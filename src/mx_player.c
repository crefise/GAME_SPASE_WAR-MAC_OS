#include "../inc/header.h"

t_object *mx_create_player() {
    t_object *player = (t_object*)malloc(sizeof(t_object));
    player->hp = 5;
    player->option = 0;
    player->texture = player_texture_1;
    player->x = WIGHT/2 - 50;
    player->y = HIGHT - 200;
    player->help = 0;
    return player;
}
void mx_draw_hp(int x, int y) {
    mx_ApplySurface(x, y, hp_texture, render);
}
void mx_cheak_lose_hp(t_object *player, t_object *asteroid, t_list **enemy, t_list **dead_enemy) {
    bomm_chank = Mix_LoadWAV("resource/music/boom.wav");
    if (player->hp <= 0)
        return;
    if (mx_collision_object(player, asteroid)) {
        player->hp = 0;
        ///////////////////////////////////////////////////////////////////////meteor
        
    }
    t_list *temp = *enemy;
    int index = 0;
    while(temp) {
        if(mx_collision_object(&temp->object, player)) {
            player->hp--;
            Mix_PlayChannel(1,bomm_chank,0);
            temp->object.hp = 0;
            if (!dead_enemy || !*dead_enemy)
               (*dead_enemy) = mx_create_node(&temp->object);
            else
                mx_push_back(dead_enemy, &temp->object);
            mx_pop_index(enemy, index);
            return;
        }
        index++;
        temp = temp->next;
    }
    return;
}
void mx_swap_boom_texture_for_player(t_object *player, int i) {
    player->texture = mx_boom_texture(i);
    i ++;
}

