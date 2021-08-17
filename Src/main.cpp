#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();

    //memoria
    /*
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); */

    // nome e icone janela e tamanho janela
    /*
    SDL_Window *screen = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640, 480,
                          SDL_WINDOW_OPENGL);*/

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game->init("salvee",
               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
               800, 600,
               false);

    //loop do jogo
    while (game->running())
    {
        //eventos

        frameStart = SDL_GetTicks();

        game->handleEvents();

        /*
        while (SDL_PollEvent(&event)) //teclado
        {

            switch (event.type)
            {
            case SDL_QUIT: //fecha com o x
                isRunning = false;
                break;

            case SDL_KEYDOWN: //fecha ao pressionar o ESC
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
            }
        } */

        //renderizacao

        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        /*
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_GLContext gContext;
        gContext = SDL_GL_CreateContext(window); */

        //inicia matriz

        //fecha matriz

        //Animacao
        
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();

    /*
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit(); */

    return 0;
}