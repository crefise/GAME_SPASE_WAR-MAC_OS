#include "../inc/header.h"

t_list *mx_create_node(t_object *copy_object) {
    if (!copy_object)
        return NULL;
    t_list *my_node = (t_list*)malloc(sizeof(t_list));
    if (!my_node)
        return NULL;
    my_node->object.x = copy_object->x;
    my_node->object.y = copy_object->y;
    my_node->object.hp = copy_object->hp;
    my_node->object.option = copy_object->option;
    my_node->object.texture = copy_object->texture;
    my_node->next = NULL;
    return my_node;
}
void mx_push_back(t_list **list, t_object *object) {
    if (!object)
        return;
    t_list *back = mx_create_node(object);
    t_list *temp = *list;
    if (*list == NULL || list == NULL) {
        *list = back;
        return;
    }
    while (temp->next != NULL) {
       temp = temp->next;
    }
    temp->next = back;
}
void mx_pop_front(t_list **head) 
{
    t_list *temp = NULL;
    if (head == NULL || *head == NULL)
        return;
    
    if ((*head)->next == NULL) 
    {

        free(*head);
        *head = NULL;
    } 
    else 
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}
int mx_list_size(t_list *list) {
    if (list == NULL)
        return 0;
    int size = 0;
    t_list *temp = list;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}
void mx_pop_back(t_list **list) {
    t_list *temp = *list;
    if (temp == NULL) {
        return;
    } else if (temp->next == NULL) {
        free(temp);
        *list = NULL;
    } else {
        while (temp->next->next) temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}

void mx_pop_index(t_list **list, int index) {
    if(list == NULL || *list == NULL) {
        return;
    }
    t_list *temp = *list;
    t_list *temp2 = NULL;
    if (index <= 0) {
        mx_pop_front(list);
        return;
    }
    for (int i = 0; i < index; i++) {
        if (temp == NULL || temp->next == NULL) {
            mx_pop_back(list);
            return;
        }
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    free(temp);
    temp = NULL;
}
