#include "../inc/header.h"


t_object *mx_create_easy_enemy(t_object *asteroid) {
    t_object *enemy = (t_object*)malloc(sizeof(t_object));
    SDL_Rect pos;
    enemy->texture = enemy_texture_easy;
    SDL_QueryTexture(enemy->texture, NULL, NULL, &pos.w, &pos.h);
    enemy->hp = 1;
    enemy->option = -351; // 3 - ne strelaet 4 - strelaet
    srand(time(NULL));
    enemy->y = -900;
    do
    {
        enemy->x = rand() % WIGHT;
        if (enemy->x > WIGHT - pos.w)
            enemy->x -= pos.w;

    } while (mx_collision_object(asteroid, enemy));
    
    return enemy;
}

t_object* mx_create_meduim_enemy(){
     t_object *enemy = (t_object*)malloc(sizeof(t_object));
    SDL_Rect pos;
    enemy->texture = enemy_texture_medium;
    SDL_QueryTexture(enemy->texture, NULL, NULL, &pos.w, &pos.h);
    enemy->hp = 2;
    srand(time(NULL));
    enemy->y =  -1200;
    enemy->x = rand() % WIGHT;
    if (enemy->x == 0)
        enemy->x = 60;
    if (enemy->x > (WIGHT - pos.w))
        enemy->x -= (pos.w + 50);
    enemy->option = enemy->x;
    enemy->help = 1;
    return enemy;
}

void mx_draw_enemies(t_list **enemies) {
    t_list *temp = *enemies;
    while (temp != NULL)
    {
        if (temp->object.x == temp->object.option + 50)
            temp->object.help *= -1;
        if (temp->object.x == temp->object.option - 50)
            temp->object.help *= -1;
        if (temp->object.option == -351) {
        mx_draw_object(&temp->object);
        temp->object.y += 5;
        }
        else {
            mx_draw_object(&temp->object);
            if (temp->object.help < 0)
                temp->object.x--;
            else
                temp->object.x++;
          temp->object.y += 5;
        }
        temp = temp->next;
    }
}

void mx_remove_enemies(t_list **enemies) {
    if (*enemies == NULL || enemies == NULL)
        return;
    t_list *temp = *enemies;
    if (temp->object.y > (HIGHT + 200))
        mx_pop_front(enemies);
    return;
}

void mx_kill_enemy(t_list **enemies) {
    t_list *temp = *enemies;
    for (int i = 0; i < mx_list_size(*enemies); i++) {
        if(temp->object.hp <= 0) {
            mx_pop_index(enemies,i);
        }
    }
}

void mx_check_kill_enemy(t_list **enemies, t_list **bullets, t_list **dead, t_object *player) {
    Mix_Chunk *hint_mus = Mix_LoadWAV("resource/music/hint.wav");
    t_list *temp_enemy = *enemies;
    t_list *temp_bullet = NULL;
    int enemy_index = 0;
    while (temp_enemy) {
        int bullet_index = 0;
        temp_bullet = *bullets;
        while (temp_bullet) {
            if (mx_collision_object(&temp_enemy->object, &temp_bullet->object) && temp_bullet->object.option == 1) {
                temp_enemy->object.hp -= 1;
                Mix_PlayChannel(1,bomm_chank,0);
                if(temp_enemy->object.hp  <= 0) {
                    if (temp_enemy->object.option == -351)
                        player->help += 10;
                    else
                        player->help += 20;
                    temp_enemy->object.hp = 0;
                    Mix_PlayChannel(1,bomm_chank,0);
                if (!dead || !*dead)
                    (*dead) = mx_create_node(&temp_enemy->object);
                else
                    mx_push_back(dead, &temp_enemy->object);
                mx_pop_index(enemies, enemy_index);
                }
                mx_pop_index(bullets, bullet_index);
                return;
            }
            temp_bullet = temp_bullet->next;
            bullet_index++;
        }
        enemy_index++;
        temp_enemy = temp_enemy->next;
    }
    temp_bullet = *bullets;
    int index = 0;
    while (temp_bullet) {
        if (mx_collision_object(player, &temp_bullet->object) && (temp_bullet->object.option == 2) && (player->hp > 0)) {
            player->hp -= 1;
            Mix_PlayChannel(1, hint_mus, 0);
            mx_pop_index(bullets, index);
            break;
        }
        temp_bullet = temp_bullet->next;
        index++;
    }
    return;
}







void mx_cheak_dead(t_list **dead) {
    t_list *temp = *dead;
    int index = 0;
    while (temp) {
        temp->object.hp++;
        if(temp->object.hp >= 60) {
            mx_pop_index(dead, index);
            return;
        }
        temp = temp->next;
        index++;
    }

}


void mx_swap_boom_texture_for_dead(t_list *dead) {
    SDL_Texture *temp_texture = NULL;
    t_list *temp = dead;
    while (temp) {
        temp_texture = mx_boom_texture(temp->object.hp);
        temp->object.texture = temp_texture;
        temp = temp->next;
    }
}
