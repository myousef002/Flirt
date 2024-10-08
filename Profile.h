/*
St. Olaf Dates
Carter Schafer
4/30/21
Profile.h
*/

#ifndef _PROFILE_H_
#define _PROFILE_H_
#include "BasicInfo.h"
#include "ImageStorage.h"
#include "Image.h"
#include "genderOrientation.h"
#include "react.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

class Profile {
    string id;
    BasicInfo bInfo;
    genderOrientation genderOr;
    ImageStorage userImages;
    string matches;
    
public:
    Profile(); // use default constructor for testing
    Profile(string username);
    string &getID();
    BasicInfo &getBasicInfo();
    genderOrientation &getGenderObject();
    ImageStorage &getImageStorage();
    void store_possible_match(string username, string randUsername);
    void store_match(string username, string randUsername);
    bool check_Match(string username, string randUsername);
    string FindMatchYes(string matched_username);
    string FindMatchNo();
    void put_in_global_mem(int offset = 0);
    void get_from_global_mem();
    void put_in_txt();
    void get_from_txt(int offset = 0);
};



#endif // _PROFILE_H_