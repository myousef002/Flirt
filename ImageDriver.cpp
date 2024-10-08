#include"Image.h"

int main() {
    Image myimg("test2.ppm",0);
    myimg.crop(4,5);
    myimg.print();
}