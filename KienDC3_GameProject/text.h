#ifndef TEXT_H__
#define TEXT_H__
#include"function.h"
class text_object{
public:
    TTF_Font* font = TTF_OpenFont("font.otf",35);
    SDL_Color fg = { 45, 55, 55 };
    SDL_Texture* score_text;
    SDL_Texture* point;
    SDL_Texture* high_score;
    SDL_Texture* highest_point;
    SDL_Rect score_text_rect;
    SDL_Rect point_rect;
    SDL_Rect high_score_rect;
    SDL_Rect highest_point_rect;
    string score_text_str="SCORE: ";
    string point_str="0";
    string high_score_str="HIGHSCORE: ";
    string highest_point_str;
    //setting text;
    SDL_Texture* button[5];
    SDL_Rect button_rect[5];
    string button_string[5];
    ifstream high_score_input;
    fstream high_score_output;
    void set_Text(SDL_Renderer* renderer);
    void set_highscore_menu();
    void load_Score(SDL_Renderer* renderer);
    void load_Highscore(SDL_Renderer* renderer);
    void load_Highscore_endgame(SDL_Renderer* renderer);
    void updateHighScore(SDL_Renderer* renderer);
    void loadButton_Setting(SDL_Renderer* renderer);
};


#endif // TEXT_H__
