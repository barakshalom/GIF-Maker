#ifndef SCREENH
#define SCREENH
#define CV_IGNORE_DEBUG_BUILD_GUARD

#include "LinkedList.h"

/*
* Function getting list of frames and printing it
* Input - list of frames
* Output - none.
*/
void printFrameList(FrameNode* list);

/*
* Function printing first menu
* Input - none.
* Output - none.
*/
void printFirstMenu();

/*
* Function printing second menu
* Input - none.
* Output - none.
*/
void printSecondMenu();

#endif