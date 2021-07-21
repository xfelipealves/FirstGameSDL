#include <SDL2/SDL.h>
#include <iostream>

int main(int argv, char **args)
{
    SDL_Init(SDL_INIT_EVERYTHING);

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

    SDL_Window *window = SDL_CreateWindow("salvee",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_OPENGL);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    bool isRunning = true;
    SDL_Event event;

    //loop do jogo
    while (isRunning)
    {
        //eventos
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
        }

        //renderizacao
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);

        SDL_RenderPresent(renderer);
        SDL_GLContext gContext;
        gContext = SDL_GL_CreateContext(window);
        
        //inicia matriz
        

        //fecha matriz

        //Animacao
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}