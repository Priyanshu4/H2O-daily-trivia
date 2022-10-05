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
                Background(const pimoroni::RGB332 (&rgb_data)[SCREEN_HEIGHT][SCREEN_WIDTH]);

                /**
                 * Draws the sprite with the pen that is already set in the graphics object.
                 * The x and y are the top left position to draw the sprite.
                 */
                void draw(pimoroni::PicoGraphics_PenRGB332 &graphics);

            private:
                pimoroni::RGB332 data[SCREEN_HEIGHT][SCREEN_WIDTH];
        };
};

