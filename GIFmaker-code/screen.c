#include "screen.h"

/*
* Function getting list of frames and printing it
* Input - list of frames
* Output - none.
*/
void printFrameList(FrameNode* list) {
    FrameNode* curr = list;
    printf("\n");
    printf("                Name            Duration        Path\n");
    while (curr)
    {
        printf("                %s            %u ms        %s\n", curr->frame->name, curr->frame->duration, curr->frame->path);
        curr = curr->next;
        printf("\n");
    }
}

/*
* Function printing first menu
* Input - none.
* Output - none.
*/
void printFirstMenu() {
    printf("Welcome to Magshimim Movie Maker! what whould you like to do?\n");
    printf(" [0] Create a new project\n");
    printf(" [1] Load existing project\n");
}

/*
* Function printing second menu
* Input - none.
* Output - none.
*/
void printSecondMenu() {
    printf("\nWhat would you like to do?\n");
    printf(" [0] Exit\n");
    printf(" [1] Add new Frame\n");
    printf(" [2] Remove a Frame\n");
    printf(" [3] Change frame index\n");
    printf(" [4] Change frame duration\n");
    printf(" [5] Change duration of all frames\n");
    printf(" [6] List frames\n");
    printf(" [7] Play movie!\n");
    printf(" [8] Save project\n");
}