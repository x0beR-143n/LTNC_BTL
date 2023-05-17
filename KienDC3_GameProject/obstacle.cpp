#include"obstacle.h"

 void obstacle::setRectsize(int x1, int y1)
 {
    obs_rect.x=x1;
    obs_rect.y=y1;
 }
 void obstacle::load_obsImg(SDL_Renderer* renderer)
 {
    SDL_RenderCopy(renderer,obs_object,NULL,&obs_rect);
 }
void obstacle::obs_move(int &state, int step)
 {
     //int step=4;
     obs_rect.x -= step;
        if(obs_rect.x < 0-obs_rect.w)
            {
                obs_rect.x=SCREEN_WIDTH;
                obs_rect.y=randomNumber();
                state++;
            }
 }
 void obstacle::respawn()
{
        respawn_time++;
        if(respawn_time==70)
        {
            obs_is_fired=false;
            respawn_time=0;
            obs_rect.y = randomNumber();
        }
}
void obstacle::set_Enemy_default(SDL_Renderer* renderer)
{
    obs_object=loadTexture("img/enemy.png",renderer,true);
    SDL_QueryTexture(obs_object,NULL,NULL,&obs_rect.w,&obs_rect.h);
    obs_rect.w /= 2;
    obs_rect.h /= 2;
    torpedo.is_fired=true;
    torpedo.setAmmoRect(obs_rect.x-20,obs_rect.y+55);
    torpedo.setting_ammo(2,renderer);
}
bool obstacle::check_character_enemy_collision(mainCharacter character)
{
    if(obs_is_fired || !obs_is_move)
    {
        return false;
    }
    if((character.rect.x+character.rect.w >= obs_rect.x && character.rect.x <= obs_rect.x) || obs_rect.x <= character.rect.x && obs_rect.x+obs_rect.w >= character.rect.x)
    {
        if(character.rect.y >= obs_rect.y && character.rect.y <= obs_rect.y + obs_rect.h)
        {
            return true;
        }
        if(obs_rect.y >=character.rect.y && obs_rect.y <= character.rect.y + character.rect.h)
        {
            return true;
        }
    }
    return false;
}
bool obstacle::check_character_enemybullet_Colision(mainCharacter character)
{
    if(!torpedo.is_fired )
    {
        return false;
    }
    if(torpedo.ammo_rect.x <= character.rect.x + character.rect.w && torpedo.ammo_rect.x >= character.rect.x)
    {
        if(torpedo.ammo_rect.y >= character.rect.y && torpedo.ammo_rect.y <= character.rect.y + character.rect.h )
        {
            return true;
        }
    }
    return false;
}
bool obstacle::check_characterbullet_enemy_Colision(Ammo bullet)
{
    if(!obs_is_move || obs_is_fired)
    {
        return false;
    }
    if(bullet.ammo_rect.x + bullet.ammo_rect.w >= obs_rect.x && bullet.ammo_rect.x+bullet.ammo_rect.w <= obs_rect.x + obs_rect.w)
    {
        if(bullet.ammo_rect.y >= obs_rect.y && bullet.ammo_rect.y <= obs_rect.y + obs_rect.h)
        {
            return true;
        }
    }
    return false;
}
void obstacle::set_Boss_enemy(SDL_Renderer* renderer)
{
    obs_object=loadTexture("img/special_enemy.png",renderer,false);
    SDL_QueryTexture(obs_object,NULL,NULL,&obs_rect.w,&obs_rect.h);
    obs_rect.w /= 4;
    obs_rect.h /= 4;
    obs_rect.x=SCREEN_WIDTH-100;
    obs_rect.y=SCREEN_HEIGHT/3;
    torpedo.setAmmoRect(obs_rect.x-80,obs_rect.y+80);
    torpedo.setting_ammo(2,renderer);
    torpedo.ammo_rect.w *=2;
    torpedo.ammo_rect.h *=2;
    obs_is_move=false;
}
void obstacle::load_Boss_enemy(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,obs_object,NULL,&obs_rect);
}
void obstacle::boss_move(int &up_or_down)
{
            if(up_or_down == 1)
            {
                limit_down = random(50, 150);
                up_or_down=3;
                move_down=true;
            }
            if(move_down)
            {
                obs_rect.y += 2;
                if( obs_rect.y+ obs_rect.h > SCREEN_HEIGHT-100)
                {
                    count_down=0;
                    up_or_down=2;
                    move_down=false;
                }
                count_down++;
                if(count_down == limit_down)
                {
                    count_down=0;
                    up_or_down=2;
                    move_down=false;
                }
            }
            if(up_or_down == 2)
            {
                move_up=true;
                limit_up = random(50,250);
                up_or_down=3;
            }
            if(move_up)
            {
                 obs_rect.y -= 2;
                if( obs_rect.y < 100)
                {
                    count_up=0;
                    up_or_down=1;
                    move_up=false;
                }
                count_up++;
                if(count_up == 100)
                {
                    count_up=0;
                    up_or_down=1;
                    move_up=false;
                }
            }
}
