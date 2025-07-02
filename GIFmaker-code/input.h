#ifndef INPUTH
#define INPUTH
#define CV_IGNORE_DEBUG_BUILD_GUARD

#include "linkedList.h"

/*
* Function getting limits and receives input from the user until it is between those limits and returns it
* Input - min number and max number (limits for input)
* Output - correct input from user
*/
int getChoice(int min, int max);

/*
* Function getting file path input from user untill its a real file with contant
* Input - none
* Output - correct file path
*/
char* getFilePath();

/*
* Function getting name input from user untill its a new name that not alr used
* Input - list of frames
* Output - correct name
*/
char* getFrameName(FrameNode* list);

/*
* Function checking if name is in list
* Input - list of frames
* Output - correct name
*/
int nameExists(FrameNode* list, char* name);

/*
* Function getting name input from user
* Input - list of frames
* Output - correct name
*/
char* getName();

/*
* Function getting duration input from user untill its unsigned int
* Input - none
* Output - correct duration
*/
unsigned int getFrameDuration();

/*
* Function will perform the fgets command and also remove the newline
* that might be at the end of the string - a known issue with fgets.
* input: the buffer to read into, the number of chars to read
*/
void myFgets(char str[], int n);

#endif