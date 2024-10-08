all: ImageDriver ImageStorageDriver BasicInfoDriver genderOrientation.o Profile.o ProfileDriver.o ProfileDriver
clean: 
	rm *.o; ln -s /usr/local/cs/cs251/react.o .

ImageDriver.o: ImageDriver.cpp
	g++ -Wall -c ImageDriver.cpp
Image.o: Image.h Image.cpp
	g++ -Wall -c Image.cpp
ImageDriver: Image.o ImageDriver.o
	g++ -Wall -o ImageDriver Image.o ImageDriver.o

ImageStorageDriver.o: ImageStorageDriver.cpp
	g++ -Wall -c ImageStorageDriver.cpp
ImageStorage.o: ImageStorage.cpp ImageStorage.h
	g++ -Wall -c ImageStorage.cpp
ImageStorageDriver: ImageStorageDriver.o ImageStorage.o
	g++ -Wall -o ImageStorageDriver ImageStorageDriver.o ImageStorage.o Image.o

BasicInfo.o: BasicInfo.cpp BasicInfo.h
	g++ -Wall -c BasicInfo.cpp
BasicInfoDriver.o: BasicInfoDriver.cpp
	g++ -Wall -c BasicInfoDriver.cpp
BasicInfoDriver: BasicInfoDriver.o BasicInfo.o
	g++ -Wall -o BasicInfoDriver BasicInfoDriver.o BasicInfo.o

genderOrientation.o: genderOrientation.cpp genderOrientation.h
	g++ -Wall -c genderOrientation.cpp

Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp
ProfileDriver.o: ProfileDriver.cpp
	g++ -Wall -c ProfileDriver.cpp
ProfileDriver: Profile.o ProfileDriver.o
	g++ -Wall -o ProfileDriver ProfileDriver.o Profile.o BasicInfo.o genderOrientation.o ImageStorage.o Image.o react.o -lcurl

Match.o: Match.h Match.cpp
	g++ -Wall -c Match.cpp
Match: Match.o
	g++ -Wall -o Match Match.o Profile.o BasicInfo.o genderOrientation.o ImageStorage.o Image.o

server:
	g++ -Wall server.cpp Profile.o BasicInfo.o genderOrientation.o ImageStorage.o Image.o react.o -lcurl