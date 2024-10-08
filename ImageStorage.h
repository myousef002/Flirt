#ifndef __ImageStorage__
#define __ImageStorage__

#include"Image.h"
#include<string>
#include<fstream>
using namespace std;

class ImageStorage {
    string* images = new string[4];
    int index = 0;
    string username;
public:
    ImageStorage();
    ImageStorage(string name);
    ~ImageStorage(){delete [] images;}
    void addImage(string name);
    string& getName(int i);
    void deleteImage(int i);
    void cropImage(string name, string un, int i);
    void filter(string name, int i, int filter);
};

#endif