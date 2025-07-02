#ifndef MEMORYH
#define MEMORYH

#include "LinkedList.h"

#define MAX_LINE_LENGTH 80

/*
* Function is saving the list into a file
* Input - head of the linked list of frame nodes
* Output - none.
*/
void saveList(FrameNode* list);

/*
* Function is loading the list into the program so you can edit it
* Input - pointer to head of the linked list of frame nodes
* Output - none.
*/
void loadList(FrameNode** list);

#endif