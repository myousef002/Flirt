#include"Profile.h"
#include"react.h"

void startup() {
    _put_raw(100, "\0");
    _put_raw(150, "\0");
    _put_raw(170, "\0");
    _put_raw(175, "\0");
    _put_raw(200, "\0");
    _put_raw(325, "\0");
    _put_raw(225, "\0");
    _put_raw(240, "\0");
    _put_raw(255, "\0");
    _put_raw(260, "\0");
    _put_raw(500, "\0");
    _put_raw(530, "\0");
    _put_raw(265, "sample.png");
    _put_raw(280, "\0");
    _put_raw(295, "\0");
    _put_raw(310, "\0");
    _put_raw(6000, "Enter your username");
    _put_raw(10, "\0");
    _put_raw(9000, "Next");
    _put_raw(9070, "Meet Oles");
    _put_raw(9080, "Matches");
    _put_raw(9090, "Profile");
    add_yaml("login.yaml");
}

void startup_error() {
    _put_raw(7050, "Please enter a new or existing username");
    add_yaml("login1.yaml");
}

void basicInfo() {
    _put_raw(6000, "First name:");
    _put_raw(6020, "Pronouns:");
    _put_raw(6040, "Class year:");
    _put_raw(6060, "Major:");
    _put_raw(6080, "Hometown:");
    _put_raw(9000, "Next");

    add_yaml("BasicInfo.yaml");
}

void basicInfoError() {
    _put_raw(7050, "Please enter your first name");
    add_yaml("BasicInfo1.yaml");
}

void bio() {
    _put_raw(6100, "Make a fun bio:");
    _put_raw(9000, "Next");
    add_yaml("Bio.yaml");
}

void genderPicker() {
    _put_raw(6000, "Select your gender");
    _put_raw(7000, "--");
    _put_raw(7010, "Female");
    _put_raw(7020, "Male");
    _put_raw(7030, "Non-Binary");
    add_yaml("gender.yaml");
}

void genderPickerError() {
    _put_raw(7050, "Please select your gender");
    add_yaml("gender1.yaml");
}

void genderText() {
    _put_raw(6000, "Enter your gender");
    add_yaml("gender2.yaml");
}

void orientationPicker() {
    _put_raw(6000, "Select your sexual orientation");
    _put_raw(7000, "--");
    _put_raw(7010, "Straight");
    _put_raw(7023,"Gay");
    _put_raw(7030, "Lesbian");
    _put_raw(7040, "Bisexual");
    add_yaml("orientation.yaml");
}

void orientationError() {
    _put_raw(7050, "Please select your orientation");
    add_yaml("orientation1.yaml");
}

void orientationText() {
    _put_raw(6000, "Enter your sexual orientation");
    add_yaml("orientation2.yaml");
}

void show_seen_by() {
    _put_raw(6000, "Allow me to be seen by");
    _put_raw(6050, "Show me");
    _put_raw(7000, "Women");
    _put_raw(7010, "Men");
    _put_raw(7020, "Both");
    add_yaml("show_seen.yaml");
}

void socialMedia() {
    _put_raw(6000, "Snapchat");
    _put_raw(6050, "Instagram");
    add_yaml("social_media.yaml");
}

void socialMediaError() {
    _put_raw(7050, "Please enter at least one social media account");
    add_yaml("social_media1.yaml");
}

void imageSelection() {
    _put_raw(8000, "Select up to four images to include in your profile by typing the name of the image file, including .png. One image is required.");
    _put_raw(6000,"Image 1");
    _put_raw(6020, "Image 2");
    _put_raw(6040, "Image 3");
    _put_raw(6060, "Image 4");
    _put_raw(9000, "Next");
    add_yaml("imageSelection.yaml");
}

void confirmation() {
    _put_raw(8000,"Review Profile");
    _put_raw(9000, "Edit Info");
    _put_raw(6000, "Name");
    _put_raw(6010, "Pronouns");
    _put_raw(6020, "Class Of");
    _put_raw(6030, "Major");
    _put_raw(6040, "Hometown");
    _put_raw(2000, "\0");
    if(_get_char(225)== '1'){
        _put_raw(225, "Female");
    } else if (_get_char(225) == '2'){
        _put_raw(225, "Male");
    }
    _put_raw(6050, "Gender");
    if(_get_char(240)=='1'){
        _put_raw(240, "Straight");
    }
    if(_get_char(240)=='2'){
        _put_raw(240, "Gay");
    }
    if(_get_char(240)=='3'){
        _put_raw(240, "Lesbian");
    }
    if(_get_char(240)=='4'){
        _put_raw(240, "Bisexual");
    }
    _put_raw(6060, "Sex Or");
    if(_get_char(255) == '\0'){
        _put_raw(255, "F");
    } else if (_get_char(255) == '1'){
        _put_raw(255, "M");
    } else if (_get_char(255)=='2'){
        _put_raw(255,"B");
    }
    _put_raw(6070, "Show to");
    if(_get_char(260) == '\0'){
        _put_raw(260, "F");
    } else if (_get_char(260) == '1'){
        _put_raw(260, "M");
    } else if (_get_char(260)=='2'){
        _put_raw(260, "B");
    }
    _put_raw(6080, "Show me");
    _put_raw(6090, "Image 1");
    _put_raw(6100, "Image 2");
    _put_raw(6110, "Image 3");
    _put_raw(6120, "Image 4");
    _put_raw(6130, "Bio");
    _put_raw(6140, "Instagram");
    _put_raw(6150, "Snapchat");
    _put_raw(9030, "CREATE!");
    _put_raw(9050, "Review Profile");
    _put_raw(9070, "Meet Oles");
    _put_raw(9080, "Matches");
    _put_raw(9090, "Profile");
    add_yaml("review.yaml");
}

void find_match(Profile& profile, Profile& match, bool like) {
    string match_str;
    if (like) {
        string gm_id;
        for(int i = 1010; _get_char(i) != '\0'; i++) {
            gm_id += _get_char(i);
        }
        // cerr << "Match ID: " << match.getID() << endl;
        match_str = profile.FindMatchYes(gm_id);
    } else {
        match_str = profile.FindMatchNo();
    }
    _put_raw(1010, match_str.c_str());
    match.get_from_txt(1000);
    match.put_in_global_mem(1000);
}

void main_screen(Profile& profile, Profile& match, bool like = false) {
    find_match(profile, match, like);
    _put_raw(6000, "St. Olaf Dates");
    _put_raw(6100, "Name here");
    _put_raw(9070, "Meet Oles");
    _put_raw(9080, "Matches");
    _put_raw(9090, "Profile");
    ImageStorage image = match.getImageStorage();
    add_yaml("main_screen.yaml",{{"main",image.getName(0)}});
}


void info_screen(Profile& match) {
    string name_str = match.getBasicInfo().getName();
    _put_raw(5950, name_str.c_str());
    _put_raw(9070, "Meet Oles");
    _put_raw(9080, "Matches");
    _put_raw(9090, "Profile");
    _put_raw(6000, "Gender");
    _put_raw(6010, "Pronouns");
    _put_raw(6020, "Class Of");
    _put_raw(6030, "Major");
    _put_raw(6040, "Hometown");
    _put_raw(6130, "Bio");
    _put_raw(9030, "Done");
    add_yaml("info_screen.yaml");
}

void my_profile() {
    _put_raw(9050, "My Profile");
    _put_raw(6000, "Name");
    _put_raw(6010, "Pronouns");
    _put_raw(6020, "Class Of");
    _put_raw(6030, "Major");
    _put_raw(6040, "Hometown");
    if(_get_char(225)== '1'){
        _put_raw(225, "Female");
    } else if (_get_char(225) == '2'){
        _put_raw(225, "Male");
    }
    _put_raw(6050, "Gender");
    if(_get_char(240)=='1'){
        _put_raw(240, "Straight");
    }
    if(_get_char(240)=='2'){
        _put_raw(240, "Gay");
    }
    if(_get_char(240)=='3'){
        _put_raw(240, "Lesbian");
    }
    if(_get_char(240)=='4'){
        _put_raw(240, "Bisexual");
    }
    _put_raw(6060, "Sex Or");
    if(_get_char(255) == '\0'){
        _put_raw(255, "F");
    } else if (_get_char(255) == '1'){
        _put_raw(255, "M");
    } else if (_get_char(255)=='2'){
        _put_raw(255,"B");
    }
    _put_raw(6070, "Show to");
    if(_get_char(260) == '\0'){
        _put_raw(260, "F");
    } else if (_get_char(260) == '1'){
        _put_raw(260, "M");
    } else if (_get_char(260)=='2'){
        _put_raw(260, "B");
    }
    _put_raw(6080, "Show me");
    _put_raw(6090, "Image 1");
    _put_raw(6100, "Image 2");
    _put_raw(6110, "Image 3");
    _put_raw(6120, "Image 4");
    _put_raw(6130, "Bio");
    _put_raw(6140, "Instagram");
    _put_raw(6150, "Snapchat");
    _put_raw(9000, "Edit Images");
    _put_raw(9030, "Edit Info");
    _put_raw(9070, "Meet Oles");
    _put_raw(9080, "Matches");
    _put_raw(9090, "Profile");
    add_yaml("my_profile.yaml");
}

void matches(Profile &profile) {
    profile.get_from_txt();
    profile.put_in_global_mem();
    string userMatches;
    for(int i = 2000; _get_char(i) != '\0'; i++){
        userMatches += _get_char(i);
    }
    int match = 300;
    int index = 0;
    int matchList[5] = {};
    stringstream ss(userMatches);
    while( ss.good() && index < 5){
        string substr;
        getline(ss, substr, ',');
        if(substr[0] == '*'){
            _put_raw(match,substr.c_str());
            matchList[index] = match;
            match += substr.length() + 1;
            _put_raw(match - 1, "\0");
            index++;
        }
    }
    
    add_yaml("matches.yaml",{{"1",matchList[0]},{"2",matchList[1]},{"3",matchList[2]},{"4",matchList[3]},{"5",matchList[4]}});
}

bool checkProfile() {
    string un;
    for(int i = 0; _global_mem[10+i]; i++){
        un += _global_mem[10+i];
    }
    ifstream file(un+".txt");
    if(file) {
        return true;
    }
    return false;
}

void response(Profile& profile, Profile& match) {
    if(_event_id_is("login")) {
        bool profileCheck = checkProfile();
        if (_get_char(10) == '\0'){
            startup_error();
        } else if(profileCheck) { // if profile exists
            profile.get_from_txt(); // reads in existing information from profile txt file
            profile.put_in_global_mem(); // puts the profile in global mem
            // find_match(profile, match);
            main_screen(profile, match); // goes to main screen of app
        } else { // no profile with that username exists, heads to profile creation

            string str;
            for(int i = 10; _get_char(i) != '\0'; i++) {
                str += _get_char(i);
            }
            ofstream users_file;
            users_file.open("users.txt", std::ios_base::app); // append username to file users.txt
            users_file << "\n" << str;
            users_file.close();
            basicInfo();
        }
    }
    if(_event_id_is("basicInfo")) {
        if (_get_char(100) == '\0'){
            basicInfoError();
        } else {
            bio();
        }
    }
    if(_event_id_is("binfo")) {add_yaml("BasicInfo.yaml");}
    if(_event_id_is("bio")){
        genderPicker();
    }
    if(_event_id_is("genderPicker")){add_yaml("gender.yaml");} 
    if(_event_id_is("genderb")) {
        if(_get_char(225) == '\0'){
            genderPickerError();
        } else {
            orientationPicker();
        }
    }
    if(_event_id_is("orientation")){add_yaml("orientation.yaml");} 
    if (_event_id_is("orientationb")){
        if(_get_char(240)== '\0'){
            orientationError();
        }
        show_seen_by(); 
    }
    if(_event_id_is("orientationText")){
        show_seen_by();
    }
    if(_event_id_is("seen")){add_yaml("show_seen.yaml");}
    if(_event_id_is("show")){add_yaml("show_seen.yaml");}
    if(_event_id_is("showseen")){
        socialMedia();
        }
    if(_event_id_is("socialmedia")){
        if(_get_char(500) == '\0' && _get_char(530) == '\0'){
            socialMediaError();
        } else {
            imageSelection();
        }
    }
    if(_event_id_is("imageSelection")){
        confirmation();
    }
    if(_event_id_is("checkProfile")){
        basicInfo();
    }
    if(_event_id_is("to_main_screen")){
        if(_get_char(150) == '\0'){
            _put_raw(150,"0");
        }
        if(_get_char(170) == '\0'){
            _put_raw(170,"0");
        }
        if(_get_char(175) == '\0'){
            _put_raw(175,"0");
        }
        if(_get_char(200) == '\0'){
            _put_raw(200,"0");
        }
        if(_get_char(225) == '\0'){
            _put_raw(225,"0");
        }
        if(_get_char(240) == '\0'){
            _put_raw(240,"0");
        }
        if(_get_char(255) == '\0'){
            _put_raw(255,"0");
        }
        if(_get_char(260) == '\0'){
            _put_raw(260,"0");
        }
        if(_get_char(280) == '\0'){
            _put_raw(280,"0");
        }
        if(_get_char(295) == '\0'){
            _put_raw(295,"0");
        }
        if(_get_char(310) == '\0'){
            _put_raw(310,"0");
        }
        if(_get_char(325) == '\0'){
            _put_raw(325,"0");
        }
        if(_get_char(500) == '\0'){
            _put_raw(500,"0");
        }
        if(_get_char(530) == '\0'){
            _put_raw(530,"0");
        }
        
        profile.get_from_global_mem();
        profile.put_in_txt();

        main_screen(profile, match);
    }
    if(_event_id_is("info")) {
        info_screen(match);
    }
    if(_event_id_is("myprofile")){
        my_profile();
    }
    if(_event_id_is("like")){ // gets called when the user clicks the green check
        profile.get_from_txt();
        profile.put_in_global_mem();

        if(_get_char(150) == '\0'){
            _put_raw(150,"0");
        }
        if(_get_char(170) == '\0'){
            _put_raw(170,"0");
        }
        if(_get_char(175) == '\0'){
            _put_raw(175,"0");
        }
        if(_get_char(200) == '\0'){
            _put_raw(200,"0");
        }
        if(_get_char(225) == '\0'){
            _put_raw(225,"0");
        }
        if(_get_char(240) == '\0'){
            _put_raw(240,"0");
        }
        if(_get_char(255) == '\0'){
            _put_raw(255,"0");
        }
        if(_get_char(260) == '\0'){
            _put_raw(260,"0");
        }
        if(_get_char(280) == '\0'){
            _put_raw(280,"0");
        }
        if(_get_char(295) == '\0'){
            _put_raw(295,"0");
        }
        if(_get_char(310) == '\0'){
            _put_raw(310,"0");
        }
        if(_get_char(325) == '\0'){
            _put_raw(325,"0");
        }
        if(_get_char(500) == '\0'){
            _put_raw(500,"0");
        }
        if(_get_char(530) == '\0'){
            _put_raw(530,"0");
        }
        
        profile.get_from_global_mem();
        profile.put_in_txt();

        main_screen(profile, match, true);
    }
    if(_event_id_is("matches")){
        matches(profile);
    }
    
}

int main() {
    _init();
    Profile user;
    Profile match;
    if(_just_starting()) { // login screen where username is entered
        startup();
    } else if (_received_event()) { // handles button presses etc
        response(user,match);
    }
    _quit();
}