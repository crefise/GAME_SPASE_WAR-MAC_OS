#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>

extern SDL_Window *window;
extern SDL_Surface *screen;
extern SDL_Surface *surface_texture;
extern SDL_Renderer *render;
extern SDL_Texture *background_texture;
extern SDL_Texture *player_texture_1;
extern SDL_Texture *player_texture_2;
extern SDL_Texture *asteroid_texture;
extern SDL_Texture *bullet_texture;
extern SDL_Texture *enemy_texture_easy;
extern SDL_Texture *enemy_texture_medium;
extern SDL_Texture *enemy_texture_hard;
extern SDL_Texture *hp_texture;
extern SDL_Texture *BOOM_texture_1;
extern SDL_Texture *BOOM_texture_2;
extern SDL_Texture *BOOM_texture_3;
extern SDL_Texture *BOOM_texture_4;
extern SDL_Texture *BOOM_texture_5;
extern SDL_Texture *BOOM_texture_6;
extern SDL_Texture *button_play;
extern SDL_Texture *button_quit;
extern SDL_Texture *name_game;
extern SDL_Texture *button_shop;
extern SDL_Texture *enemy_bullets;
extern SDL_Surface *surfaceMessage;
extern SDL_Surface *surfaceMessage_1;
extern SDL_Texture* Message;
extern SDL_Texture* Message_1;

extern SDL_Surface *pause_2;
extern SDL_Texture* pause_1;

extern SDL_Rect Message_rect;
extern const int FPS;
extern int timer_seconds;
extern const int HIGHT;
extern const int WIGHT;

typedef struct s_object {
    int x;
    int y;
    int hp;
    int option;
    int help;
    int time;
    SDL_Texture *texture;
}              t_object;

typedef struct s_list {
    t_object object;
    struct s_list *next;
}               t_list;
void mx_pop_back(t_list **list);
void mx_pop_index(t_list **list, int index);
void mx_push_back(t_list **list, t_object *object);
t_list *mx_create_node(t_object *copy_object);
int mx_list_size(t_list *list);
SDL_Texture *mx_load_texture(const char *file);
void mx_clear();
void mx_init();
void mx_background();
void mx_pop_front(t_list **head);
void mx_draw_bullets(t_list *list);
void mx_remove_bullets(t_list **bullet, t_object *asteroid);
void mx_load_all_textures();

void mx_ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
void mx_draw_object(t_object *object);
t_object *mx_create_player();
t_object *mx_create_asteroid();
void mx_asteroid_rain(t_object *asteroid);
void mx_rerand_asteroid(t_object *asteroid);
bool mx_collision_object(t_object *obj1, t_object *obj2);
t_object* mx_create_easy_enemy(t_object *asteroid);
void mx_draw_enemies(t_list **enemies);
void mx_remove_enemies(t_list **enemies);
void mx_draw_hp(int x, int y);
void mx_kill_enemy(t_list **enemies);
void mx_check_kill_enemy(t_list **enemies, t_list **bullets, t_list **dead, t_object *player);
void mx_cheak_lose_hp(t_object *player, t_object *asteroid, t_list **enemy, t_list **dead_enemy);
void mx_cheak_dead(t_list **dead);
void mx_swap_boom_texture_for_dead(t_list *dead);
SDL_Texture *mx_boom_texture(int time_sprite);
void mx_swap_boom_texture_for_player(t_object *player, int i);

Mix_Chunk *bomm_chank;
//////////////////////menu
void mx_draw_button_play();
bool mx_click_play(int mouseX, int mouseY);
void mx_draw_button_shop();
void mx_draw_game_name();
void mx_draw_button_quit();
bool mx_click_quit(int mouseX, int mouseY);

void mx_bullet_mechanic(t_object *player, t_list **bullets);
t_object* mx_create_meduim_enemy();




char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char* src);
char *mx_strjoin(char const *s1, char const *s2);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
int mx_static_abs(int num);
char *mx_score(int score);
char *mx_strcat(char *s1, const char *s2);

void mx_window_write();
void mx_window_write_1();

void mx_create_enemy_bullets(t_list **bullets,t_list *enemies);

void mx_draw_pause();
#endif
