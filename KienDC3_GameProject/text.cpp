#include"text.h"

void text_object::set_Text(SDL_Renderer* renderer)
{
    score_text=loadFont(font,fg,score_text_str,renderer);
    TTF_SizeText(font,score_text_str.c_str(),&score_text_rect.w,&score_text_rect.h);
    score_text_rect.x=720;
    score_text_rect.y=0;

    point=loadFont(font,fg,point_str,renderer);
    TTF_SizeText(font,point_str.c_str(),&point_rect.w,&point_rect.h);
    point_rect.x=870;
    point_rect.y=0;

    high_score=loadFont(font,fg,high_score_str,renderer);
    TTF_SizeText(font,high_score_str.c_str(),&high_score_rect.w,&high_score_rect.h);
    high_score_rect.y=0;
    high_score_rect.x=20;

    high_score_input.open("score.txt");
    high_score_input >> highest_point_str;
    highest_point=loadFont(font,fg,highest_point_str,renderer);
    TTF_SizeText(font,highest_point_str.c_str(),&highest_point_rect.w,&highest_point_rect.h);
    highest_point_rect.y=0;
    highest_point_rect.x=270;
    high_score_input.close();

    //setting


    for(int i=0; i<5; i++)
    {
        button[i]=loadFont(font,fg,button_string[i],renderer);
        TTF_SizeText(font,button_string[i].c_str(),&button_rect[i].w,&button_rect[i].h);
        button_rect[i].x=250;
        if(i==0)
        {
            button_rect[i].y=25;
        }
        else
        {
            button_rect[i].y=button_rect[i-1].y+75;
        }
    }
}
void text_object::load_Score(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,point,NULL,&point_rect);
    SDL_RenderCopy(renderer,score_text,NULL,&score_text_rect);
}
void text_object::load_Highscore(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,high_score,NULL,&high_score_rect);
    SDL_RenderCopy(renderer,highest_point,NULL,&highest_point_rect);
}
void text_object::load_Highscore_endgame(SDL_Renderer* renderer)
{
    highest_point_rect.x=740;
    highest_point_rect.y=330;
    high_score_rect.x=490;
    high_score_rect.y=330;
    SDL_RenderCopy(renderer,high_score,NULL,&high_score_rect);
    SDL_RenderCopy(renderer,highest_point,NULL,&highest_point_rect);
}
void text_object::set_highscore_menu()
{
    high_score_rect.y=0;
    high_score_rect.x=20;
    highest_point_rect.y=0;
    highest_point_rect.x=270;
}
void text_object::updateHighScore(SDL_Renderer* renderer)
{
    if( is_bigger(point_str,highest_point_str))
    {
        highest_point_str=point_str;
        highest_point=loadFont(font,fg,highest_point_str,renderer);
        TTF_SizeText(font,highest_point_str.c_str(),&highest_point_rect.w,&highest_point_rect.h);
        high_score_output.open("score.txt",ios::out);
        high_score_output << point_str;
        high_score_output.close();
    }
}
void text_object::loadButton_Setting(SDL_Renderer* renderer)
{
    for(int i=0; i<5; i++)
    {
        SDL_RenderCopy(renderer,button[i],NULL,&button_rect[i]);
    }
}
