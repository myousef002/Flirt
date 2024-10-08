#ifndef __Image__
#define __Image__
#include <string>
#include <iostream>
#include<fstream>

using namespace std;

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class Image {
    string name;
    int index;
    int width;
    int height;
    int depth;
    Pixel **data;
public:
    Image(string i, int id);
    Image();
    ~Image();
    int getWidth();
    int getHeight();
    void print();
    void zeroRed();
    void greyScale();
    void horizSqueeze();
    void saturation(unsigned char p);
    void vintage();
    void vignette(char factor = 76);
    void crop(int _h, int _w);
    Image& operator=(const Image& i);
};

#endif