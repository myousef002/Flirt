/*
St. Olaf Dates
Carter Schafer
4/27/21
BasicInfo.cpp
*/

#include "BasicInfo.h"
#include<iostream>
#include<string>
using namespace std;

// CONSTRUCTORS

BasicInfo::BasicInfo() {
    name = "";
    classYear = "";
    pronouns = "";
    major = "";
    hometown = "";
    bio = "";
    instaGram = "";
    snapChat = "";
}

// pronouns, major, and hometown are given default values in BasicInfo.h
BasicInfo::BasicInfo(const string& n, const string& c, const string& b, const string& p, const string& m, const string& h) {
    name = n;
    classYear = c;
    pronouns = p;
    major = m;
    hometown = h;
    bio = b;
}

// METHODS

void BasicInfo::getKeywords() {
    cerr << "getKeywords called" << endl;
}

void BasicInfo::display() {
    cerr << name << endl;
    cerr << classYear << endl;
    if (pronouns != "") {
        cerr << pronouns << endl;
    }
    if (major != "") {
        cerr << major << endl;
    }
    if (hometown != "") {
        cerr << hometown << endl;
    }
    
}

