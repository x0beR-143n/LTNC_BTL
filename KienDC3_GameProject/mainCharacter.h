#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include"function.h"
#include"Ammo.h"

class mainCharacter{
public:
    SDL_Texture* object;
    SDL_Rect rect;
    vector<Ammo> vec;
    bool is_alive=true;
    bool move_right=false;
    bool move_left=false;
    bool move_up=false;
    bool move_down=false;
    int count_right=0;
    int count_left=0;
    int count_up=0;
    int count_down=0;
    void setRectsize(int x1, int y1);
    void loadImg(SDL_Renderer* renderer);
    void handleInput(SDL_Event e,int up, int down, int right, int left);
    void moving();
    void handleFire(SDL_Event event,int x,int y,SDL_Renderer* renderer, int shoot);
    void set_character_default(SDL_Renderer* renderer,int type);
};

#endif
