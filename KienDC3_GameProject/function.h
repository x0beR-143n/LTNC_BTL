#ifndef FUNCTION__H_
#define FUNCTION__H_

#include<windows.h>
#include<string>
#include<SDL.h>
#include<SDL_mixer.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include<fstream>

using namespace std;

static const int SCREEN_WIDTH = 1270;
static const int SCREEN_HEIGHT = 700;

void logSDLError(std::ostream& os,const std::string &msg, bool fatal);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
SDL_Texture* loadTexture( string path, SDL_Renderer* renderer ,bool is_enemy);
SDL_Texture* loadFont(TTF_Font* font,SDL_Color fg, string text, SDL_Renderer* renderer);
int randomNumber();
int randomIndex_heartIcon();
int random(int minN, int maxN);
bool click(SDL_Event e, SDL_Rect click_rect);
int length(int number);
void updateScore(int &score, string &text, int point);
bool is_bigger(string s1, string s2);
#endif // FUNCTION__H_
