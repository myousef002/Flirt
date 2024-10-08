#include"ImageStorage.h"

int main() {
    ImageStorage myImages("ander6.ppm");
    myImages.addImage("ander6-0.ppm");
    cerr << myImages.getName(0) << endl;
    cerr << myImages.getName(1) << endl;
}