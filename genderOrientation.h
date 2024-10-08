#ifndef _Messages_
#define _Messages_
#include<iostream>
#include<string>
using namespace std;

class genderOrientation {
    string gender; 
    string show; //Men or Women
    string seenBy; //Men or Women
    string orientation;

    public:
    genderOrientation();
    genderOrientation(string g, string s1, string s2, string o);
    ~genderOrientation() {}
    string &getGender();
    string &getShow();
    string &getseenBy();
    string &getOrientation();
};

#endif