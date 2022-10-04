#pragma once
#include <cstddef>
#include "libraries/pico_graphics/pico_graphics.hpp"

#define SCREEN_HEIGHT 240
#define SCREEN_WIDTH 320

namespace pico_trivia
{
    
        /**
         * Class that represents an RGB332 background. 
         */
        class Background 
        {
            public:
                Background(const pimoroni::RGB332 (&rgb_data)[SCREEN_HEIGHT][SCREEN_WIDTH]) 
                {
                    for (int i = 0; i < SCREEN_HEIGHT; i++)
                    {
                        for (int j = 0; j < SCREEN_WIDTH; j++)
                        {
                            data[i][j] = rgb_data[i][j];
                        }
                    }
                }

                /**
                 * Draws the sprite with the pen that is already set in the graphics object.
                 * The x and y are the top left position to draw the sprite.
                 */
                void draw(pimoroni::PicoGraphics_PenRGB332 &graphics)
                {
                    for (int i = 0; i < SCREEN_HEIGHT; i++)
                    {
                        for (int j = 0; j < SCREEN_WIDTH; j++)
                        {
                            graphics.set_pen(data[i][j]);
                            graphics.set_pixel(pimoroni::Point(j, i));
                        }
                    }
                }

            private:
                pimoroni::RGB332 data[SCREEN_HEIGHT][SCREEN_WIDTH];
        };
};

