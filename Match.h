#ifndef _Match_
#define _Match_
#include "Profile.h"

class Match {
    
    int numUsers;

    public:

    Match(string username);
    string FindMatch(string username);
    
};

#endif