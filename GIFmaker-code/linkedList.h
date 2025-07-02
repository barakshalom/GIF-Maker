#ifndef LINKEDLISTH
#define LINKEDLISTH
#pragma warning(disable:4996)

#define FALSE 0
#define TRUE !FALSE

#define BUFFER 265

#define FIRST_CHOICE_NIM 0
#define FIRST_CHOICE_MAX 1

#define SECOND_CHOICE_NIM 0
#define SECOND_CHOICE_MAX 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Frame struct
typedef struct Frame
{
	char*		name;
	unsigned int	duration;
	char*		path;  
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

/*
* Function is getting frame info and creating Frame
* Input - char* path, char* name, unsigned int duration (frame info)
* Output - new Frame pointer
*/
Frame* createFrame(char* path, char* name, unsigned int duration);

/*
* Function is getting FrameNode info and creating FrameNode
* Input - Frame* frame (FrameNode info)
* Output - new FrameNode pointer
*/
FrameNode* createFrameNode(Frame* frame);

/*
* Function adds a new frame node to the end of a linked list of frames
* Input - pointer to the head of the linked list of frame nodes
* Output - none.
*/
void addFrame(FrameNode** list);

/*
* Function erase frame node from the linked list of frames
* Input - pointer to the head of the linked list of frame nodes
* Output - none.
*/
void deleteFrame(FrameNode** list);

/*
* Function is changing frame index
* Input - pointer to the head of the linked list of frame nodes
* Output - none.
*/
void changeFrameIndex(FrameNode** list);

/*
* Function is changing frame duration
* Input - head of the linked list of frame nodes, name of the frame want to change, duration to chnage to
* Output - none.
*/
void changeFrameDuration(FrameNode* list, char* frameName, unsigned int duration);

/*
* Function is changing one frame duration
* Input - head of the linked list of frame nodes
* Output - none.
*/
void chnageOneFrameDuration(FrameNode* list);

/*
* Function is changing all frames duration
* Input - head of the linked list of frame nodes
* Output - none.
*/
void changeAllFramesDuration(FrameNode* list);

/*
* Function is freeing alllll space
* Input - head of the linked list of frame nodes
* Output - none.
*/
void freeLinkedList(FrameNode* list);

#endif
