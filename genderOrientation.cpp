#include "genderOrientation.h"

genderOrientation::genderOrientation(){
    gender = "";
    show = "";
    seenBy = "";
    orientation = "";
}

genderOrientation::genderOrientation(string g, string s1, string s2, string o){
    gender = g;
    show = s1;
    seenBy = s2;
    orientation = o;
}

string &genderOrientation::getGender(){
    return gender;
}

string &genderOrientation::getShow(){
    return show;
}

string &genderOrientation::getseenBy(){
    return seenBy;
}

string &genderOrientation::getOrientation(){
    return orientation;
}