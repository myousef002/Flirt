#include "Match.h"

Match::Match(string username){
    Profile user(username + ".txt");
    
    ifstream userfile("users.txt");
    string x;
    while (userfile >> x){
        ++numUsers;
    }

    userfile.close();
}

string Match::FindMatch(string username){
    Profile user(username + ".txt");
    ifstream userfile("users.txt");

    while (true) {
        srand(time(NULL));
        int randomNum = rand() % numUsers;

        string x;
        for(int i = 0; i < randomNum; ++i){ userfile >> x; }
        userfile >> x;

        Profile randUser(x + ".txt");
        if(user.getGenderObject().getShow() == randUser.getGenderObject().getseenBy()){
            cout << user.getGenderObject().getShow() << " " << randUser.getGenderObject().getseenBy() << endl;
            cout << x << endl;
            return x;
        }
    }
}

int main(){
    Match mike("yousef2");
    mike.FindMatch("yousef2");
}