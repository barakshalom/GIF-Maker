#include "input.h"

/*
* Function getting limits and receives input from the user until it is between those limits and returns it
* Input - min number and max number (limits for input)
* Output - correct input from user
*/
int getChoice(int min, int max) {
	int choice = 0;
    int result = 0;

    while (1) {
        result = scanf("%d", &choice);

        if (choice > max || choice < min || result != 1) {
            // Invalid input received
            printf("You should type one of the options - %d-%d!\n", min, max);
            // Clear the input buffer
            while (getchar() != '\n');
        }
        else {
            // Valid input received
            
            break;
        }
    }

	return choice;
}

/*
* Function getting file path input from user untill its a real file with contant
* Input - none
* Output - correct file path
*/
char* getFilePath() { 
    char* buffer = (char*)malloc(sizeof(char) * BUFFER);

    char* filePath = NULL;
    FILE* file = NULL;

    // Get frame path until it's not empty
    while (file == NULL) {

        // Putting the input in a buffer so we can allocate memory appropriate for the size of the input
        myFgets(buffer, BUFFER);

        // Allocate memory appropriate for the size of the input
        filePath = (char*)malloc(strlen(buffer) + 1);

        // Putting the desired information into place
        strcpy(filePath, buffer);

        // Opening the file to check if it's empty
        file = fopen(filePath, "r");

        if (file == NULL) {
            printf("This file doesnt exist, enter a file path: ");
            free(filePath);
            filePath = NULL;
        }
    }

    // Closing the file
    fclose(file);
    free(buffer);
    return filePath;
}

/*
* Function getting name input from user untill its a new name that not alr used
* Input - list of frames
* Output - correct name
*/
char* getFrameName(FrameNode* list) {
    char* buffer = (char*)malloc(sizeof(char) * BUFFER);
    char* fileName = NULL;

    while (1) {
        myFgets(buffer, BUFFER);
        if (list == NULL) {
            break;
        }
        if (!nameExists(list, buffer)) {
            break; // Exit the loop if the name is not in the list
        }
        printf("Name already exists. Please enter a different name:\n");
    }

    // Allocate memory appropriate for the size of the input
    fileName = (char*)malloc(strlen(buffer) + 1);

    // Putting the desired information into place
    strcpy(fileName, buffer);

    free(buffer);
    return fileName;
}

/*
* Function checking if name is in list
* Input - list of frames
* Output - correct name
*/
int nameExists(FrameNode* list, char* name) {
    FrameNode* curr = list;
    while (curr) {
        if (strcmp(curr->frame->name, name) == 0) {
            return TRUE; // Name found in the list
        }
        curr = curr->next;
    }
    return FALSE; // Name not found in the list
}

/*
* Function getting name input from user
* Input - list of frames
* Output - correct name
*/
char* getName() {
    char* buffer = (char*)malloc(sizeof(char) * BUFFER);

    char* fileName = NULL;

    myFgets(buffer, BUFFER);
    
    // Allocate memory appropriate for the size of the input
    fileName = (char*)malloc(strlen(buffer) + 1);

    // Putting the desired information into place
    strcpy(fileName, buffer);

    free(buffer);
    return fileName;
}


/*
* Function getting duration input from user untill its unsigned int 
* Input - none
* Output - correct duration
*/
unsigned int getFrameDuration() {
    unsigned int duration = 0;
    int result = 0;

    while (1) {
        result = scanf("%u", &duration);
        getchar();  

        if (result == 1) {
            // Valid input received
            break;
        }
        else {
            // Invalid input received
            printf("Duration can only be a number! \n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
    }

    return duration;
}

/*
* Function will perform the fgets command and also remove the newline
* that might be at the end of the string - a known issue with fgets.
* input: the buffer to read into, the number of chars to read
*/
void myFgets(char str[], int n) {
    if (fgets(str, n, stdin) != NULL) {  // Read input using fgets
        str[strcspn(str, "\n")] = '\0';  // Remove newline character, if present
    }
}