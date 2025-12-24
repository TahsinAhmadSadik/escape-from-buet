#ifndef scene0_h
#define scene0_h
#include "iGraphics.h"

//variables
bool new_game_check = false;

//renderer
void scene0_render(int ratio){
    //Main Menu (Simple, only a cover photo and some options)
    if(new_game_check == false) iText(600*ratio,48*ratio, "[Space] Continue Game     [N] New Game", GLUT_BITMAP_TIMES_ROMAN_24);
    else iText(500*ratio,82*ratio, "New game will overwrite your previous progress. Are you sure?", GLUT_BITMAP_TIMES_ROMAN_24), iText(700*ratio,48*ratio, "[Space] Yes     [N] No", GLUT_BITMAP_TIMES_ROMAN_24);
}

//input
void keyboard0(unsigned char key){
    if(new_game_check == false){
        if(key == 'n' || key == 'N') new_game_check = true;
        else if(key == ' ') return; //continue
    }
    else{
        
        if(key == 'n' || key == 'N') new_game_check = false;
        else if(key == ' ') return; //new_game
    }
}
#endif