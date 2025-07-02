#include "memory.h"
#include "input.h"

void saveList(FrameNode* list) {
	FILE* fptr = NULL;
	FrameNode* curr = list;
	char* fileName = NULL;
	char* filePath = NULL;

	printf("Where to save the project? enter a full path and file name\n");
	fileName = getName();

	filePath = (char*)malloc(strlen(fileName) + 5); // 4 for ".txt" and 1 for null terminator

	sprintf(filePath, "%s.txt", fileName);

	// Open a file in writing mode
	fptr = fopen(filePath, "w");

    while (curr) {
        fprintf(fptr, "%s,%u,%s\n", curr->frame->path, curr->frame->duration, curr->frame->name);
        curr = curr->next;
    }

    // Close the file
    free(filePath);
    fclose(fptr);
}

void loadList(FrameNode** list) {
    FILE* file = NULL;
    FrameNode* curr = NULL;
    Frame* newFrame = NULL;
    FrameNode* newFrameNode = NULL;

    char* filePath = NULL;
    char buffPath[BUFFER];
    char buffName[BUFFER];
    unsigned int frameDuration = 0;

    char* frameName = NULL;
    char* framePath = NULL;

    char line[MAX_LINE_LENGTH] = { 0 };

    printf("Enter the path of the project (including project name):\n");
    filePath = getFilePath();

    // Open a file in reading mode
    file = fopen(filePath, "r");

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%255[^,],%u,%255[^\n]", buffPath, &frameDuration, buffName);

        framePath = (char*)malloc(strlen(buffPath) + 1);
        frameName = (char*)malloc(strlen(buffName) + 1);

        strcpy(framePath, buffPath);
        strcpy(frameName, buffName);

        newFrame = createFrame(framePath, frameName, frameDuration);
        newFrameNode = createFrameNode(newFrame);

        if (*list == NULL) {
            *list = newFrameNode; // First node
            curr = *list;
        }
        else {
            curr->next = newFrameNode;
            curr = curr->next;
        }
    }

    fclose(file);
    free(filePath);
}

//C:\Users\Cyber_User\source\repos\project2024\project2024\project.txt