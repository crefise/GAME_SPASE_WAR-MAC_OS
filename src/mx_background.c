#include "../inc/header.h"

int back_y = 0;
int back_z = -1920;


void mx_background(){
    
    mx_ApplySurface(0,back_y,background_texture, render);
    mx_ApplySurface(0,back_z,background_texture, render);
    if(back_y == 1920) { back_y = -1920;}
    if(back_z == 1920) { back_z = -1920;}

    back_y+=2;
    back_z+=2;
    
}
