#ifndef HEALTH_ICON_H_
#define HEALTH_ICON_H_

#include"function.h"
#include"mainCharacter.h"
class heart_icon{
public:
    SDL_Texture* health_regen;
    SDL_Rect health_icon;
    bool appearance_rate[50];
    bool is_appear=false;
    void setHealthRegenerate(SDL_Renderer* renderer);
    void loadHealthRegen(SDL_Renderer* renderer);
    void icon_move(int type);
    bool check_collide(mainCharacter character);
    bool check_appear(int state);
    void setBomb(SDL_Renderer* renderer);
    void loadBomb(SDL_Renderer* renderer);
    bool check_appearBomb();
};
#endif // HEALTH_ICON_H_
