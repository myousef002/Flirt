/*
St. Olaf Dates
Carter Schafer
4/27/21
BasicInfoDriver.cpp
*/

#include "BasicInfo.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
    BasicInfo b("Carter", "2024", "First year ultimate player, musician, and photographer.", "he/him", "CS");
    // cerr << b.getName() << endl;
    b.display();
}