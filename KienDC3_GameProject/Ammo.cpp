#include"Ammo.h"

void Ammo::setAmmoRect(int x, int y)
{
    ammo_rect.x=x;
    ammo_rect.y=y;
}
void Ammo::loadAmmoImg(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer,ammo_object,NULL,&ammo_rect);
}
void Ammo::bullet_travel(int type)
{
     int step=30;
     int enemy_step=10;
        if(type==1)
            ammo_rect.x+=step;
        else
            ammo_rect.x-=enemy_step;
}
void Ammo::setting_ammo(int type,SDL_Renderer* renderer)
{
    //character
    if(type == 1)
    {
        ammo_object=loadTexture("img/torpedo_black.png",renderer,false);
        SDL_QueryTexture(ammo_object, NULL,NULL,&ammo_rect.w,&ammo_rect.h);
        ammo_rect.w /= 8;
        ammo_rect.h /= 10;
    }
    //enemy
    if(type == 2)
    {
        ammo_object=loadTexture("img/torpedo.png",renderer,false);
        SDL_QueryTexture(ammo_object, NULL,NULL,&ammo_rect.w,&ammo_rect.h);
        ammo_rect.w /= 8;
        ammo_rect.h /= 10;
    }
}
