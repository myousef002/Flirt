/*
St. Olaf Dates
Carter Schafer
5/2/21
ProfileDriver.cpp
*/

#include "Profile.h"

int main() {
    cerr << "ProfileDriver::main called" << endl;
    Profile yousef2("yousef2");
    cerr << endl;
    
    cout << yousef2.FindMatchYes("profile1") << endl;
}
