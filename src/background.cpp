#include "background.hpp"

pico_trivia::Background::Background(const pimoroni::RGB332 (&rgb_data)[SCREEN_HEIGHT][SCREEN_WIDTH]) 
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
       for (int j = 0; j < SCREEN_WIDTH; j++)
       {
          data[i][j] = rgb_data[i][j];
       }
    }
}

void pico_trivia::Background::draw(pimoroni::PicoGraphics_PenRGB332 &graphics)
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
