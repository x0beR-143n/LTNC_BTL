#ifndef AMMO_H_
#define AMMO_H_

#include "function.h"

class Ammo{
    public:
    SDL_Texture* ammo_object;
    SDL_Rect ammo_rect;
    const int character_ammo = 1;
    const int enemy_ammo=2;
    bool is_fired=false;
    void setAmmoRect(int x, int y);
    void loadAmmoImg(SDL_Renderer* renderer);
    void bullet_travel(int type);
    void setting_ammo(int type,SDL_Renderer* renderer);
};

#endif
