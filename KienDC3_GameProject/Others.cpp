#include "Others.h"

void Surrounding::setBackground(SDL_Renderer* renderer)
{
    for(int i=0; i<2; i++)
    {
        background[i]=loadTexture("img/background1.webp",renderer,false);
        SDL_QueryTexture(background[i],NULL,NULL,&bg_rect[i].w, &bg_rect[i].h);
        bg_rect[i].y=0;
        bg_rect[i].w=SCREEN_WIDTH;
        bg_rect[i].h=SCREEN_HEIGHT;
    }
    bg_rect[0].x=0;
    bg_rect[1].x=SCREEN_WIDTH;
}
void Surrounding::setExplosion(SDL_Renderer* renderer)
{
    explosion = loadTexture("img/explosion_03.png",renderer,false);
    SDL_QueryTexture(explosion,NULL,NULL,&explo_rect.w,&explo_rect.h);
    explo_rect.w /= 3;
    explo_rect.h /= 3;
}
void Surrounding::setexplosion_character(SDL_Renderer* renderer)
{
    main_character_explosion= loadTexture("img/explosion_04.png",renderer,false);
    SDL_QueryTexture(main_character_explosion,NULL,NULL,&main_character_rect_explosion.w,&main_character_rect_explosion.h);
    main_character_rect_explosion.w /= 3;
    main_character_rect_explosion.h /= 3;
}
void Surrounding::set_healthbar(SDL_Renderer* renderer)
{
    hp=loadTexture("img/hp.png",renderer,false);
    SDL_QueryTexture(hp,NULL,NULL,&hp_rect.w,&hp_rect.h);
    hp_rect.w /= 2;
    hp_rect.h /= 2;
    hp_rect.x = 20;
    hp_rect.y = 20;

    base_hp= loadTexture("img/base_hp.png",renderer,false);
    SDL_QueryTexture(base_hp,NULL,NULL,&base_hp_rect.w,&base_hp_rect.h);
    base_hp_rect.w /= 2;
    base_hp_rect.h /= 2;
    base_hp_rect.x = 20;
    base_hp_rect.y = 60;

    health_bar[0]=loadTexture("img/full_health.png",renderer,false);
    health_bar[1]=loadTexture("img/75per_health.png",renderer,false);
    health_bar[2]=loadTexture("img/half_health.png",renderer,false);
    health_bar[3]=loadTexture("img/25per_health.png",renderer,false);
    health_bar[4]=loadTexture("img/last_chance.png",renderer,false);
    health_bar[5]=loadTexture("img/no_health.png",renderer,false);

    base_health[0]=loadTexture("img/full_base_health.png",renderer,false);
    base_health[1]=loadTexture("img/75per_base_health.png",renderer,false);
    base_health[2]=loadTexture("img/half_base_health.png",renderer,false);
    base_health[3]=loadTexture("img/25per_base_health.png",renderer,false);
    base_health[4]=loadTexture("img/last_base_chance.png",renderer,false);
    base_health[5]=loadTexture("img/no_health.png",renderer,false);
    for(int i=0; i<6;i++)
    {
        SDL_QueryTexture(health_bar[i],NULL,NULL,&health_rect[i].w,&health_rect[i].h);
        SDL_QueryTexture(base_health[i],NULL,NULL,&base_rect[i].w,&base_rect[i].h);
        health_rect[i].w /= 3;
        health_rect[i].h /= 3;
        if(i==0)
        {
        base_rect[i].w =  base_rect[i].w /3 + 5;
        base_rect[i].h =  base_rect[i].h /3 + 3;
        }
        else
        {
            base_rect[i].w /=3 ;
            base_rect[i].h /=3 ;
        }
        health_rect[i].x=150;
        health_rect[i].y=20;
        base_rect[i].x = 150;
        base_rect[i].y = 65;
    }
}
void Surrounding::setgameover_img(SDL_Renderer* renderer)
{
    game_over=loadTexture("img/end_game_1.png",renderer,false);
    SDL_QueryTexture(game_over,NULL,NULL,&gameover_rect.w,&gameover_rect.h);
    gameover_rect.x=SCREEN_WIDTH/4;
    gameover_rect.y=SCREEN_HEIGHT/7;
    gameover_rect.w =gameover_rect.w/2 + 200;
    gameover_rect.h =gameover_rect.h/2 + 200;
    back_to_menu=loadTexture("img/back_to_menu.png",renderer,false);
    SDL_QueryTexture(back_to_menu,NULL,NULL,&back_to_menu_rect.w,&back_to_menu_rect.h);
    back_to_menu_rect.x= gameover_rect.x+100;
    back_to_menu_rect.y= gameover_rect.y+300;
    back_to_menu_rect.w/=2;
    back_to_menu_rect.h/=2;
    play_again=loadTexture("img/play_again.png",renderer,false);
    SDL_QueryTexture(play_again,NULL,NULL,&play_again_rect.w,&play_again_rect.h);
    play_again_rect.x=gameover_rect.x+330;
    play_again_rect.y=gameover_rect.y+300;
    play_again_rect.w /=2;
    play_again_rect.h/=2;

}
void Surrounding::set_healthBar_boss(SDL_Renderer* renderer)
{
    health_bar[0]=loadTexture("img/full_health.png",renderer,false);
    health_bar[1]=loadTexture("img/75per_health.png",renderer,false);
    health_bar[2]=loadTexture("img/half_health.png",renderer,false);
    health_bar[3]=loadTexture("img/25per_health.png",renderer,false);
    health_bar[4]=loadTexture("img/last_chance.png",renderer,false);
    health_bar[5]=loadTexture("img/no_health.png",renderer,false);

    for(int i=0; i<6;i++)
    {
        SDL_QueryTexture(health_bar[i],NULL,NULL,&health_rect[i].w,&health_rect[i].h);
        health_rect[i].w /= 3;
        health_rect[i].h /= 3;
    }
}
void Surrounding::loadExplosion(SDL_Renderer* renderer,int x,int y)
{
    explo_rect.x=x;
    explo_rect.y=y;
    SDL_RenderCopy(renderer,explosion,NULL,&explo_rect);
}
void Surrounding::loadBackground(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,background[0],NULL,&bg_rect[0]);
    SDL_RenderCopy(renderer,background[1],NULL,&bg_rect[1]);
    bg_rect[0].x -= 1;
    bg_rect[1].x -= 1;
    for(int i=0; i<2; i++)
    {
        if(bg_rect[i].x + bg_rect[i].w <=0)
        {
            bg_rect[i].x=SCREEN_WIDTH;
        }
    }
}
void Surrounding::loadExplosion_maincharacter(SDL_Renderer* renderer,int x,int y)
{
    main_character_rect_explosion.x=x;
    main_character_rect_explosion.y=y;
    SDL_RenderCopy(renderer,main_character_explosion,NULL,&main_character_rect_explosion);
}
void Surrounding::loadHealthbar(SDL_Renderer* renderer,int state)
{
    SDL_RenderCopy(renderer,health_bar[state],NULL,&health_rect[state]);
    SDL_RenderCopy(renderer,hp,NULL,&hp_rect);
}
void Surrounding::loadBaseHealth(SDL_Renderer* renderer, int state)
{
    SDL_RenderCopy(renderer,base_health[state],NULL,&base_rect[state]);
    SDL_RenderCopy(renderer,base_hp,NULL,&base_hp_rect);
}
void Surrounding::loadGameover(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,game_over,NULL,&gameover_rect);
    SDL_RenderCopy(renderer,play_again,NULL,&play_again_rect);
    SDL_RenderCopy(renderer,back_to_menu,NULL,&back_to_menu_rect);
}
void Surrounding::load_healthBar_boss(SDL_Renderer* renderer,int x, int y, int boss_state)
{
    health_rect[boss_state].x=x;
    health_rect[boss_state].y=y;
    SDL_RenderCopy(renderer,health_bar[boss_state],NULL,&health_rect[boss_state]);
}
