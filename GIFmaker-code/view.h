#ifndef VIEWH
#define VIEWH
#define CV_IGNORE_DEBUG_BUILD_GUARD

#include <opencv2/imgcodecs/imgcodecs_c.h>

#include <opencv2\core\core_c.h>
#include <opencv2\highgui\highgui_c.h>
#include "LinkedList.h"

#define GIF_REPEAT 5

/**
play the movie!!
display the images each for the duration of the frame one by one and close the window
input: a linked list of frames to display
output: none
**/
void play(FrameNode* list);

#endif