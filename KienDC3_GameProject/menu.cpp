#include "menu.h"
void the_menu::setMenu(SDL_Renderer* renderer)
{
    title=loadTexture("img/title_menu.png",renderer,false);
    SDL_QueryTexture(title,NULL,NULL,&title_rect.w,&title_rect.h);
    title_rect.x=SCREEN_WIDTH/6;
    title_rect.y= -150;
    title_rect.w = title_rect.w/2 +200;
    title_rect.h = title_rect.h/2 +200;
    play=loadTexture("img/play_menu.png",renderer,false);
    SDL_QueryTexture(play,NULL,NULL,&play_rect.w,&play_rect.h);
    play_rect.x=title_rect.x + 350;
    play_rect.y=title_rect.y + 380;
    play_rect.w/=2;
    play_rect.h/=2;

    setting=loadTexture("img/setting_menu.png",renderer,false);
    SDL_QueryTexture(setting,NULL,NULL,&setting_rect.w,&setting_rect.h);
    setting_rect.x=title_rect.x + 350;
    setting_rect.y=title_rect.y + 500;
    setting_rect.w/=2;
    setting_rect.h/=2;

    setting_menu=loadTexture("img/setting_details.png",renderer,false);
    SDL_QueryTexture(setting_menu,NULL,NULL,&setting_menu_rect.w, &setting_menu_rect.h);
    setting_menu_rect.x=100;
    setting_menu_rect.y=10;
    setting_menu_rect.w= 800;
    setting_menu_rect.h= 600;

    guide=loadTexture("img/guide.png",renderer,false);
    SDL_QueryTexture(guide,NULL,NULL,&guide_rect.w, &guide_rect.h);
    guide_rect.x=600;
    guide_rect.y=50;
    guide_rect.w = 600;
    guide_rect.h = 350;

    for(int i=0; i<5; i++)
    {
        change[i] = loadTexture("img/change.png",renderer,false);
        SDL_QueryTexture(change[i],NULL,NULL,&change_rect[i].w,&change_rect[i].h);
        change_rect[i].w /= 2;
        change_rect[i].h /= 2;
        change_rect[i].x = 400;
    }
    change_rect[0].y= 20;
    for(int i=1; i<5; i++)
    {
        change_rect[i].y=change_rect[i-1].y+75;
    }

    quit=loadTexture("img/quit_menu.png",renderer,false);
    SDL_QueryTexture(quit,NULL,NULL,&quit_rect.w,&quit_rect.h);
    quit_rect.x=title_rect.x + 350;
    quit_rect.y=title_rect.y + 620;
    quit_rect.w/=2;
    quit_rect.h/=2;

    pause = loadTexture("img/pause.png",renderer,false);
    SDL_QueryTexture(pause,NULL,NULL,&pause_rect.w, &pause_rect.h);
    pause_rect.w /= 4;
    pause_rect.h /= 4;
    pause_rect.x = SCREEN_WIDTH-10-pause_rect.w;
    pause_rect.y = 10;

    pause_menu = loadTexture("img/quit_confirm.png",renderer,false);
    SDL_QueryTexture(pause,NULL,NULL,&pause_menu_rect.w, &pause_menu_rect.h);
    pause_menu_rect.w *= 2;
    pause_menu_rect.h *= 2;
    pause_menu_rect.x = SCREEN_WIDTH/2 - 230;
    pause_menu_rect.y = SCREEN_HEIGHT/2 -200;

    yes= loadTexture("img/yes.png",renderer,false);
    SDL_QueryTexture(yes,NULL,NULL,&yes_rect.w,&yes_rect.h);
    yes_rect.w /= 2;
    yes_rect.h /= 2;
    yes_rect.x = pause_menu_rect.x + 60;
    yes_rect.y = pause_menu_rect.y + 200;

    no= loadTexture("img/no.png",renderer,false);
    SDL_QueryTexture(no,NULL,NULL,&no_rect.w,&no_rect.h);
    no_rect.w /= 2;
    no_rect.h /= 2;
    no_rect.x = pause_menu_rect.x + 260;
    no_rect.y = pause_menu_rect.y + 200;

    back_button=loadTexture("img/back.png",renderer,false);
    SDL_QueryTexture(back_button,NULL,NULL,&back_button_rect.w,&back_button_rect.h);
    back_button_rect.x=25;
    back_button_rect.y=25;
    back_button_rect.w/=2;
    back_button_rect.h/=2;

    music_op[0]=loadTexture("img/selection_yes.png",renderer,false);
    music_op[2]=loadTexture("img/selection_yes.png",renderer,false);
    music_op[1]=loadTexture("img/selection_no.png",renderer,false);
    music_op[3]=loadTexture("img/selection_no.png",renderer,false);
    for(int i=0; i<4; i++)
    {
        SDL_QueryTexture(music_op[i],NULL,NULL,&music_rect[i].w,&music_rect[i].h);
        music_rect[i].w/=2;
        music_rect[i].h/=2;
    }
    music_rect[0].x=210;
    music_rect[0].y=450;
    music_rect[1].x=300;
    music_rect[1].y=music_rect[0].y;
    music_rect[2].x=music_rect[0].x;
    music_rect[2].y=530;
    music_rect[3].x=music_rect[1].x;
    music_rect[3].y=music_rect[2].y;

    setting_page2_title=loadTexture("img/setting_page2_title.png",renderer,false);
    SDL_QueryTexture(setting_page2_title,NULL,NULL,&setting_page2_title_rect.w,&setting_page2_title_rect.h);
    setting_page2_title_rect.x=240;
    setting_page2_title_rect.y=50;

    next_page=loadTexture("img/nextpage_setting.png",renderer,false);
    SDL_QueryTexture( next_page,NULL,NULL,&next_page_rect.w,&next_page_rect.h);
    next_page_rect.x=SCREEN_WIDTH-200;
    next_page_rect.y=SCREEN_HEIGHT-180;
    next_page_rect.w/=3;
    next_page_rect.h/=3;

    prev_page=loadTexture("img/prevpage_setting.png",renderer,false);
    SDL_QueryTexture(prev_page,NULL,NULL,&prev_page_rect.w,&prev_page_rect.h);
    prev_page_rect.x=100;
    prev_page_rect.y=next_page_rect.y;
    prev_page_rect.w/=3;
    prev_page_rect.h/=3;

    prev_plane=loadTexture("img/prev_plane.png",renderer,false);
    SDL_QueryTexture(prev_plane,NULL,NULL,&prev_plane_rect.w,&prev_plane_rect.h);
    prev_plane_rect.x=250;
    prev_plane_rect.y=320;
    prev_plane_rect.w/=2;
    prev_plane_rect.h/=2;

    next_plane=loadTexture("img/next_plane.png",renderer,false);
    SDL_QueryTexture(next_plane,NULL,NULL,&next_plane_rect.w,&next_plane_rect.h);
    next_plane_rect.x=950;
    next_plane_rect.y=320;
    next_plane_rect.w/=2;
    next_plane_rect.h/=2;

    menu_music= Mix_LoadMUS("music/background_music2.mp3");
    if(menu_music == NULL)
    {
        printf("%s", Mix_GetError());
    }
    is_in_menu=true;
}
void the_menu::loadMenu(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,title,NULL,&title_rect);
    SDL_RenderCopy(renderer,play,NULL,&play_rect);
    SDL_RenderCopy(renderer,setting,NULL,&setting_rect);
    SDL_RenderCopy(renderer,quit,NULL,&quit_rect);
}
void the_menu::load_Pause(SDL_Renderer* renderer)
{
 SDL_RenderCopy(renderer,pause,NULL,&pause_rect);
}
void the_menu::load_pause_menu(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,pause_menu,NULL,&pause_menu_rect);
    SDL_RenderCopy(renderer,yes,NULL,&yes_rect);
    SDL_RenderCopy(renderer,no,NULL,&no_rect);
}
void the_menu::load_setting_menu(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,setting_menu,NULL,&setting_menu_rect);
    SDL_RenderCopy(renderer,guide,NULL,&guide_rect);
    for(int i=0; i<5; i++)
    {
        SDL_RenderCopy(renderer,change[i],NULL,&change_rect[i]);
    }
    SDL_RenderCopy(renderer,back_button,NULL,&back_button_rect);
    SDL_RenderCopy(renderer,next_page,NULL,&next_page_rect);
    for(int i=0; i<4; i++)
    {
        SDL_RenderCopy(renderer,music_op[i],NULL,&music_rect[i]);
    }
}
void the_menu::load_setting_page2(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,setting_page2_title,NULL,&setting_page2_title_rect);
    SDL_RenderCopy(renderer,next_plane,NULL,&next_plane_rect);
    SDL_RenderCopy(renderer,prev_plane,NULL,&prev_plane_rect);
    SDL_RenderCopy(renderer,prev_page,NULL,&prev_page_rect);
}
