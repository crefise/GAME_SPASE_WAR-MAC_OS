#include "../inc/header.h"

SDL_Texture *mx_load_texture(const char *file) {
    SDL_Texture *temp_texture = IMG_LoadTexture(render, file);
    return temp_texture;
}

void mx_init() {
    SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO);
    window = SDL_CreateWindow("Space War", 100, 100, WIGHT, HIGHT, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}   

void mx_clear() {
    
    SDL_DestroyWindow(window);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(surface_texture);
    SDL_FreeSurface(surfaceMessage_1);
    SDL_FreeSurface(surfaceMessage);
    SDL_FreeSurface(pause_2);
    SDL_DestroyTexture(background_texture);
    SDL_DestroyTexture(player_texture_1);
    SDL_DestroyTexture(player_texture_2);
    SDL_DestroyTexture(asteroid_texture);
    SDL_DestroyTexture(bullet_texture);
    SDL_DestroyTexture(enemy_texture_easy);
    SDL_DestroyTexture(enemy_texture_medium);
    SDL_DestroyTexture(enemy_texture_hard);
    SDL_DestroyTexture(hp_texture);
    SDL_DestroyTexture(BOOM_texture_1);
    SDL_DestroyTexture(BOOM_texture_2);
    SDL_DestroyTexture(BOOM_texture_3);
    SDL_DestroyTexture(BOOM_texture_4);
    SDL_DestroyTexture(BOOM_texture_5);
    SDL_DestroyTexture(BOOM_texture_6);
    SDL_DestroyTexture(button_play);
    SDL_DestroyTexture(button_quit);
    SDL_DestroyTexture(name_game);
    SDL_DestroyTexture(button_shop);
    SDL_DestroyTexture(enemy_bullets);
    SDL_DestroyTexture(Message);
    SDL_DestroyTexture(Message_1);
    SDL_DestroyTexture(pause_1);
    SDL_DestroyRenderer(render);
    SDL_Quit();
}

void mx_ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
   SDL_RenderCopy(rend, tex, NULL, &pos);
}

void mx_load_all_textures() {
    background_texture = mx_load_texture("resource/image/background.png");

    name_game = mx_load_texture("resource/image/logo.png");
    button_play = mx_load_texture("resource/image/button_play.png");
    button_shop = mx_load_texture("resource/image/shop.png");
    button_quit = mx_load_texture("resource/image/button_quit.png");
    
    player_texture_1 = mx_load_texture("resource/image/player1.png");
    player_texture_2 = mx_load_texture("resource/image/player2.png");
    asteroid_texture = mx_load_texture("resource/image/asteroid_texture.png");
    bullet_texture = mx_load_texture("resource/image/bullet.png");
    enemy_texture_easy = mx_load_texture("resource/image/easy_enemy.png");


    enemy_texture_medium = mx_load_texture("resource/image/medium_enemy.png");

    enemy_bullets = mx_load_texture("resource/image/enemy_bullets.png");
    hp_texture = mx_load_texture("resource/image/hp.png");
    BOOM_texture_1 = mx_load_texture("resource/image/boom1.png");
    BOOM_texture_2 = mx_load_texture("resource/image/boom2.png");
    BOOM_texture_3 = mx_load_texture("resource/image/boom3.png");
    BOOM_texture_4 = mx_load_texture("resource/image/boom4.png");
    BOOM_texture_5 = mx_load_texture("resource/image/boom5.png");
    BOOM_texture_6 = mx_load_texture("resource/image/boom6.png"); 
}
SDL_Texture *mx_boom_texture(int time_sprite) {
    
    int t = time_sprite / 10;
    t = t % 6;
    if (t == 0) 
        return BOOM_texture_1;
    else
        if (t == 1)
            return BOOM_texture_2;
        else
            if (t == 2)
                return BOOM_texture_3;
            else
                if (t == 3)
                    return BOOM_texture_4;
                else
                    if (t == 4)
                        return BOOM_texture_5;
                    else
                        return BOOM_texture_6;  
}


void mx_window_write() {
    mx_ApplySurface(800, 0, Message, render);
}
void mx_window_write_1() {
    mx_ApplySurface(950, 0, Message_1, render);
}

void mx_draw_pause() {
    mx_ApplySurface(800, 45, pause_1, render);
}
