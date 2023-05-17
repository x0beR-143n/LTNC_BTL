#include "function.h"
#include "obstacle.h"
#include "Others.h"
#include "health_icon.h"
#include "menu.h"
#include "text.h"
void settingEnemy(obstacle enemy[],int n,SDL_Renderer* renderer)
{
    for(int i=0; i<n; i++)
    {
        enemy[i].setRectsize(SCREEN_WIDTH,randomNumber());
        enemy[i].set_Enemy_default(renderer);
        enemy[i].torpedo.is_fired=false;
    }
     enemy[0].obs_is_move=true;
     enemy[1].obs_is_move=false;
     enemy[2].obs_is_move=false;
}
bool check_press(int movement, int move_arr[])
{
    for(int i=0; i<5; i++)
    {
        if(move_arr[i] == movement)
        {
            return true;
        }
    }
    return false;
}
int main(int argc, char* argv[])
{
    srand(time(0));
    int boss_count;
    int boss_waiting_time;
    bool mainCharacter_hit_enemy=false;
    bool enemy_hit_maincharacter=false;
    bool enemy_collide_mainCharacter=false;
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
//sound effect
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        printf("%s", Mix_GetError());
    }
    Mix_Music* background_music=NULL;
    Mix_Chunk* explosion=NULL;
    Mix_Chunk* heart_sound=NULL;
//Load Sound Effect
    explosion = Mix_LoadWAV("music/explosion.wav");
    if (explosion == NULL)
    {
        printf("%s", Mix_GetError());
        return -1;
    }
    heart_sound = Mix_LoadWAV("music/health_Regen.wav");
    if (heart_sound == NULL)
    {
        printf("%s", Mix_GetError());
        return -1;
    }
//Load Music
    background_music = Mix_LoadMUS("music/background_music.mp3");
    if(background_music == NULL)
    {
        printf("%s", Mix_GetError());
    }
//Font
    if (TTF_Init() < 0)
    {
        SDL_Log("%s", TTF_GetError());
        return -1;
    }
    text_object text;
    text.button_string[0]="UP";
    text.button_string[1]="DOWN";
    text.button_string[2]="RIGHT";
    text.button_string[3]="LEFT";
    text.button_string[4]="SPACE";
    text.set_Text(renderer);
//menu loading
    the_menu menu;
    menu.setMenu(renderer);
//addition intitialize
    Surrounding addition;
//background
    addition.setBackground(renderer);
//explosion
    addition.setExplosion(renderer);
    addition.setexplosion_character(renderer);
//health_bar
    addition.set_healthbar(renderer);
    addition.setgameover_img(renderer);
    Surrounding boss_Healthbar;
    boss_Healthbar.set_healthBar_boss(renderer);
    int boss_state=0;
//health related icon
    heart_icon heart;
    heart_icon bomb;
//character initialize
    mainCharacter planeobject;
    int type_of_plane=0;
    planeobject.set_character_default(renderer,type_of_plane);
    int n;
    int play_rect_size_w=planeobject.rect.w;
    int play_rect_size_h=planeobject.rect.h;
    int setting_rect_size_w = planeobject.rect.w*2;
    int setting_rect_size_h = planeobject.rect.h*2;
    int state_of_player;
    int base_state;
    int plane_move[5];
    plane_move[0]=SDLK_UP;
    plane_move[1]=SDLK_DOWN;
    plane_move[2]=SDLK_RIGHT;
    plane_move[3]=SDLK_LEFT;
    plane_move[4]=SDLK_SPACE;
//obstacle initialize
    obstacle enemy[3];
    obstacle boss_enemy;
    int up_or_down=random(1,2);
    int count=0;
//Keyboard event
    SDL_Event e;
//loop game
    bool in_play=false;
    bool in_game=true;
    bool in_menu=true;
    bool in_setting=false;
while(in_game)
{
    if(in_menu)
    {
        planeobject.setRectsize(50,300);
        planeobject.rect.w = play_rect_size_w;
        planeobject.rect.h = play_rect_size_h;
        menu.is_in_menu=true;
        text.set_highscore_menu();
        while(menu.is_in_menu)
        {
            SDL_RenderClear(renderer);
            addition.loadBackground(renderer);
            planeobject.loadImg(renderer);
            planeobject.moving();
            menu.loadMenu(renderer);
            text.load_Highscore(renderer);
            if(!Mix_PlayingMusic() && menu.music_is_play)
            {
                Mix_PlayMusic(menu.menu_music,0);
            }
            while(SDL_PollEvent(&e))
            {
                if(click(e,menu.play_rect))
                {
                    menu.is_in_menu=false;
                    in_menu=false;
                    in_play=true;
                    in_setting=false;
                    if(Mix_PlayingMusic())
                    {
                        Mix_HaltMusic();
                    }
                    break;
                }
                if(click(e,menu.setting_rect))
                {
                    menu.is_in_menu=false;
                    in_menu=false;
                    in_setting=true;
                    break;
                }
                if(click(e,menu.quit_rect))
                {
                    menu.is_in_menu=false;
                    in_menu=false;
                    in_game=false;
                    in_setting=false;
                    break;
                }
                planeobject.handleInput(e,plane_move[0],plane_move[1],plane_move[2],plane_move[3]);
            }
            SDL_RenderPresent(renderer);
        }
    }
    if(in_setting)
    {
        bool in_setting_menu=true;
        bool in_setting_page2=false;
        while(in_setting_menu)
        {
            SDL_RenderClear(renderer);
            addition.loadBackground(renderer);
            menu.load_setting_menu(renderer);
            text.loadButton_Setting(renderer);
            SDL_RenderPresent(renderer);
            if(!Mix_PlayingMusic() && menu.music_is_play)
            {
                Mix_PlayMusic(menu.menu_music,0);
            }
            while(SDL_PollEvent(&e))
            {
                if(click(e,menu.back_button_rect))
                {
                    in_setting_menu=false;
                    in_menu=true;
                    break;
                }
                for(int i=0; i<5; i++)
                {
                    if(click(e,menu.change_rect[i]))
                    {
                       bool wait_press=true;
                       while(wait_press)
                       {
                           while(SDL_WaitEvent(&e))
                           {
                               if(e.type==SDL_KEYDOWN)
                               {
                                   if(check_press(e.key.keysym.sym,plane_move))
                                   {
                                       wait_press=false;
                                       break;
                                   }
                                   else
                                   {
                                        plane_move[i]=e.key.keysym.sym;
                                        text.button_string[i]=SDL_GetKeyName(e.key.keysym.sym);
                                        text.button[i]=loadFont( text.font, text.fg, text.button_string[i],renderer);
                                        TTF_SizeText( text.font, text.button_string[i].c_str(),& text.button_rect[i].w,& text.button_rect[i].h);
                                        wait_press=false;
                                        break;
                                   }
                               }
                           }
                       }
                    }
                }
                if(click(e,menu.music_rect[1]))
                {
                    swap(menu.music_rect[0].x,menu.music_rect[1].x);
                    if(menu.click_sound==0)
                    {
                       menu.sound_is_play=false;
                       menu.click_sound=1;
                       break;
                    }
                    if(menu.click_sound==1)
                    {
                        menu.sound_is_play=true;
                        menu.click_sound=0;
                        break;
                    }
                }
                if(click(e,menu.music_rect[3]))
                {
                    swap(menu.music_rect[2].x,menu.music_rect[3].x);
                    if(menu.click_music==0)
                    {
                        menu.music_is_play=false;
                        if(Mix_PlayingMusic())
                        {
                            Mix_HaltMusic();
                        }
                        menu.click_music=1;
                        break;
                    }
                    if(menu.click_music==1)
                    {
                        menu.music_is_play=true;
                        if(!Mix_PlayingMusic())
                        {
                            Mix_PlayMusic(menu.menu_music,0);
                        }
                        menu.click_music=0;
                        break;
                    }
                }
                if(click(e,menu.next_page_rect))
                {
                    in_setting_menu=false;
                    in_setting_page2=true;
                    break;
                }
            }
        }
        planeobject.setRectsize(500,260);
        planeobject.rect.w = setting_rect_size_w;
        planeobject.rect.h = setting_rect_size_h;
        while(in_setting_page2)
        {
            SDL_RenderClear(renderer);
            addition.loadBackground(renderer);
            menu.load_setting_page2(renderer);
            planeobject.loadImg(renderer);
            SDL_RenderPresent(renderer);
            while(SDL_PollEvent(&e))
            {
                if(click(e,menu.prev_page_rect))
                {
                    in_setting_page2=false;
                    in_setting_menu=true;
                    break;
                }
                if(click(e,menu.next_plane_rect))
                {
                    type_of_plane++;
                    if(type_of_plane > 3)
                    {
                        type_of_plane=0;
                    }
                    planeobject.set_character_default(renderer,type_of_plane);
                    planeobject.rect.w = setting_rect_size_w;
                    planeobject.rect.h = setting_rect_size_h;
                }
                if(click(e,menu.prev_plane_rect))
                {
                    type_of_plane--;
                    if(type_of_plane < 0)
                    {
                        type_of_plane=3;
                    }
                    planeobject.set_character_default(renderer,type_of_plane);
                    planeobject.rect.w = setting_rect_size_w;
                    planeobject.rect.h = setting_rect_size_h;
                }
            }
        }
    }
    if(in_play)
    {
        bool in_pause=false;
        bool is_over=false;
        state_of_player=0;
        base_state=0;
        int enemy_step=4;
        planeobject.is_alive=true;
        planeobject.setRectsize(50,300);
        planeobject.rect.w = play_rect_size_w;
        planeobject.rect.h = play_rect_size_h;
        settingEnemy(enemy,3,renderer);
        heart.setHealthRegenerate(renderer);
        bomb.setBomb(renderer);
        boss_enemy.set_Boss_enemy(renderer);
        boss_waiting_time=0;
        boss_count=0;
        int score=0;
        text.point_str="0";
        text.set_Text(renderer);
        heart.is_appear=false;
        bomb.is_appear=false;
        while(!is_over)
        {
    //clear_background
        SDL_RenderClear(renderer);
    //load sound
        if(!Mix_PlayingMusic() && menu.music_is_play)
        {
            Mix_PlayMusic(background_music,0);
        }
    //background and health bar and health icon
        addition.loadBackground(renderer);
        addition.loadHealthbar(renderer,state_of_player);
        addition.loadBaseHealth(renderer,base_state);
    //pause game
        menu.load_Pause(renderer);
    // score
        text.load_Score(renderer);
    //heart_icon
        if(heart.is_appear)
        {
            heart.loadHealthRegen(renderer);
            heart.icon_move(1);
            if(heart.check_collide(planeobject))
            {
                if(menu.sound_is_play)
                {
                    Mix_PlayChannel(-1,heart_sound,0);
                }
                heart.is_appear=false;
                state_of_player--;
                heart.health_icon.x=SCREEN_WIDTH-100;
                heart.health_icon.y=randomNumber();
            }
            if(heart.health_icon.x <0)
            {
                heart.is_appear=false;
                heart.health_icon.x=SCREEN_WIDTH-100;
                heart.health_icon.y=randomNumber();
            }
        }
        if(heart.check_appear(state_of_player))
        {
            heart.is_appear=true;
        }
    //player_heart
        if(state_of_player==5 || base_state==5)
        {
            addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-30, planeobject.rect.y-40);
            planeobject.is_alive=false;
            is_over=true;
            in_play=false;
            addition.end_game=true;
            if(Mix_PlayingMusic())
            {
                Mix_HaltMusic();
            }
        }
    //character
        if(planeobject.is_alive)
        {
           planeobject.loadImg(renderer);
           planeobject.moving();
        }
    //bomb
         if(bomb.is_appear)
        {
            bomb.loadHealthRegen(renderer);
            bomb.icon_move(2);
            if(bomb.check_collide(planeobject))
            {
                addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-30, planeobject.rect.y-40);
                bomb.is_appear=false;
                state_of_player++;
                bomb.health_icon.x=SCREEN_WIDTH-100;
                bomb.health_icon.y=randomNumber();
                enemy_hit_maincharacter=true;
                if(menu.sound_is_play)
                {
                    Mix_PlayChannel(-1,explosion,0);
                }
            }
            if(bomb.health_icon.x <0)
            {
                bomb.is_appear=false;
                bomb.health_icon.x=SCREEN_WIDTH-100;
                bomb.health_icon.y=randomNumber();
            }
        }
        if(bomb.check_appearBomb())
        {
            bomb.is_appear=true;
        }
    //boss

        if(boss_waiting_time >= 10 )
        {
            boss_waiting_time++;
        }
        if(boss_waiting_time >=60 && boss_enemy.obs_rect.x > SCREEN_WIDTH-300)
        {
            boss_enemy.load_Boss_enemy(renderer);
            boss_enemy.obs_rect.x -= 1;
        }
        if(boss_enemy.obs_rect.x <= SCREEN_WIDTH-300 && boss_waiting_time >=60)
        {
            boss_enemy.obs_is_move=true;
            boss_enemy.obs_is_fired=false;
        }
        if(boss_enemy.obs_is_move && !boss_enemy.obs_is_fired)
        {
            if(boss_enemy.check_character_enemy_collision(planeobject))
            {
                addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-30, planeobject.rect.y-40);
                enemy_collide_mainCharacter=true;
                if(menu.sound_is_play)
                {
                    Mix_PlayChannel(-1,explosion,0);
                }
                state_of_player=5;
            }
            boss_enemy.load_Boss_enemy(renderer);
            boss_Healthbar.load_healthBar_boss(renderer,boss_enemy.obs_rect.x+30,boss_enemy.obs_rect.y-40,boss_state);
            if(boss_enemy.torpedo.is_fired)
            {
                boss_enemy.torpedo.loadAmmoImg(renderer);
                boss_enemy.torpedo.ammo_rect.x -= 15;
                if(boss_enemy.check_character_enemybullet_Colision(planeobject))
                {
                    boss_enemy.torpedo.is_fired=false;
                    addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-30, planeobject.rect.y-40);
                    enemy_hit_maincharacter=true;
                    state_of_player += 2;
                    if(menu.sound_is_play)
                    {
                        Mix_PlayChannel(-1,explosion,0);
                    }
                    if(state_of_player >5)
                    {
                        state_of_player=5;
                    }
                }
                if(boss_enemy.torpedo.ammo_rect.x <0)
                {
                    boss_enemy.torpedo.is_fired=false;

                }
            }
            else
            {
                boss_count++;
                if(boss_count==20)
                {
                    boss_enemy.torpedo.is_fired=true;
                    boss_enemy.torpedo.setAmmoRect(boss_enemy.obs_rect.x-80,boss_enemy.obs_rect.y+80);
                    boss_count=0;
                }
            }
            boss_enemy.boss_move(up_or_down);
        }
        if(boss_enemy.obs_is_fired && boss_enemy.torpedo.is_fired)
        {
            boss_enemy.torpedo.loadAmmoImg(renderer);
            boss_enemy.torpedo.ammo_rect.x -= 15;
            if(boss_enemy.check_character_enemybullet_Colision(planeobject))
            {
                if(menu.sound_is_play)
                {
                Mix_PlayChannel(-1,explosion,0);
                }
                boss_enemy.torpedo.is_fired=false;
                addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-30, planeobject.rect.y-40);
                state_of_player += 2;
            }
            if(boss_enemy.torpedo.ammo_rect.x <0)
            {
                boss_enemy.torpedo.is_fired=false;
                boss_enemy.torpedo.ammo_rect.x=boss_enemy.obs_rect.x-80;
                boss_enemy.torpedo.ammo_rect.y=boss_enemy.obs_rect.y+80;
            }
        }


    //small enemy
         for(int i=0; i<3; i++)
        {
            if(enemy[i].obs_is_move && !enemy[i].obs_is_fired)
            {
                enemy[i].load_obsImg(renderer);
                enemy[i].obs_move(base_state,enemy_step);
                if(enemy[i].check_character_enemy_collision(planeobject))
                {
                    if(menu.sound_is_play)
                    {
                        Mix_PlayChannel(-1,explosion,0);
                    }
                    enemy[i].obs_is_fired=true;
                    state_of_player++;
                    addition.loadExplosion(renderer,enemy[i].obs_rect.x-40,enemy[i].obs_rect.y-50);
                    addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-30, planeobject.rect.y-40);
                    enemy_collide_mainCharacter=true;
                    enemy[i].obs_rect.x=SCREEN_WIDTH;
                }
            }
            if(!enemy[i].obs_is_move )
            {
                count++;
                if(count==50)
                {
                    enemy[i].obs_is_move=true;
                    count=0;
                }
            }
            if(enemy[i].obs_is_fired )
            {
                enemy[i].respawn();
            }
        }
    //enemy ammo
        for(int i=0; i<3; i++)
        {
            if(enemy[i].obs_is_move && !enemy[i].obs_is_fired)
            {
                if(enemy[i].torpedo.is_fired)
                {
                    enemy[i].torpedo.loadAmmoImg(renderer);
                    enemy[i].torpedo.bullet_travel(2);
                    //bullet collision with player
                    if(enemy[i].check_character_enemybullet_Colision(planeobject))
                    {
                        if(menu.sound_is_play)
                        {
                        Mix_PlayChannel(-1,explosion,0);
                        }
                        enemy[i].torpedo.is_fired=false;
                        addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-30, planeobject.rect.y-40);
                        enemy_hit_maincharacter=true;
                        state_of_player++;
                    }
                    if(enemy[i].torpedo.ammo_rect.x < 0)
                    {
                        enemy[i].torpedo.is_fired=false;
                    }
                }
                if(!enemy[i].torpedo.is_fired)
                {
                    enemy[i].waiting_time++;
                    if(enemy[i].waiting_time == 50)
                    {
                    enemy[i].torpedo.is_fired=true;
                    enemy[i].torpedo.setAmmoRect(enemy[i].obs_rect.x-20, enemy[i].obs_rect.y+55);
                    enemy[i].waiting_time=0;
                    }
                }
            }
            if(enemy[i].obs_is_fired && enemy[i].torpedo.is_fired)
            {
                enemy[i].torpedo.loadAmmoImg(renderer);
                enemy[i].torpedo.bullet_travel(2);
                if(enemy[i].check_character_enemybullet_Colision(planeobject))
                {
                    if(menu.sound_is_play)
                    {
                        Mix_PlayChannel(-1,explosion,0);
                    }
                    enemy[i].torpedo.is_fired=false;
                    addition.loadExplosion_maincharacter(renderer,planeobject.rect.x-50, planeobject.rect.y-60);
                    enemy_hit_maincharacter=true;
                    state_of_player++;
                }
                if(enemy[i].torpedo.ammo_rect.x < 0)
                {
                    enemy[i].torpedo.is_fired=false;
                }
            }
        }
    //main character bullet fire
        n=planeobject.vec.size();
         if(!planeobject.vec.empty())
        {
            for(int i=0;i<n;i++)
            {
                if(planeobject.vec[i].is_fired)
                {
                    planeobject.vec[i].loadAmmoImg(renderer);
                    planeobject.vec[i].bullet_travel(1);
                    //check collision with obstacle
                    for(int j=0; j<3; j++)
                    {
                        if( enemy[j].check_characterbullet_enemy_Colision(planeobject.vec[i]) )
                        {
                            planeobject.vec[i].is_fired=false;
                            enemy[j].obs_is_fired=true;
                            addition.loadExplosion(renderer,enemy[j].obs_rect.x-40,enemy[j].obs_rect.y-50);
                            enemy[j].obs_rect.x=SCREEN_WIDTH;
                            mainCharacter_hit_enemy=true;
                            if(menu.sound_is_play)
                            {
                                Mix_PlayChannel(-1,explosion,0);
                            }
                            boss_waiting_time++;
                            updateScore(score,text.point_str,10);
                            text.point = loadFont(text.font,text.fg,text.point_str,renderer);
                            TTF_SizeText(text.font,text.point_str.c_str(),&text.point_rect.w,&text.point_rect.h);
                        }
                    }
                    if(boss_enemy.check_characterbullet_enemy_Colision(planeobject.vec[i]))
                    {
                        if(menu.sound_is_play)
                        {
                        Mix_PlayChannel(-1,explosion,0);
                        }
                        planeobject.vec[i].is_fired=false;
                        mainCharacter_hit_enemy=true;
                        addition.loadExplosion(renderer,boss_enemy.obs_rect.x,boss_enemy.obs_rect.y);
                        boss_state++;
                    }
                    //set false for ammo out of screen
                    if(planeobject.vec[i].ammo_rect.x > SCREEN_WIDTH)
                    {
                        planeobject.vec[i].is_fired=false;
                    }
                }
            }
            if(planeobject.vec[n-1].ammo_rect.x > SCREEN_WIDTH || state_of_player==5)
            {
                while(!planeobject.vec.empty())
                {
                    planeobject.vec.pop_back();
                }
            }
        }
        if(boss_state==5)
        {
            boss_enemy.obs_is_move=false;
            boss_enemy.obs_is_fired=true;
            boss_enemy.obs_rect.x=SCREEN_WIDTH-100;
            boss_enemy.obs_rect.y=SCREEN_HEIGHT/3;
            boss_waiting_time=0;
            boss_state=0;
            enemy_step += 2;
            updateScore(score,text.point_str,50);
            text.point = loadFont(text.font,text.fg,text.point_str,renderer);
            TTF_SizeText(text.font,text.point_str.c_str(),&text.point_rect.w,&text.point_rect.h);
        }
        //renderer preset
        SDL_RenderPresent(renderer);
        if(enemy_collide_mainCharacter)
        {
            SDL_Delay(200);
            enemy_collide_mainCharacter=false;
        }
        if(mainCharacter_hit_enemy)
        {
            SDL_Delay(200);
            mainCharacter_hit_enemy=false;
        }
        if(enemy_hit_maincharacter)
        {
            SDL_Delay(200);
            enemy_hit_maincharacter=false;
        }

        //keyboard event
            while(SDL_PollEvent(&e))
            {
                planeobject.handleInput(e,plane_move[0],plane_move[1],plane_move[2],plane_move[3]);
                planeobject.handleFire(e,planeobject.rect.x+planeobject.rect.w-10,planeobject.rect.y+planeobject.rect.h-20,renderer,plane_move[4    ]);
                if(click(e,menu.pause_rect) || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    in_pause=true;
                    menu.load_pause_menu(renderer);
                    SDL_RenderPresent(renderer);
                    while(in_pause)
                    {
                        while(SDL_WaitEvent(&e))
                        {
                           if(click(e,menu.yes_rect))
                            {
                                in_pause=false;
                                is_over=true;
                                in_play=false;
                                in_menu=true;
                                if(Mix_PlayingMusic())
                                {
                                    Mix_HaltMusic();
                                }
                                break;
                            }
                            if(click(e,menu.no_rect))
                            {
                                in_pause=false;
                                break;
                            }
                        }
                    }
                }
            }
        // end event
        }
    }
    if(addition.end_game)
    {
        addition.loadGameover(renderer);
        text.updateHighScore(renderer);
        text.load_Highscore_endgame(renderer);
        SDL_RenderPresent(renderer);
        bool wait_end_game=true;
        while(wait_end_game)
        {
            while(SDL_WaitEvent(&e))
            {
                if(click(e,addition.play_again_rect))
                {
                    in_play=true;
                    addition.end_game=false;
                    wait_end_game=false;
                    break;
                }
                if(click(e,addition.back_to_menu_rect))
                {
                    in_menu=true;
                    addition.end_game=false;
                    wait_end_game=false;
                    break;
                }
            }
        }
    }
}
    // endgame
    TTF_Quit();
    Mix_CloseAudio();
    quitSDL(window, renderer);
    return 0;

}

