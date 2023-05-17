#include"mainCharacter.h"

void mainCharacter::setRectsize(int x1, int y1)
{
    rect.x=x1;
    rect.y=y1;
}
void mainCharacter::loadImg(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,object,NULL,&rect);
}
void mainCharacter::handleInput(SDL_Event e,const int up,const int down,const int right,const int left)
{
        if(e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym == up)
                {
                    move_up=true;
                }
                if(e.key.keysym.sym == down)
                {
                    move_down=true;
                }
                if(e.key.keysym.sym == right)
                {
                    move_right=true;
                }
                if(e.key.keysym.sym == left)
                {
                    move_left=true;
                }
            }
}
void mainCharacter::moving()
{
    int step=5;
    int limit=15;
            if(move_right && rect.x+rect.w+step < SCREEN_WIDTH)
            {
                rect.x += step;
                count_right++;
                if(count_right == limit)
                {
                    count_right=0;
                    move_right=false;
                }
            }
            if(move_left && rect.x-step > 0)
            {
                rect.x -= step;
                count_left++;
                if(count_left == limit)
                {
                    count_left=0;
                    move_left=false;
                }
            }
            if(move_up && rect.y-step > 0)
            {
                rect.y -= (step+1);
                count_up++;
                if(count_up==limit)
                {
                    count_up=0;
                    move_up=false;
                }
            }
            if(move_down && rect.y+rect.h+step < SCREEN_HEIGHT-100)
            {
                rect.y += (step+1);
                count_down++;
                if(count_down ==limit)
                {
                    count_down=0;
                    move_down=false;
                }
            }

}
void mainCharacter::handleFire(SDL_Event event,int x,int y,SDL_Renderer* renderer,int shoot)
{
     if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == shoot)
            {
                Ammo fire;
                fire.setAmmoRect(x,y);
                fire.setting_ammo(1,renderer)   ;
                fire.is_fired=true;
                vec.push_back(fire);
            }
        }
}
void mainCharacter::set_character_default(SDL_Renderer* renderer,int type)
 {
    if(type==0)
    {
        object=loadTexture("img/plane_2_yellow.png",renderer,false);
    }
    if(type==1)
    {
        object=loadTexture("img/plane_2_blue.png",renderer,false);
    }
    if(type==2)
    {
        object=loadTexture("img/plane_2_green.png",renderer,false);
    }
    if(type==3)
    {
        object=loadTexture("img/plane_2_red.png",renderer,false);
    }
    SDL_QueryTexture(object, NULL,NULL,&rect.w,&rect.h);
    rect.w /= 8;
    rect.h /= 8;
 }
