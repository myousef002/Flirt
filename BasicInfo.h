/*
St. Olaf Dates
Carter Schafer
4/26/21
BasicInfo.h
*/

#ifndef _BASICINFO_H_
#define _BASICINFO_H_
#include<iostream>
#include<string>
using namespace std;

class BasicInfo {
    string name, pronouns, major, hometown, bio;
    string classYear, snapChat, instaGram;

public:
    BasicInfo();

    // constructor, only name and classYear are required fields, need checking later on
    BasicInfo(const string& n, const string& c, const string& bio, const string& p = "", const string& m = "", const string& h = "");

    // assuming that using C++ strings automatically takes care of deallocation, if not, add a destructor here
    
    ~BasicInfo() {}
    string &getName() {
        return name;
    }
    string &getClassYear() {
        return classYear;
    }
    string &getPronouns() {
        return pronouns;
    }
    string &getMajor() {
        return major;
    }
    string &getHometown() {
        return hometown;
    }
    string &getBio() {
        return bio;
    }

    // extracts keywords like sports, interests, etc. from the bio
    void getKeywords();

    void display();

    string &getInsta() {
        return instaGram;
    }

    string &getSnap() {
        return snapChat;
    }

};



#endif // _BASICINFO_H_