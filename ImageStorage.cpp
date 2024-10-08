#include"ImageStorage.h"

ImageStorage::ImageStorage() {
    index = 0;
    for(int i = 0; i<4; i++){
        images[i] = "0\n";
    }
}

ImageStorage::ImageStorage(string name){
    for(int i = 0; i<4; i++){
        images[i] = "0\n";
    }
    Image myImage(name,index);
    myImage.print();
    string index_s = to_string(index);
    images[index] = name+".ppm";
}

void ImageStorage::addImage(string name){
    if(index > 3){
        cerr << "Max number of photos has been uploaded. Replace or delete an existing photo." << endl;
        return;
    }
    if(name == "0\n"){
        return;
    }
    if(images[0] == "0\n"){
        index = 0;
    } else if (images[1] == "0\n") {
        index = 1;
    } else if (images[2] == "0\n"){
        index = 2;
    } else if (images[3] == "0\n") {
        index = 3;
    } else {
        return;
    }
    Image myImage(name,index);
    myImage.print();
    string index_s = to_string(index);
    images[index] = name+".ppm";
    index += 1;
}

void ImageStorage::deleteImage(int i) {
    images[i] = "0\n";
}

string& ImageStorage::getName(int i){
    return images[i];
}

void ImageStorage::cropImage(string name, string un, int i){
    if(images[i] == "0"){
        return;
    }
    Image img(name,i);
    int h, w;
    cerr << "Enter the new height of the image: ";
    cin >> h;
    cerr << "Enter the new width of the image: ";
    cin >> w;
    img.crop(h,w);
    img.print();
}

void ImageStorage::filter(string name, int i, int filter) {
    if(images[i] == "0"){
        return;
    }
    Image img(name,i);
    if (filter == 0){
        img.zeroRed();
    } else if (filter == 1){
        img.greyScale();
    } else if (filter == 2){
        cerr << "Saturation: ";
        unsigned char saturation;
        cin >> saturation;
        img.saturation(saturation);
    } else if (filter == 3){
        img.vintage();
    } else if (filter == 4){
        img.vignette();
    } else {
        cerr << "No filters applied, invalid filter int entered" << endl;
    }
    img.print();
}
