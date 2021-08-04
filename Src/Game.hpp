#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class Game
{

public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

private:
    float cnt = 0;
    bool isRunning = false;
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Texture *playerTex;

    float vel = 0.1;
};

#endif /* Game_hpp */