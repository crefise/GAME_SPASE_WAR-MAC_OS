#include "../inc/header.h"

SDL_Window *window = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *surface_texture = NULL;
SDL_Renderer *render = NULL;
SDL_Texture *background_texture = NULL;
SDL_Texture *player_texture_1 = NULL;
SDL_Texture *player_texture_2 = NULL;
SDL_Texture *asteroid_texture = NULL;
SDL_Texture *bullet_texture = NULL;
SDL_Texture *enemy_texture_easy = NULL;
SDL_Texture *enemy_texture_medium = NULL;
SDL_Texture *enemy_texture_hard = NULL;
SDL_Texture *hp_texture = NULL;
SDL_Texture *BOOM_texture_1 = NULL;
SDL_Texture *BOOM_texture_2 = NULL;
SDL_Texture *BOOM_texture_3 = NULL;
SDL_Texture *BOOM_texture_4 = NULL;
SDL_Texture *BOOM_texture_5 = NULL;
SDL_Texture *BOOM_texture_6 = NULL;
SDL_Texture *button_play = NULL;
SDL_Texture *button_quit = NULL;
SDL_Texture *name_game = NULL;
SDL_Texture *button_shop = NULL;
SDL_Texture *enemy_bullets = NULL;
const int HIGHT = 1300;
const int WIGHT = 1080;
const int FPS = 60;
/////
SDL_Surface *surfaceMessage = NULL;
SDL_Surface *surfaceMessage_1 = NULL;
SDL_Texture* Message = NULL;
SDL_Texture* Message_1 = NULL;
SDL_Surface *pause_2 = NULL;
SDL_Texture* pause_1 = NULL;
SDL_Rect Message_rect;

int main() {
    SDL_Event quit;
    mx_init();
    TTF_Init();
    mx_load_all_textures();
    int mouseX, mouseY; 
    bool exiit = false;
    int start = 0;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music *play_music = Mix_LoadMUS("resource/music/background_mus.ogg");
    Mix_Music *menu_music = Mix_LoadMUS("resource/music/menu_mus.ogg");
    Mix_Chunk *laser_mus = Mix_LoadWAV("resource/music/laser_shoot.wav");
    Mix_Chunk *die_mus = Mix_LoadWAV("resource/music/energ_vzryv.ogg");
    TTF_Font* Sans = TTF_OpenFont("resource/Fonts/Thintel.ttf", 75);
    SDL_Color White = {255, 255, 255, 0};
    surfaceMessage = TTF_RenderText_Solid(Sans, "Score: ", White);
    Message = SDL_CreateTextureFromSurface(render, surfaceMessage);
    pause_2 = TTF_RenderText_Solid(Sans,"P - pause", White);
    pause_1 = SDL_CreateTextureFromSurface(render,pause_2);
    while (!exiit) {
        Mix_PlayMusic(menu_music,-1);
        while (start == 0) {
            if(SDL_PollEvent(&quit) != 0) {
                switch (quit.type)
                {
                    case SDL_QUIT:
                        mx_clear();
                        return 0;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        
                        if(mx_click_play(mouseX, mouseY)) {
                            start = 1;
                            break;
                        }
                        if(mx_click_quit(mouseX, mouseY)){
                         exit(-1);
                        }
                        break;
                }

            }
            SDL_GetMouseState(&mouseX, &mouseY);
            SDL_RenderClear(render);
            mx_background();
            mx_draw_game_name();
            mx_draw_button_play();
            mx_draw_button_quit();
            mx_draw_button_shop();
            SDL_RenderPresent(render);
            if (start == 1) {
                break;
            }

        }
    int speed = 0;
    int i = 0;
    int timer_tick = 0;
    t_object *player = mx_create_player();
    t_object *asteroid = mx_create_asteroid();
    t_object *enemy = NULL;
    t_list *enemies = NULL;
    t_list *dead_enemies = NULL;
    t_list *bullets = NULL;
    int pause = 0;
    int timer_seconds = 0;
    int time_sprite = 0;
    int delay = 0;
    Mix_PlayMusic(play_music,-1);
        while (start == 1) {
            if (player->hp > 0 && SDL_PollEvent(&quit) != 0) {
                if (quit.type == SDL_QUIT) {
                    exit(-1);
                }
                if (quit.type == SDL_KEYDOWN) {
                    switch (quit.key.keysym.sym) { 
                        case SDLK_LEFT:
                            speed = -8;
                            break; 
                        case SDLK_RIGHT:
                            speed = 8;
                            break;
                        case SDLK_SPACE:
                            if (timer_tick - delay < 20) {
                                break;
                            }
                            Mix_PlayChannel(1,laser_mus,0);
                            mx_bullet_mechanic(player, &bullets);
                            delay = timer_tick;
                            break;

                        case SDLK_ESCAPE:
                            if (pause == 0)
                                start = 0;
                            break;
                        case SDLK_p: 
                            pause = 1;
                            break;
                    } 
                }
                if (quit.type == SDL_KEYUP) {
                    switch (quit.key.keysym.sym) {
                        case SDLK_LEFT:
                            speed = 0;
                        case SDLK_RIGHT:
                            speed = 0;
                    }
                }
            }
            if (pause == 1) {
                if (SDL_PollEvent(&quit) != 0) {
                    
                        switch (quit.key.keysym.sym) {
                            case SDLK_p:
                                pause = 0;
                                break; 
                            case SDL_QUIT:
                                mx_clear();
                                return 0;
                                break;
                        }
                    
                }
            }
            
            else if (pause == 0) {
                if (!(player->x + speed < 0) && !(player->x + speed > WIGHT-140)) 
            player->x += speed;
        if (player->hp > 0) {
            if (time_sprite % 2 == 0)
                player->texture = player_texture_1;
            else 
                player->texture = player_texture_2;
        }

        mx_swap_boom_texture_for_dead(dead_enemies);
        
        SDL_RenderClear(render); 
        mx_background();
        mx_draw_object(player);

        mx_asteroid_rain(asteroid); // Запускает астероид


        if (player->help < 100) {
            if (timer_tick % 100 == 0) { // генерация врагов каждую секунду
                enemy = mx_create_easy_enemy(asteroid); 
                if (enemies == NULL)
                    enemies = mx_create_node(enemy);
                else
                    mx_push_back(&enemies, enemy);
            }
        }
        else
            if (player->help < 200) {
                if (timer_tick % 60 == 0) { // генерация врагов каждую секунду
                enemy = mx_create_easy_enemy(asteroid); 
                if (enemies == NULL)
                    enemies = mx_create_node(enemy);
                else
                    mx_push_back(&enemies, enemy);
                }
            }
            else
                if (player->help < 500) {
                    if (timer_tick % 60 == 0) { // генерация врагов каждую секунду
                        enemy = mx_create_easy_enemy(asteroid); 
                        if (enemies == NULL)
                            enemies = mx_create_node(enemy);
                        else
                            mx_push_back(&enemies, enemy);
                        }
                    if (timer_tick % 175 == 0) {
                        enemy = mx_create_meduim_enemy();
                        if (enemies == NULL)
                            enemies = mx_create_node(enemy);
                        else
                            mx_push_back(&enemies, enemy);
                    }
                } 
                else
                    if (player->help >= 500) {
                        if (timer_tick % 30 == 0) { // генерация врагов каждую секунду
                        enemy = mx_create_easy_enemy(asteroid); 
                        if (enemies == NULL)
                            enemies = mx_create_node(enemy);
                        else
                            mx_push_back(&enemies, enemy);
                        }
                        if (timer_tick % 60 == 0) {
                            enemy = mx_create_meduim_enemy();
                            if (enemies == NULL)
                                enemies = mx_create_node(enemy); 
                            else
                                mx_push_back(&enemies, enemy);         
                    }
                }
        mx_draw_enemies(&enemies); // риссует врагов
        mx_draw_enemies(&dead_enemies);//рисует текстуры мертвых врагов
        mx_remove_enemies(&enemies);//удаляет врагов если они вышли за зону
        mx_draw_bullets(bullets); // рисует все пули
        mx_remove_bullets(&bullets, asteroid); //удаляет пули если они попали в астероид либо вышли
        mx_cheak_lose_hp(player,asteroid,&enemies, &dead_enemies); //проверят втаранился ли в нас корабель либо астероид если да, то снимает нам хп и добавляет корабль в ДЕАД
        mx_check_kill_enemy(&enemies,&bullets, &dead_enemies, player);//Если мы убили добавляет корабль в дэад
        mx_cheak_dead(&dead_enemies);// через времья удаляет масив дэад
        if(timer_tick % 100 == 0)
             mx_create_enemy_bullets(&bullets,enemies);
        // DRAW HP PLAYER
        int x = 5;
        for (int i = 0; i < player->hp; i++) {
            mx_draw_hp(x,5);
            x+= 45;
        }
        //bool F = 0;
        if (player->hp <= 0) {
            player->texture = mx_boom_texture(i);
            i++;
            speed = 0;
            if(i==1)
            {
                Mix_PlayChannel(1,die_mus,3);
            }
            if (i > 200) {
                start = 0;
                
                break;
            }
        }
        surfaceMessage_1 = TTF_RenderText_Solid(Sans, mx_score(player->help), White);
        Message_1 = SDL_CreateTextureFromSurface(render, surfaceMessage_1);
        mx_window_write();
        mx_window_write_1();
        mx_draw_pause();
        SDL_RenderPresent(render); 
        SDL_Delay(1000/FPS);
        if (timer_tick % FPS == 0) {
            timer_seconds++;
        }
        timer_tick++;
        if (timer_tick % 10 == 0)
            time_sprite++;
        }
            }
                
        
    }
    mx_clear();
}
