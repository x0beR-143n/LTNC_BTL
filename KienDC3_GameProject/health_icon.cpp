#include"health_icon.h"
void heart_icon::setHealthRegenerate(SDL_Renderer* renderer)
{
    health_regen=loadTexture("img/health_regenerate.png",renderer,false);
    SDL_QueryTexture(health_regen,NULL,NULL,&health_icon.w,&health_icon.h);
    health_icon.w /=3;
    health_icon.h /=3;
    health_icon.x=SCREEN_WIDTH-100;
    health_icon.y=randomNumber();
    for(int i=0; i<50;i++)
    {
        if(i==19 || i==47 )
            appearance_rate[i]=true;
        else
            appearance_rate[i]=false;
    }
}
void heart_icon::loadHealthRegen(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,health_regen,NULL,&health_icon);
}
void heart_icon::icon_move(int type)
{
    if(is_appear)
    {
        //type =1 => heart
        if(type==1)
            health_icon.x -= 3;
        //type=2 => bomb
        if(type==2)
            health_icon.x -=8;
        if(health_icon.x <0)
        {
            is_appear=false;
        }
    }
}
bool heart_icon::check_collide(mainCharacter character)
{
    if(!is_appear)
    {
        return false;
    }
    if(health_icon.x <= character.rect.x + character.rect.w && health_icon.x >= character.rect.x)
    {
        if(health_icon.y >= character.rect.y && health_icon.y <= character.rect.y + character.rect.h)
        {
            return true;
        }
        if(character.rect.y >= health_icon.y && character.rect.y <= health_icon.y + health_icon.h)
        {
            return true;
        }
    }
    return false;
}
bool heart_icon::check_appear(int state)
{
    if(is_appear)
    {
        return false;
    }
    if(state >=3)
    {
        if(appearance_rate[randomIndex_heartIcon()]  && appearance_rate[randomIndex_heartIcon()] )
        {
            return true;
        }
    }
    return false;
}
void heart_icon::setBomb(SDL_Renderer* renderer)
{
    health_regen=loadTexture("img/bomb.png",renderer,false);
    SDL_QueryTexture(health_regen,NULL,NULL,&health_icon.w,&health_icon.h);
    health_icon.w/=15;
    health_icon.h/=15;
    health_icon.x=SCREEN_WIDTH-100;
    health_icon.y=randomNumber();
    for(int i=0; i<50;i++)
    {
        if(i==19 || i==23)
        {
            appearance_rate[i]=true;
        }
        else
        {
            appearance_rate[i]=false;
        }
    }
}
void heart_icon::loadBomb(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,health_regen,NULL,&health_icon);
}
bool heart_icon::check_appearBomb()
{
    if(is_appear)
    {
        return false;
    }
    if(appearance_rate[randomIndex_heartIcon()]  && appearance_rate[randomIndex_heartIcon()] )
    {
        return true;
    }
    return false;
}
