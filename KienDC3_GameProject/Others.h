#ifndef OTHERS_H_
#define OTHERS_H_

#include "function.h"
class Surrounding{
public:
    SDL_Texture* background[2];
    SDL_Rect bg_rect[2];
    SDL_Texture* explosion;
    SDL_Texture* main_character_explosion;
    SDL_Texture* health_bar[6];
    SDL_Texture* base_health[6];
    SDL_Texture* game_over;
    SDL_Texture* play_again;
    SDL_Texture* back_to_menu;
    SDL_Texture* hp;
    SDL_Texture* base_hp;
    SDL_Rect explo_rect;
    SDL_Rect main_character_rect_explosion;
    SDL_Rect health_rect[6];
    SDL_Rect base_rect[6];
    SDL_Rect gameover_rect;
    SDL_Rect play_again_rect;
    SDL_Rect back_to_menu_rect;
    SDL_Rect hp_rect;
    SDL_Rect base_hp_rect;
    bool end_game=false;
    void setBackground(SDL_Renderer* renderer);
    void setExplosion(SDL_Renderer* renderer);
    void setexplosion_character(SDL_Renderer* renderer);
    void set_healthbar(SDL_Renderer* renderer);
    void setgameover_img(SDL_Renderer* renderer);
    void loadExplosion_maincharacter(SDL_Renderer* renderer, int x, int y);
    void loadExplosion(SDL_Renderer* renderer,int x, int y);
    void loadBackground(SDL_Renderer* renderer);
    void loadHealthbar(SDL_Renderer* renderer,int state);
    void loadBaseHealth(SDL_Renderer* renderer, int state);
    void loadGameover(SDL_Renderer* renderer);
    void set_healthBar_boss(SDL_Renderer* renderer);
    void load_healthBar_boss(SDL_Renderer* renderer,int x, int y, int boss_state);
};

#endif // OTHERS_H_
