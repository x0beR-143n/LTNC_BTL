#ifndef MENU_H_
#define MENU_H_

#include"function.h"
class the_menu
{
public:
    SDL_Texture* title;
    SDL_Texture* play;
    SDL_Texture* setting;
    SDL_Texture* setting_menu;
    SDL_Texture* guide;
    SDL_Texture* change[5];
    SDL_Texture* quit;
    SDL_Texture* pause;
    SDL_Texture* pause_menu;
    SDL_Texture* yes;
    SDL_Texture* no;
    SDL_Texture* back_button;
    SDL_Texture* music_op[4];

    SDL_Texture* setting_page2_title;
    SDL_Texture* next_page;
    SDL_Texture* prev_page;
    SDL_Texture* next_plane;
    SDL_Texture* prev_plane;
    SDL_Rect setting_page2_title_rect;
    SDL_Rect next_page_rect;
    SDL_Rect prev_page_rect;
    SDL_Rect next_plane_rect;
    SDL_Rect prev_plane_rect;

    SDL_Rect music_rect[4];
    SDL_Rect title_rect;
    SDL_Rect play_rect;
    SDL_Rect setting_rect;
    SDL_Rect setting_menu_rect;
    SDL_Rect guide_rect;
    SDL_Rect change_rect[5];
    SDL_Rect quit_rect;
    SDL_Rect pause_rect;
    SDL_Rect pause_menu_rect;
    SDL_Rect yes_rect;
    SDL_Rect no_rect;
    SDL_Rect back_button_rect;

    Mix_Music* menu_music;
    bool is_in_menu;
    bool music_is_play=true;
    bool sound_is_play=true;
    int click_sound=0;
    int click_music=0;
    void setMenu(SDL_Renderer* renderer);
    void loadMenu(SDL_Renderer* renderer);
    void load_Pause(SDL_Renderer* renderer);
    void load_pause_menu(SDL_Renderer* renderer);
    void load_setting_menu(SDL_Renderer* renderer);
    void load_setting_page2(SDL_Renderer* renderer);
};
#endif // MENU_H_
