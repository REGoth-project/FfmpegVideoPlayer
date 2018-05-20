//
// Created by andre on 20.05.18.
//

#include "SDLWindow.h"
#include <exception>
#include <stdexcept>

static struct
{
    struct
    {
        SDL_Window* pWindow;
        SDL_Renderer* pRenderer;
        SDL_Texture* pTexture;
    }sdl;
}module;

void SDLWindow::open(uint32_t width, uint32_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
        throw new std::runtime_error("SDL_Init failed!");
    }

    module.sdl.pWindow = SDL_CreateWindow("Video-Player",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_OPENGL);

    if (!module.sdl.pWindow) {
        throw new std::runtime_error("Could not create SDL-Window");
    }

    module.sdl.pRenderer = SDL_CreateRenderer(module.sdl.pWindow, -1, 0);
    module.sdl.pTexture = SDL_CreateTexture(module.sdl.pRenderer,
                                            SDL_PIXELFORMAT_RGB24,
                                            SDL_TEXTUREACCESS_STATIC,
                                            width,
                                            height);
}

void SDLWindow::update()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    /*SDL_UpdateYUVTexture(bmp, NULL, pFrame->data[0], pFrame->linesize[0],
                                                           pFrame->data[1], pFrame->linesize[1],
                                                           pFrame->data[2], pFrame->linesize[2]);
    SDL_RenderCopy(renderer, bmp, NULL, NULL);*/

    SDL_RenderPresent(module.sdl.pRenderer);
    SDL_UpdateWindowSurface(module.sdl.pWindow);
    SDL_Delay(1000/30);
}

void SDLWindow::displayPixels(const uint8_t* pRGB, size_t pitch)
{
    SDL_UpdateTexture(module.sdl.pTexture, NULL, pRGB, (int)pitch);

    SDL_RenderCopy(module.sdl.pRenderer, module.sdl.pTexture, NULL, NULL);
}
