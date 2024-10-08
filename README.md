# St. Olaf Dates


CBM Technologies
Michael Yousef, Carter Schafer, Ben Anderson
St. Olaf Dates

HOW TO USE:
-- To compile all the necessary files: "make"
-- To compile the server that connects with bridge.py: "make server"
** It is also important to note that bridge.py was developed to work with the St. Olaf CS Network so will not work on other networks.
-- Get rid of all .o files and relink react.o to the directory: "make clean"
** It is important that react.o is stored in the directory. If it is not linked, use "make clean" to link it.

ADDITIONAL INFORMATION:
-- All screens are described in the "St Olaf Dates User Manual.pdf"
-- For a match to show up in your matches tab (that is not simply your username with some ~ characters), both users need to tap the green check mark. Ideally, an extension of this page would include either displaying their snapchat or instagram information or even creating chat functionality. 
-- It is important only one person is adding new users at a time as the users.txt file needs to update properly, unless you want to deal with a merge conflict (although it is a pretty simple fix as long as every users' username is included). Also, for each user, a txt file named username.txt needs to be in this directory as well.
-- There is an ImageStorage class as well as a modified Image class (from lab 5). These were not incorporated into the demo with a user interface; however, the general idea was that a user could store up to four images as a part of their profile. While the ImageStorage functionality works (a user can type the names of four pngs in the profile creation process), there was never an implementation of some of the edit methods. In the Image class, there are additional methods that allow for some simple photo editing, such as adding a vignette or changing the saturation. The idea was that eventually when uploading images for a profile a user could choose to apply those methods to their uploaded photos. There are also some unused react files with basic beginnings for this concept (editImages.yaml for instance). Also, ideally the profile information screens would show all the images the user uploaded--as of right now they display the name of the photo and the only time their first photo is shown is when another user sees their profile on the main screen and chooses whether to match or reject them. Also, during the profile creation the name of the photo(s) selected for the account need to be in this repository to correctly upload.
-- On the main screen, for somewhat bizzare reasons, the react output does not always show "Main Screen," "Matches," and "Profile" as the bottom three tabs despite the correct indices in global memory storing those characters. If they are not displayed, the order of the three tabs is the same as listed in this item, from left to right.
