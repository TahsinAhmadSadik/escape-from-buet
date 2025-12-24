#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "iGraphics.h"
#include "iSound.h"

//scenes
#include "scenes/scene0.h"

//all variables
int scene = 0;
bool init = false;
int loader_count = 0;

int W, H;
double ratio;

//all images
Image cover;

void loadImages()
{
    switch(loader_count)
    {
        case 0: iLoadImage(&cover, "assets/images/cover.png");iScaleImage(&cover, ratio); loader_count++; break;
        default: break;
    }
}

void sound_handle(int idx)
{
    return;
}

void saveGame(void)
{
    return;
}



void newGameInit(void)
{
    return;
}


void iDraw()
{
    iClear();
    //Full screen
    if(init == false) init = true, iToggleFullscreen();

    switch(scene)
    {
    case 0:
        scene0_render(ratio);
        break;
    }
}



void iMouseMove(int mx, int my)
{
    switch(scene)
    {
    case 1:
        break;
    }
}

void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        switch(scene)
        {
        case 1:
            break;
        }
    }
}

void iKeyboard(unsigned char key)
{
    switch(scene)
    {
    case 0:
        keyboard0(key);
        break;
    }

    //press "q" to quit the game (temporary, dev use)
    if(key == 'q') exit(0);
}

void iSpecialKeyboard(unsigned char key)
{
    switch(scene)
    {
    case 4:
        break;
    }
}

void iMouseDrag(int mx, int my)
{
    return;
}

void iMouseWheel(int dir, int mx, int my)
{
    return;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    iInitializeSound();
    //Starting the Game
    //Load Save Game
    W = glutGet(GLUT_SCREEN_WIDTH);
    H = glutGet(GLUT_SCREEN_HEIGHT);
    ratio = 1920/W;
    iInitialize(W, H, "Escape from BUET");
    return 0;
}
