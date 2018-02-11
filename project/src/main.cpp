#include <iostream>
#include <cmath>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "utils/sdl_utils.hpp"

const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 768;
const int BRUSH_SIZE = 32;
const int PIXELS_PER_ITERATION = 5;

static SDL_Texture *brush = 0;

void
drawLine(SDL_Renderer *renderer, float startx, float starty, float dx, float dy)
{

    std::cout << dx << " " << dy << std::endl;
    float distance = sqrt(dx * dx + dy * dy);   /* length of line segment (pythagoras) */
    int iterations = distance / PIXELS_PER_ITERATION + 1;       /* number of brush sprites to draw for the line */
    float dx_prime = dx / iterations;   /* x-shift per iteration */
    float dy_prime = dy / iterations;   /* y-shift per iteration */
    SDL_Rect dstRect;           /* rect to draw brush sprite into */

    dstRect.w = BRUSH_SIZE;
    dstRect.h = BRUSH_SIZE;

    /* setup x and y for the location of the first sprite */
    float x = startx - BRUSH_SIZE / 2.0f;
    float y = starty - BRUSH_SIZE / 2.0f;

    int i;
    /* draw a series of blots to form the line */
    for (i = 0; i < iterations; i++) {
            dstRect.x = x;
            dstRect.y = y;
            /* shift x and y for next sprite location */
            x += dx_prime;
            y += dy_prime;
            /* draw brush blot */
            SDL_RenderCopy(renderer, brush, NULL, &dstRect);
        }
}

void
initializeTexture(SDL_Renderer *renderer)
{
    SDL_Surface *bmp_surface;
    bmp_surface = SDL_LoadBMP("stroke.bmp");
    if (bmp_surface == NULL) {
          std::cout << "Could not load stroke" << std::endl;
        }
    brush =
        SDL_CreateTextureFromSurface(renderer, bmp_surface);
    SDL_FreeSurface(bmp_surface);
    if (brush == 0) {
          std::cout << "Could not load stroke" << std::endl;
        }
    SDL_SetTextureBlendMode(brush, SDL_BLENDMODE_ADD);
    SDL_SetTextureColorMod(brush, 255, 255, 255);
}

int
main(int argc, char *argv[])
{

    int x, y, dx, dy;
    Uint8 state;
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      return -1;
        }

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, 0, 0);


    initializeTexture(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event e;

    while(!quit) {
      while(SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
          quit = true;

        /* } else if (e.type == SDL_FINGERMOTION) { */
        } else if (true) {
          state = SDL_GetMouseState(&x, &y);
          SDL_GetRelativeMouseState(&dx, &dy);

          if (state & SDL_BUTTON_LMASK) {
            drawLine(renderer, x - dx, y - dy, dx, dy);
            SDL_RenderPresent(renderer);

          }
        }
      }
    }

    SDL_DestroyTexture(brush);
    SDL_Quit();

    return 0;
}

