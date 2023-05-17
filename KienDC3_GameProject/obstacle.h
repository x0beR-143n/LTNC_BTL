#ifndef OBSTACLE_H
#define OBSTACLE_H

#include"function.h"
#include"Ammo.h"
#include"mainCharacter.h"
class obstacle{
public:
    SDL_Texture* obs_object;
    SDL_Rect obs_rect;
    Ammo torpedo;
    int waiting_time=0;
    int respawn_time=0;
    int count_up=0;
    int count_down=0;
    int limit_up=0;
    int limit_down=0;
    bool move_down=false;
    bool move_up=false;
    bool obs_is_move=false;
    bool obs_is_fired=false;
    void setRectsize(int x1, int y1);
    void load_obsImg(SDL_Renderer* renderer);
    void obs_move(int &state, int step);
    void respawn();
    void set_Enemy_default(SDL_Renderer* renderer);
    void set_Boss_enemy(SDL_Renderer* renderer);
    void load_Boss_enemy(SDL_Renderer* renderer);
    bool check_character_enemy_collision(mainCharacter character);
    bool check_character_enemybullet_Colision(mainCharacter character);
    bool check_characterbullet_enemy_Colision(Ammo bullet);
    void boss_move(int &up_or_down);
};
#endif // OBSTACLE_H
