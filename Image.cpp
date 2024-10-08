#include"Image.h"

    Image::Image(string i, int id) {
        index = id;
        std::ifstream f(i);
        f >> name;
        f >> width >> height;
        data = new Pixel*[height];
        for(int i = 0; i<height; ++i) {
            data[i] = new Pixel[width];
        }
        f >> depth;
        f.get();
        for(int i = 0; i<height; ++i) {
            f.read(reinterpret_cast<char *>(data[i]),width*3);
        }
        f.close();
    }
    Image::Image() {
        name = " ";
        index = depth = 0;
        height = width = 1;
        data = new Pixel*[height];
        for(int i = 0; i<height; ++i){
            data[i] = new Pixel[width];
        }
    }
    Image::~Image() {
        for(int i = 0; i < height; ++i) {
            delete [] data[i];
        }
        delete [] data;
    }
    int Image::getWidth() {
        return width;
    }
    int Image::getHeight() {
        return height;
    }
    void Image::print() {
        std::ofstream f;
        string index_s = to_string(index);
        f.open(name+".ppm");
        f << name << std::endl;
        f << width << " " << height << std::endl;
        f << depth << std::endl;
        for(int i = 0; i < height; ++i){
            f.write(reinterpret_cast<char *>(data[i]),width*3);
        }
        f.close();
    }

    void Image::zeroRed() {
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                data[i][j].red = 0;
            }
        }
    }

    void Image::greyScale() {
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                int average = (data[i][j].red + data[i][j].green + data[i][j].blue)/3;
                data[i][j].red = data[i][j].green = data[i][j].blue = average;
            }
        }
    }

    void Image::horizSqueeze() {
        width /= 2;
        Pixel** tmp = data;
        data = new Pixel*[height];
        for(int i = 0; i < height; ++i) {
            data[i] = new Pixel[width];
        }
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                data[i][j] = tmp[i][j*2];
            }
        }
        for(int i = 0; i < height; ++i) {
            delete [] tmp[i];
        }
        delete [] tmp;
}

void Image::saturation(unsigned char i) {
    i /= 100;
    for(int h = 0; h<height; ++h){
        for(int j = 0; j<width; ++j){
            unsigned char pRed = data[h][j].red * i;
            unsigned char pGreen = data[h][i].green * i;
            unsigned char pBlue = data[h][i].blue * i;
            data[h][i].red -= pRed;
            data[h][i].green -= pGreen;
            data[h][i].blue -= pBlue;
        }
    }
}

void Image::vintage() {
    Image::saturation(30);
}

void Image::vignette(char factor) {
    int quarterH = height/4;
    int quarterW = width/4;
    for(int i = 0; i<quarterH; i++) {
        for(int j =0; j<quarterW; j++) {
            char scale =  (1/2)*factor*(i/quarterH) + (1/2)*factor*(j/quarterW);
            if(data[i][j].red + scale > 255) {
                data[i][j].red = 255;
            } else {
                data[i][j].red += scale;
            }
            if(data[i][j].green + scale > 255) {
                data[i][j].green = 255;
            } else {
                data[i][j].green += scale;
            }
            if(data[i][j].blue + scale > 255) {
                data[i][j].blue = 255;
            } else {
                data[i][j].blue += scale;
            }
        }
    }
    for(int i = 3*quarterH; i<height; i++){
        for(int j = 0; j<quarterW; j++){
            char scale =  (1/2)*factor*((height-i)/quarterH) + (1/2)*factor*(j/quarterW);
            if(data[i][j].red + scale > 255) {
                data[i][j].red = 255;
            } else {
                data[i][j].red += scale;
            }
            if(data[i][j].green + scale > 255) {
                data[i][j].green = 255;
            } else {
                data[i][j].green += scale;
            }
            if(data[i][j].blue + scale > 255) {
                data[i][j].blue = 255;
            } else {
                data[i][j].blue += scale;
            }
        }
    } 
    for(int i = 3*quarterH; i<height; i++){
        for(int j = 3*quarterW; j<width; j++){
            char scale =  (1/2)*factor*((height-i)/quarterH) + (1/2)*factor*((width-j)/quarterW);
            if(data[i][j].red + scale > 255) {
                data[i][j].red = 255;
            } else {
                data[i][j].red += scale;
            }
            if(data[i][j].green + scale > 255) {
                data[i][j].green = 255;
            } else {
                data[i][j].green += scale;
            }
            if(data[i][j].blue + scale > 255) {
                data[i][j].blue = 255;
            } else {
                data[i][j].blue += scale;
            }
        }
    }
    for(int i = 0; i<quarterH; i++){
        for(int j = 3*quarterW; j<width; j++){
            char scale =  (1/2)*factor*(i/quarterH) + (1/2)*factor*((width-j)/quarterW);
            if(data[i][j].red + scale > 255) {
                data[i][j].red = 255;
            } else {
                data[i][j].red += scale;
            }
            if(data[i][j].green + scale > 255) {
                data[i][j].green = 255;
            } else {
                data[i][j].green += scale;
            }
            if(data[i][j].blue + scale > 255) {
                data[i][j].blue = 255;
            } else {
                data[i][j].blue += scale;
            }
        }
    }   
}
void Image::crop(int _h, int _w) {
    if(_h>height || _w>width){
        cerr << "Invalid dimensions: Crop dimensions greater than photo dimensions" << endl;
        return;
    }

    Pixel** tmp = data;
    data = new Pixel*[_h];
    for(int i = 0; i<_h; i++){
        data[i] = new Pixel[_w];
    }
    int marginH = (height - _h) / 2;
    int marginW = (width - _w) / 2;
    for(int i = 0; i<_h; i++){
        for(int j = 0; j<_w; j++){
            data[i][j] = tmp[i+marginH][j+marginW];
        }
    }

    for(int i = 0; i < height; ++i) {
            delete [] tmp[i];
    }
    delete [] tmp;

    height = _h;
    width = _w;
}

Image& Image::operator=(const Image& i){
    name = i.name;
    index = i.index;
    width = i.width;
    height = i.height;
    depth = i.depth;
    data = new Pixel*[height];
    for(int i = 0; i<height; i++){
        data[i] = new Pixel[width];
    }
    for(int h = 0; h<height; h++){
        for(int j = 0; j<width; j++){
            data[h][j] = i.data[h][j];
        }
    }
    return *this;
}