#include "view.h"
#include "linkedList.h"
#include "screen.h"
#include "input.h"
#include "memory.h"


void main(void) {
	FrameNode* list = NULL;

	int firstChoice = 0;
	int secondChoice = 1;

	printFirstMenu();
	firstChoice = getChoice(FIRST_CHOICE_NIM, FIRST_CHOICE_MAX);
	
	if (firstChoice == 1) {
		getchar();
		loadList(&list);
	}

	while (secondChoice != 0) {
		printSecondMenu();
		secondChoice = getChoice(SECOND_CHOICE_NIM, SECOND_CHOICE_MAX);
		switch (secondChoice) {
			case 0:
				printf("byeee :)\n");
				break;
			case 1:
				getchar();

				addFrame(&list);
				break;
			case 2:
				getchar();

				deleteFrame(&list);
				break;
			case 3:
				getchar();
				changeFrameIndex(&list);
				break;
			case 4:
				getchar();

				chnageOneFrameDuration(list);

				break;
			case 5:
				getchar();

				changeAllFramesDuration(list);
				break;
			case 6:
				getchar();

				printFrameList(list);
				break;
			case 7:
				getchar();

				play(list);
				break;
			case 8:
				getchar();

				saveList(list);
				break;
		}
	}
	
	freeLinkedList(list);

	getchar();
	return 0;
}
