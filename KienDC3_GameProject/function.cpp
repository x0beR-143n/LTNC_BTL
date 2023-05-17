#include"function.h"

using namespace std;
const string WINDOW_TITLE = "x0Ber_143n_game";
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{

    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

//may ao: window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);



    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);


    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
SDL_Texture* loadTexture( string path, SDL_Renderer* renderer,bool is_enemy )
{
     SDL_Texture* newTexture = NULL;
     SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
     if ( loadedSurface == NULL )
     cout << "Unable to load image " << path << " SDL_image Error: "<< IMG_GetError() << endl;
    else {
        if(is_enemy)
        {
            SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format,248, 248, 255));
        }
        else
        {
            SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format,255, 255, 255));
        }
     newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
     if( newTexture == NULL )
     cout << "Unable to create texture from " << path << " SDL Error: "<< SDL_GetError() << endl;

     }
      SDL_FreeSurface( loadedSurface );
    return newTexture;
}
SDL_Texture* loadFont(TTF_Font* font,SDL_Color fg, string text, SDL_Renderer* renderer)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), fg);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
int randomNumber()
{
    return 69+ rand()%(SCREEN_HEIGHT-200+1-69);
}
int randomIndex_heartIcon()
{
    return rand()%51;
}
int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}
bool click(SDL_Event e,SDL_Rect click_rect)
{
    if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            int mouse_x=e.motion.x;
            int mouse_y=e.motion.y;
            if(mouse_x <= click_rect.x + click_rect.w && mouse_x >= click_rect.x)
            {
                if(mouse_y >= click_rect.y && mouse_y <= click_rect.y + click_rect.h )
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int length(int number)
{
    int count=0;
    while(number!= 0)
    {
        number /= 10;
        count++;
    }
    return count;
}
void updateScore(int &score, string &text, int point)
{
    score+=point;
    int n=length(score);
    int index=n-1;
    int a=score;
    char c[n+1];
    while(index >= 0)
    {
        c[index]= (a%10) + '0';
        a=a/10;
        index--;
    }
    c[n] = '\0';
    text=c;
}
bool is_bigger(string s1, string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    if(n1 < n2)
    {
        return false;
    }
    if(n1 > n2)
    {
        return true;
    }
    for(int i=0; i<n1; i++)
    {
        if(s1[i] -'0' > s2[i] -'0')
        {
            return true;
        }
        if(s1[i]-'0' < s2[i]- '0')
        {
            return false;
        }
    }
    return false;
}
