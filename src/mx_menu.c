#include "../inc/header.h"

void mx_draw_button_play() {
    mx_ApplySurface(340, 550, button_play, render);
}

bool mx_click_play(int mouseX, int mouseY) {
    bool l = false;
    SDL_Rect pos;
    SDL_QueryTexture(button_play, NULL, NULL, &pos.w, &pos.h);
    if((mouseX >= 340 && mouseX <= 340+pos.w) && (mouseY >= 550 && mouseY <= 550+pos.h)) {
        l = true;
    }
    return l;
}
void mx_draw_button_shop() {
    mx_ApplySurface(340, 750, button_shop, render);
}

void mx_draw_game_name() {
    mx_ApplySurface(190, 250, name_game, render);
}

void mx_draw_button_quit() {
    mx_ApplySurface(340,950, button_quit, render);
}

bool mx_click_quit(int mouseX, int mouseY) {
    bool k = false;
    SDL_Rect pos;
    SDL_QueryTexture(button_quit, NULL, NULL, &pos.w, &pos.h);
    if((340 <= mouseX  && mouseX <= 340+pos.w) && (950 <= mouseY && 950+pos.h)) {
        k = true;
    }
    return k;
}
