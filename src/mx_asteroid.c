#include "../inc/header.h"

t_object *mx_create_asteroid() {
    t_object *asteroid = (t_object*)malloc(sizeof(t_object));
    asteroid->hp = 100;
    asteroid->option = 0;
    asteroid->texture = asteroid_texture;
    srand(time(NULL));
    asteroid->x = rand() % WIGHT;
    SDL_Rect pos;
    SDL_QueryTexture(asteroid->texture, NULL, NULL, &pos.w, &pos.h);
    if (asteroid->x > WIGHT - pos.w)
        asteroid->x -= pos.w;
    asteroid->y = -300;
    return asteroid;
}
void mx_rerand_asteroid(t_object *asteroid){
    asteroid->hp = 100;
    asteroid->option = 1;
    asteroid->texture = asteroid_texture;
    srand(time(NULL));
    asteroid->x = rand() % WIGHT;
    SDL_Rect pos;
    SDL_QueryTexture(asteroid->texture, NULL, NULL, &pos.w, &pos.h);
    if (asteroid->x > WIGHT - pos.w)
        asteroid->x -= pos.w;
    asteroid->y = -300;
}
void mx_asteroid_rain(t_object *asteroid) {
    if(asteroid->y > HIGHT + 200) {
        mx_rerand_asteroid(asteroid);
    }
    mx_draw_object(asteroid);
    asteroid->y += 10;
}
