#include <math.h>
#include <vector>
#include <cstdlib>

#include "libraries/pico_display_2/pico_display_2.hpp"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "rgbled.hpp"
#include "button.hpp"

#include "trivia_questions.h"


using namespace pimoroni;

ST7789 st7789(320, 240, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

RGBLED led(PicoDisplay2::LED_R, PicoDisplay2::LED_G, PicoDisplay2::LED_B);

Button button_a(PicoDisplay2::A);
Button button_b(PicoDisplay2::B);
Button button_x(PicoDisplay2::X);
Button button_y(PicoDisplay2::Y);  

int main() {
  // set backlight to full brightness
  st7789.set_backlight(255);

  // draw background
  Pen BG = graphics.create_pen(0, 0, 255);
  graphics.set_pen(BG);
  graphics.clear();
  
  // TODO on first setup, add a way to set date/time
  
  // get trivia question
  // TODO get a new trivia question every day
  pico_trivia::TriviaQuestion trivia_q = pico_trivia::trivia_questions[0];
  
  Pen WHITE = graphics.create_pen(255, 255, 255);
  
  // TODO write trivia questions and answers, detect button input for each answer, play animations for correct/incorrect

  // update screen
  st7789.update(&graphics);

  return 0;
}
