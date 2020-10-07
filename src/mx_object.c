#include "../inc/header.h"

void mx_draw_object(t_object *object) {
    mx_ApplySurface(object->x,object->y,object->texture, render);
}

bool mx_collision_object(t_object *obj1, t_object *obj2) {
    SDL_Rect obj1_info;
    SDL_Rect obj2_info;
    SDL_QueryTexture(obj1->texture, NULL, NULL, &obj1_info.w, &obj1_info.h);
    SDL_QueryTexture(obj2->texture, NULL, NULL, &obj2_info.w, &obj2_info.h);
    int obj2_point1_x = obj2->x;
    int obj2_point1_y = obj2->y;
    int obj2_point2_x = obj2->x + obj2_info.w;
    int obj2_point2_y = obj2->y;
    int obj2_point3_x = obj2->x + obj2_info.w;
    int obj2_point3_y = obj2->y + obj2_info.h;
    int obj2_point4_x = obj2->x;
    int obj2_point4_y = obj2->y + obj2_info.h;
    int obj2_point5_x = obj2->x;
    int obj2_point5_y = obj2->y + obj2_info.h/2;
    int obj2_point6_x = obj2->x + obj2_info.w;
    int obj2_point6_y = obj2->y + obj2_info.h/2;
    int obj2_point7_x = obj2->x + obj2_info.w/2;
    int obj2_point7_y = obj2->y;
    int obj2_point8_x = obj2->x + obj2_info.w/2;
    int obj2_point8_y = obj2->y + obj2_info.h;
    
    
    if((obj2_point1_x > obj1->x && obj2_point1_x < obj1->x + obj1_info.w) && (obj2_point1_y > obj1->y && obj2_point1_y < obj1->y + obj1_info.h))
        return true;
    if((obj2_point2_x > obj1->x && obj2_point2_x < obj1->x + obj1_info.w) && (obj2_point2_y > obj1->y && obj2_point2_y < obj1->y + obj1_info.h))
        return true;
    if((obj2_point3_x > obj1->x && obj2_point3_x < obj1->x + obj1_info.w) && (obj2_point3_y > obj1->y && obj2_point3_y < obj1->y + obj1_info.h))
        return true;
    if((obj2_point4_x > obj1->x && obj2_point4_x < obj1->x + obj1_info.w) && (obj2_point4_y > obj1->y && obj2_point4_y < obj1->y + obj1_info.h))
        return true;
    if((obj2_point5_x > obj1->x && obj2_point5_x < obj1->x + obj1_info.w) && (obj2_point5_y > obj1->y && obj2_point5_y < obj1->y + obj1_info.h))
        return true;
    if((obj2_point6_x > obj1->x && obj2_point6_x < obj1->x + obj1_info.w) && (obj2_point6_y > obj1->y && obj2_point6_y < obj1->y + obj1_info.h))
        return true;
    if((obj2_point7_x > obj1->x && obj2_point7_x < obj1->x + obj1_info.w) && (obj2_point7_y > obj1->y && obj2_point7_y < obj1->y + obj1_info.h))
        return true;
    if((obj2_point8_x > obj1->x && obj2_point8_x < obj1->x + obj1_info.w) && (obj2_point8_y > obj1->y && obj2_point8_y < obj1->y + obj1_info.h))
        return true;
    return false;
}
