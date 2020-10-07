#include "../inc/header.h"
void mx_create_enemy_bullets(t_list **bullets,t_list *enemies) {
    t_list *temp = enemies;
    while (temp) {
        if (temp->object.option == -351 || temp->object.y < 30) {
            temp = temp->next;
            continue;
        }
        t_object bullet1;
        t_object bullet2;
        bullet1.time = 0;
        bullet1.hp = 1;
        bullet1.option = 2;
        bullet1.x = temp->object.x + 41;
        bullet1.y = temp->object.y + 90;
        bullet1.texture = enemy_bullets;

        bullet2.time = 0;
        bullet2.hp = 1;
        bullet2.option = 2;
        bullet2.x = temp->object.x + 98;
        bullet2.y = temp->object.y + 90;
        bullet2.texture = enemy_bullets;
        if (!bullets) {
            mx_create_node(&bullet1);
            mx_push_back(bullets, &bullet1);
        }
        else {
            mx_push_back(bullets, &bullet1);
            mx_push_back(bullets, &bullet2);
        }
        temp = temp->next;
    }
    
}
void mx_draw_bullets(t_list *list) {
    t_list *temp = list;
    for (int i = 0; i < mx_list_size(list); i++)
    {
        mx_draw_object(&temp->object);
        if (temp->object.option == 1)
            temp->object.y -= 10;
        else
            temp->object.y += 10;
        temp = temp->next;
    }
}
void mx_remove_bullets(t_list **bullet, t_object *asteroid) {
    if (*bullet == NULL || bullet == NULL)
        return;
    t_list *temp = *bullet;
    if (temp->object.y < -10 && temp->object.option == 1)
        mx_pop_front(bullet);
    if (temp->object.y > (HIGHT + 200) && temp->object.option == 2)
        mx_pop_front(bullet);
    for (int i = 0; temp; i++) {
        if (mx_collision_object(asteroid, &temp->object)) {
            mx_pop_index(bullet, i);
            break;
        }
        temp = temp->next;
    }
}


void mx_bullet_mechanic(t_object *player, t_list **bullets) {
    t_object bullet1;
    t_object bullet2;
    bullet1.x = player->x + 2;
    bullet1.y = player->y - 15;
    bullet1.texture = bullet_texture;
    bullet1.hp = 1;
    bullet1.option = 1;
    bullet2.x = player->x + 126;
    bullet2.y = player->y - 15;
    bullet2.texture = bullet_texture;
    bullet2.hp = 1;
    bullet2.option = 1;
    if (*bullets == NULL) {
        *bullets = mx_create_node(&bullet1);
        mx_push_back(bullets, &bullet2);
    }
    else {
        mx_push_back(bullets, &bullet1);
        mx_push_back(bullets, &bullet2);
    }
    return;
}
