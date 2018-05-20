//
// Created by andre on 20.05.18.
//

#pragma once


#include <cstdint>
#include <cstddef>

#include "SDL2/SDL.h"
#include "SDL2/SDL_thread.h"
#include "SDL2/SDL_syswm.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_audio.h"

namespace SDLWindow
{
    void open(uint32_t width, uint32_t height);
    void displayPixels(const uint8_t* pRGB, size_t pitch);
    void update();
}



