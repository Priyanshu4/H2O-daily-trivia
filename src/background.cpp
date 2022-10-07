#include "background.hpp"

void pico_trivia::Background::draw(pimoroni::PicoGraphics_PenRGB332 &graphics)
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
		for (int j = 0; j < SCREEN_WIDTH; j++)
        {
			graphics.set_pen(data[i * SCREEN_WIDTH + j]);
            graphics.set_pixel(pimoroni::Point(j, i));
        }
    }
}
