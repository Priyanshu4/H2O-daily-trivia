#include <math.h>
#include <cstdlib>
#include "pico/stdlib.h"

#include "libraries/pico_display_2/pico_display_2.hpp"
#include "drivers/st7789/st7789.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "libraries/bitmap_fonts/bitmap_fonts.hpp"
#include "libraries/bitmap_fonts/font8_data.hpp"
#include "rgbled.hpp"
#include "button.hpp"

#include "trivia_questions.hpp"

// Initialize Display Drivers
pimoroni::ST7789 st7789(320, 240, pimoroni::ROTATE_0, false, pimoroni::get_spi_pins(pimoroni::BG_SPI_FRONT));
pimoroni::PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

// Initialize RGBLED on right side of display
pimoroni::RGBLED led(pimoroni::PicoDisplay2::LED_R, pimoroni::PicoDisplay2::LED_G, pimoroni::PicoDisplay2::LED_B);

// Initialize buttons
pimoroni::Button button_a(pimoroni::PicoDisplay2::A);
pimoroni::Button button_b(pimoroni::PicoDisplay2::B);
pimoroni::Button button_x(pimoroni::PicoDisplay2::X);
pimoroni::Button button_y(pimoroni::PicoDisplay2::Y);  

enum AnswerChoice {A = 0, B = 1, X = 2, Y = 3};

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define HEADER_HEIGHT 0

#define QUESTION_HEIGHT 25
#define ANSWER_CHOICES_START_X 10
#define CHOICE_A_HEIGHT 80
#define CHOICE_B_HEIGHT 120
#define CHOICE_X_HEIGHT 160
#define CHOICE_Y_HEIGHT 200

int main() {
  // set backlight to full brightness
  st7789.set_backlight(255);
  
  // set random seed to the lower 32 bits of the hardware timer
  unsigned int rand_seed = time_us_32(); 
  srand(rand_seed);

  // draw background
  pimoroni::Pen BG = graphics.create_pen(0, 0, 255);
  graphics.set_pen(BG);
  graphics.clear();

  // set font
  const bitmap::font_t * font = &font8;
  graphics.set_font(font);
  float font_scale = 2;
  int max_char_width = ceil(font_scale * font->max_width * font_scale);
  int char_height = ceil(font_scale * font->height);
  
  // TODO on first setup, add a way to set date/time

  
  
  pimoroni::Pen WHITE = graphics.create_pen(255, 255, 255);
  graphics.set_pen(WHITE);
  int32_t header_width = graphics.measure_text("H2O Daily Trivia", font_scale, 1);
  graphics.text("H2O Daily Trivia", pimoroni::Point(SCREEN_WIDTH/2 - header_width/2 - 1, 0), SCREEN_WIDTH, font_scale);


  // get trivia question
  // TODO get a new trivia question every day
  pico_trivia::TriviaQuestion trivia_q = pico_trivia::trivia_questions[0];
  
  graphics.text(trivia_q.question, pimoroni::Point(0, QUESTION_HEIGHT), SCREEN_WIDTH, font_scale);
  std::array<std::string, NUM_ANSWER_CHOICES> answer_choices = trivia_q.get_shuffled_answer_choices();
  graphics.text("A) " + answer_choices[AnswerChoice::A], pimoroni::Point(ANSWER_CHOICES_START_X, CHOICE_A_HEIGHT), SCREEN_WIDTH, font_scale);
  graphics.text("B) " + answer_choices[AnswerChoice::B], pimoroni::Point(ANSWER_CHOICES_START_X, CHOICE_B_HEIGHT), SCREEN_WIDTH, font_scale);
  graphics.text("X) " + answer_choices[AnswerChoice::X], pimoroni::Point(ANSWER_CHOICES_START_X, CHOICE_X_HEIGHT), SCREEN_WIDTH, font_scale);
  graphics.text("Y) " + answer_choices[AnswerChoice::Y], pimoroni::Point(ANSWER_CHOICES_START_X, CHOICE_Y_HEIGHT), SCREEN_WIDTH, font_scale);

  
  
  // TODO write trivia questions and answers, detect button input for each answer, play animations for correct/incorrect

  // update screen
  st7789.update(&graphics);

  return 0;
}
