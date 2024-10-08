/*
St. Olaf Dates
Carter Schafer
5/2/21
Profile.cpp
*/

#include "Profile.h"

Profile::Profile() { }

Profile::Profile(string username){
    ifstream file(username + ".txt");
    ifstream userfile("users.txt");

    if(file) {
        getline(file,id);
        getline(file,bInfo.getName());
        getline(file,bInfo.getPronouns());
        getline(file,bInfo.getClassYear());
        getline(file,bInfo.getMajor());
        getline(file,bInfo.getHometown());

        //file.get(); // goes from hometown to gender line
        getline(file,genderOr.getGender());
        getline(file,genderOr.getOrientation());
        getline(file,genderOr.getShow());
        getline(file,genderOr.getseenBy());

        getline(file,userImages.getName(0)); // image1
        getline(file,userImages.getName(1)); // image2
        getline(file,userImages.getName(2)); // image3
        getline(file,userImages.getName(3)); // image4

        getline(file,bInfo.getBio());

        getline(file,bInfo.getInsta());
        getline(file,bInfo.getSnap());
        getline(file,matches);

        file.close();
    } 
}

genderOrientation &Profile::getGenderObject(){
    return genderOr;
}

string &Profile::getID(){
    return id;
}

BasicInfo &Profile::getBasicInfo(){
    return bInfo;
}

ImageStorage &Profile::getImageStorage(){
    return userImages;
}

void Profile::store_possible_match(string username, string randUsername){
    ofstream input_f;
    input_f.open(username + ".txt", std::ios_base::app); 

    string possible_matches = randUsername + ',';
    matches += randUsername + ',';
    input_f << possible_matches;
    input_f.close();
}

void Profile::store_match(string username, string randUsername){
    ofstream input_f;
    input_f.open(username + ".txt", std::ios_base::app); 

    string possible_matches = '*' + randUsername + ',';
    matches += randUsername + ',';
    input_f << possible_matches;
    input_f.close();
}

bool Profile::check_Match(string username, string randUsername){
    ifstream output_randUser;
    output_randUser.open(randUsername + ".txt");

    string match_list_randUser;
    for(int i = 0; i < 18; ++i){ getline(output_randUser, match_list_randUser); }
    
    stringstream ss(match_list_randUser);
    while( ss.good() ){
        string substr;
        getline(ss, substr, ',');
        // cerr << substr << endl;
        // cerr << username << endl;
        if(substr == username){
            return true;
        }
    }
    return false;
}

string Profile::FindMatchYes(string matched_username){
    store_possible_match(id, matched_username);
    if(check_Match(id, matched_username)){
        store_match(id, matched_username);
        store_match(matched_username, id);
    }

    srand (time(NULL));
    ifstream userfile("users.txt");

    string y;
    int numUsers;
    while (userfile >> y){
        ++numUsers;
    }

    userfile.close();

    while (true) {
        ifstream userfile2("users.txt");
        int randomNum = rand() % numUsers;

        string x;
        for(int i = 0; i < randomNum; ++i){ getline(userfile2,x); }
        userfile2 >> x;
        userfile2.close();

        ifstream randUser(x + ".txt");
        string randUserGender;
        string randUserSexuality;
        string randUserSeenBy;
        for(int i = 0; i < 7; ++i){ randUser >> randUserGender; }
        for(int i = 0; i < 1; ++i){ randUser >> randUserSexuality; }
        for(int i = 0; i < 1; ++i){ randUser >> randUserSeenBy; }
        randUser.close();
         
        
        if (genderOr.getOrientation() == "Straight" && randUserSexuality == "Straight"){
            if((genderOr.getShow() == "F" && randUserSeenBy == "M") || (genderOr.getShow() == "M" && randUserSeenBy == "F")){
                return x;
            }
        } else if ((genderOr.getOrientation() == "Gay" && randUserSexuality == "Gay") || (genderOr.getOrientation() == "Lesbian" && randUserSexuality == "Lesbian")){
            if((genderOr.getShow() == "F" && randUserSeenBy == "F") || (genderOr.getShow() == "M" && randUserSeenBy == "M")){
                return x;
            }
        } else if (genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Straight"){
            if ((genderOr.getGender() == "Male" && randUserGender == "Female") || (genderOr.getGender() == "Female" && randUserGender == "Male")){
                return x;
            }
        } else if ((genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Gay") || (genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Lesbian")){
            if ((genderOr.getGender() == "Male" && randUserGender == "Male") || (genderOr.getGender() == "Female" && randUserGender == "Female")){
                return x;
            }
        } else if (genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Bisexual"){
            return x;
        } 
    } 
}

string Profile::FindMatchNo(){
    srand (time(NULL));
    ifstream userfile("users.txt");

    string y;
    int numUsers;
    while (userfile >> y){
        ++numUsers;
    }

    userfile.close();

    while (true) {
        ifstream userfile2("users.txt");
        int randomNum = rand() % numUsers;

        string x;
        for(int i = 0; i < randomNum; ++i){ getline(userfile2,x); }
        userfile2 >> x;
        userfile2.close();

        ifstream randUser(x + ".txt");
        string randUserGender;
        string randUserSexuality;
        string randUserSeenBy;
        for(int i = 0; i < 7; ++i){ randUser >> randUserGender; }
        for(int i = 0; i < 1; ++i){ randUser >> randUserSexuality; }
        for(int i = 0; i < 1; ++i){ randUser >> randUserSeenBy; }
        randUser.close();
         
        
        if (genderOr.getOrientation() == "Straight" && randUserSexuality == "Straight"){
            if((genderOr.getShow() == "F" && randUserSeenBy == "M") || (genderOr.getShow() == "M" && randUserSeenBy == "F")){
                return x;
            }
        } else if ((genderOr.getOrientation() == "Gay" && randUserSexuality == "Gay") || (genderOr.getOrientation() == "Lesbian" && randUserSexuality == "Lesbian")){
            if((genderOr.getShow() == "F" && randUserSeenBy == "F") || (genderOr.getShow() == "M" && randUserSeenBy == "M")){
                return x;
            }
        } else if (genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Straight"){
            if ((genderOr.getGender() == "Male" && randUserGender == "Female") || (genderOr.getGender() == "Female" && randUserGender == "Male")){
                return x;
            }
        } else if ((genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Gay") || (genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Lesbian")){
            if ((genderOr.getGender() == "Male" && randUserGender == "Male") || (genderOr.getGender() == "Female" && randUserGender == "Female")){
                return x;
            }
        } else if (genderOr.getOrientation() == "Bisexual" && randUserSexuality == "Bisexual"){
            return x;
        } 
    } 
}

void Profile::put_in_global_mem(int offset) {
    _put_raw(10 + offset,id.c_str());
    _put_raw(100 + offset,bInfo.getName().c_str());
    _put_raw(150 + offset,bInfo.getPronouns().c_str());
    _put_raw(170 + offset,bInfo.getClassYear().c_str());
    _put_raw(175 + offset,bInfo.getMajor().c_str());
    _put_raw(200 + offset,bInfo.getHometown().c_str());
    _put_raw(225 + offset,genderOr.getGender().c_str());
    _put_raw(240 + offset,genderOr.getOrientation().c_str());
    _put_raw(255 + offset,genderOr.getShow().c_str());
    _put_raw(260 + offset,genderOr.getseenBy().c_str());
    _put_raw(265 + offset,userImages.getName(0).c_str());
    _put_raw(280 + offset,userImages.getName(1).c_str());
    _put_raw(295 + offset,userImages.getName(2).c_str());
    _put_raw(310 + offset,userImages.getName(3).c_str());
    _put_raw(325 + offset,bInfo.getBio().c_str());
    _put_raw(500 + offset,bInfo.getInsta().c_str());
    _put_raw(530 + offset,bInfo.getSnap().c_str());
    _put_raw(2000 + offset, matches.c_str());
}

void Profile::get_from_global_mem() {
    string gm_id;
    for(int i = 10; _get_char(i) != '\0'; i++) {
        gm_id += _get_char(i);
    }
    id = gm_id;

    string gm_getName;
    for(int i = 100; _get_char(i) != '\0'; i++) {
        gm_getName += _get_char(i);
    }
    bInfo.getName() = gm_getName;

    string gm_getPronouns;
    for(int i = 150; _get_char(i) != '\0'; i++) {
        gm_getPronouns += _get_char(i);
    }
    bInfo.getPronouns() = gm_getPronouns;

    string gm_getClassYear;
    for(int i = 170; _get_char(i) != '\0'; i++) {
        gm_getClassYear += _get_char(i);
    }
    bInfo.getClassYear() = gm_getClassYear;

    string gm_getMajor;
    for(int i = 175; _get_char(i) != '\0'; i++) {
        gm_getMajor += _get_char(i);
    }
    bInfo.getMajor() = gm_getMajor;

    string gm_getHometown;
    for(int i = 200; _get_char(i) != '\0'; i++) {
        gm_getHometown += _get_char(i);
    }
    bInfo.getHometown() = gm_getHometown;

    string gm_getGender;
    for(int i = 225; _get_char(i) != '\0'; i++) {
        gm_getGender += _get_char(i);
    }
    genderOr.getGender() = gm_getGender;

    string gm_getOrientation;
    for(int i = 240; _get_char(i) != '\0'; i++) {
        gm_getOrientation += _get_char(i);
    }
    genderOr.getOrientation() = gm_getOrientation;

    string gm_getShow;
    for(int i = 255; _get_char(i) != '\0'; i++) {
        gm_getShow += _get_char(i);
    }
    genderOr.getShow() = gm_getShow;

    string gm_getseenBy;
    for(int i = 260; _get_char(i) != '\0'; i++) {
        gm_getseenBy += _get_char(i);
    }
    genderOr.getseenBy() = gm_getseenBy;

    string gm_getImage1;
    for(int i = 265; _get_char(i) != '\0'; i++) {
        gm_getImage1 += _get_char(i);
    }
    userImages.getName(0) = gm_getImage1;

    string gm_getImage2;
    for(int i = 280; _get_char(i) != '\0'; i++) {
        gm_getImage2 += _get_char(i);
    }
    userImages.getName(1) = gm_getImage2;

    string gm_getImage3;
    for(int i = 295; _get_char(i) != '\0'; i++) {
        gm_getImage3 += _get_char(i);
    }
    userImages.getName(2) = gm_getImage3;

    string gm_getImage4;
    for(int i = 310; _get_char(i) != '\0'; i++) {
        gm_getImage4 += _get_char(i);
    }
    userImages.getName(3) = gm_getImage4;

    string gm_getBio;
    for(int i = 325; _get_char(i) != '\0'; i++) {
        gm_getBio += _get_char(i);
    }
    bInfo.getBio() = gm_getBio;

    string gm_getInsta;
    for(int i = 500; _get_char(i) != '\0'; i++) {
        gm_getInsta += _get_char(i);
    }
    bInfo.getInsta() = gm_getInsta;

    string gm_getSnap;
    for(int i = 530; _get_char(i) != '\0'; i++) {
        gm_getSnap += _get_char(i);
    }
    bInfo.getSnap() = gm_getSnap;

    string gm_getMatches;
    for(int i = 2000; _get_char(i) != '\0'; i++) {
        gm_getMatches += _get_char(i);
    }
    matches = gm_getMatches;
}

void Profile::put_in_txt() {
    ofstream new_file(id+".txt");

    new_file << id << "\n";

    new_file << bInfo.getName() << "\n";
    new_file << bInfo.getPronouns() << "\n";
    new_file << bInfo.getClassYear() << "\n";
    new_file << bInfo.getMajor() << "\n";
    new_file << bInfo.getHometown() << "\n";

    new_file << genderOr.getGender() << "\n";
    new_file << genderOr.getOrientation() << "\n";
    new_file << genderOr.getShow() << "\n";
    new_file << genderOr.getseenBy() << "\n"; 
    
    new_file << userImages.getName(0) << '\n';
    new_file << userImages.getName(1) << '\n';
    new_file << userImages.getName(2) << '\n';
    new_file << userImages.getName(3) << '\n';

    new_file << bInfo.getBio() << "\n";
    new_file << bInfo.getInsta() << "\n";
    new_file << bInfo.getSnap() << "\n";
    new_file << matches;

    new_file.close();
}

void Profile::get_from_txt(int offset) {
    string gm_id;
    for(int i = 10 + offset; _get_char(i) != '\0'; i++) {
        gm_id += _get_char(i);
    }
    id = gm_id;
    ifstream file(id + ".txt");
    if(file) {
        file.ignore(20, '\n');
        getline(file,bInfo.getName());
        getline(file,bInfo.getPronouns());
        getline(file,bInfo.getClassYear());
        getline(file,bInfo.getMajor());
        getline(file,bInfo.getHometown());

        //file.get(); // goes from hometown to gender line
        getline(file,genderOr.getGender());
        getline(file,genderOr.getOrientation());
        getline(file,genderOr.getShow());
        getline(file,genderOr.getseenBy());

        getline(file,userImages.getName(0)); // image1
        getline(file,userImages.getName(1)); // image2
        getline(file,userImages.getName(2)); // image3
        getline(file,userImages.getName(3)); // image4

        getline(file,bInfo.getBio());

        getline(file,bInfo.getInsta());
        getline(file,bInfo.getSnap());

        getline(file,matches);

        file.close();
    }
}