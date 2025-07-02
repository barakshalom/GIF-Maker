#include "linkedList.h"
#include "input.h"

/*
* Function is getting frame info and creating Frame
* Input - char* path, char* name, unsigned int duration (frame info)
* Output - new Frame pointer
*/
Frame* createFrame(char* path, char* name, unsigned int duration) {
    // Allocation memory for new Frame
    Frame* newFrame = (Frame*)malloc(sizeof(Frame));
    
    // Allocation memory for name and path and put the desired information in the frame (+ 1 for \0 space)
    newFrame->name = (char*)malloc(strlen(name) + 1);
    newFrame->path = (char*)malloc(strlen(path) + 1);

    strcpy(newFrame->name, name);
    strcpy(newFrame->path, path);
    newFrame->duration = duration;

    // Return new Frame pointer
    return newFrame;
}

/*
* Function is getting FrameNode info and creating FrameNode
* Input - Frame* frame (FrameNode info)
* Output - new FrameNode pointer
*/
FrameNode* createFrameNode(Frame* frame) {
    // Allocation memory for new FrameNode
    FrameNode* newFrameNode = (FrameNode*)malloc(sizeof(FrameNode));

    // Allocation memory for new Frame and put the desired information 
    newFrameNode->frame = (Frame*)malloc(strlen(frame) + 1);
    newFrameNode->frame = frame;

    newFrameNode->next = NULL;

    // Returning new FrameNode pointer
    return newFrameNode;
}

/*
* Function adds a new frame node to the end of a linked list of frames
* Input - pointer to the head of the linked list of frame nodes
* Output - none.
*/
void addFrame(FrameNode** list) {
    char* framePath = NULL;
    char* frameName = NULL;
    unsigned int duration = 0;

    FrameNode* tail = *list;  // Initialize tail with the list pointer
    FrameNode* newFrameNode = NULL;
    Frame* newFrame = NULL;

    printf("*** Creating new frame ***\n");

    // Get frame path 
    printf("Please insert frame path:\n");
    framePath = getFilePath();

    // Get frame duration
    printf("Please insert frame duration (in milliseconds):\n");
    duration = getFrameDuration();

    // Get frame name
    printf("Please choose a name for the frame:\n");
    frameName = getFrameName(*list);
    
    // Creating a new Frame with all the details
    newFrame = createFrame(framePath, frameName, duration);

    // Creating a new FrameNode with the new Frame
    newFrameNode = createFrameNode(newFrame);

    // Adding the node to the list
    if (tail == NULL) {
        // If the list is empty, assign the new node as the head
        *list = newFrameNode;
    }
    else {
        // Traverse to the end of the list to append the new node
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newFrameNode;
    }

    // Free the temporary allocations
    free(frameName);
    free(framePath);
}

/*
* Function erase frame node from the linked list of frames
* Input - pointer to the head of the linked list of frame nodes
* Output - none.
*/
void deleteFrame(FrameNode** list) {
    char* frameName = NULL;
    FrameNode* curr = *list;
    FrameNode* prev = NULL;

    // Get frame name
    printf("Enter the name of the frame you wish to erase:\n");
    frameName = getName();

    // If head node itself holds the key to be deleted
    if (curr != NULL && strcmp(curr->frame->name, frameName) == 0) {
        // Change head
        *list = curr->next;

        free(curr);
        free(frameName);
        return;
    }

    // Search for the frame to be deleted
    while (curr != NULL && strcmp(curr->frame->name, frameName) != 0) {
        prev = curr;
        curr = curr->next;
    }

    // If frame was not present in linked list
    if (curr == NULL) {
        free(frameName); 
        printf("The frame was not found\n");
        return;
    }

    // Unlink the node from linked list
    prev->next = curr->next;

    free(curr);
    free(frameName); 
}

/*
* Function is changing frame index
* Input - pointer to the head of the linked list of frame nodes
* Output - none.
*/
void changeFrameIndex(FrameNode** list) {
    char* frameName = NULL;
    unsigned int newIndex = 0;
    FrameNode* curr = *list;

    FrameNode* prev = NULL;
    FrameNode* target = NULL;
    FrameNode* targetPrev = NULL;

    int i = 0;

    // Get frame name
    printf("Enter the name of the frame:\n");

    frameName = getName();

    // Get new index
    printf("Enter the new index in the movie you wish to place the frame:\n");
    scanf("%d", &newIndex);
    newIndex--;

    // Find the target frame
    while (curr != NULL && strcmp(curr->frame->name, frameName) != 0) {
        // Save the prev so when we find it well have it
        targetPrev = curr;
        curr = curr->next;
    }

    // If frame was not present in linked list
    if (curr == NULL) {
        printf("The frame does not exist\n");
        free(frameName);
        return;
    }

    target = curr;

    // Remove target frame from the list
        if (targetPrev == NULL) {
        // Target is the head of the list
        *list = target->next;
    }
    else {
        targetPrev->next = target->next;
    }

    // Insert target frame at the new index
    if (newIndex == 0) {
        // Target index is the head of the list
        target->next = *list;
        *list = target;
    }
    else {
        curr = *list;
        for (i = 0; i < newIndex - 1 && curr != NULL; i++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            printf("The new index is out of bounds\n");
            free(frameName);
            // Reinsert target back to the original position
            if (targetPrev == NULL) {
                target->next = *list;
                *list = target;
            }
            else {
                targetPrev->next = target;
                target->next = curr;
            }
            return;
        }

        target->next = curr->next;
        curr->next = target;
    }

    // Free memory
    free(frameName);
}

/*
* Function is changing frame duration
* Input - head of the linked list of frame nodes, name of the frame want to change, duration to chnage to
* Output - none.
*/
void changeFrameDuration(FrameNode* list, char* frameName, unsigned int duration) {
    FrameNode* curr = list;

    // If head node itself holds the frame to be modified
    if (curr != NULL && strcmp(curr->frame->name, frameName) == 0) {
        // Change duration
        curr->frame->duration = duration;
        return;
    }

    // Search for the frame in the linked list
    while (curr != NULL && strcmp(curr->frame->name, frameName) != 0) {
        curr = curr->next;
    }

    // If frame was not present in linked list
    if (curr == NULL) {
        printf("The frame does not exist\n");
        return;
    }

    // Change the duration
    curr->frame->duration = duration;
}

/*
* Function is changing one frame duration
* Input - head of the linked list of frame nodes
* Output - none.
*/
void chnageOneFrameDuration(FrameNode* list) {
    unsigned int duration = 0;
    char* frameName = NULL;

    // Get frame name
    printf("Enter the name of the frame:\n");

    frameName = getName();

    printf("Enter the new duration:\n");
    duration = getFrameDuration();

    changeFrameDuration(list, frameName, duration);
}

/*
* Function is changing all frames duration
* Input - head of the linked list of frame nodes
* Output - none.
*/
void changeAllFramesDuration(FrameNode* list) {
    FrameNode* curr = list;

    unsigned int duration = 0;

    printf("Enter the duration for all frames::\n");
    duration = getFrameDuration();

    while (curr != NULL) {
        curr->frame->duration = duration;
        curr = curr->next;
    }
}

/*
* Function is freeing alllll space
* Input - head of the linked list of frame nodes
* Output - none.
*/
void freeLinkedList(FrameNode* list) {
    FrameNode* current = list;
    FrameNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}


