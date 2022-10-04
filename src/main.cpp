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

#include "clock.hpp"
#include "trivia_questions_data.hpp"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define HEADER_HEIGHT 0
#define TIME_LEFT_OFFSET 3

#define QUESTION_HEIGHT 25
#define INDENT 10
#define CHOICE_A_HEIGHT 80
#define CHOICE_B_HEIGHT 120
#define CHOICE_X_HEIGHT 160
#define CHOICE_Y_HEIGHT 200

#define MILLISECONDS_TO_SHOW_ANSWER_SCREEN 5000
#define SELECTED_ANSWER_MESSAGE_HEIGHT 20
#define ANSWER_CORRECTNESS_MESSAGE_HEIGHT 65
#define ANSWER_STATISTICS_MESSAGE_HEIGHT 120
#define COME_BACK_MESSAGE_HEIGHT 180

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

enum AnswerChoice {NO_ANSWER = -1, A = 0, B = 1, X = 2, Y = 3};
enum SettingsMenuCursor {DAY = 0, HOUR = 1, MINUTE = 2, DONE = 3};

struct AnswerStatistics 
{
  unsigned int num_answers = 0;
  unsigned int num_correct = 0;
};

int main() {
  // set backlight to full brightness
  st7789.set_backlight(255);
  
  // set random seed to the lower 32 bits of the hardware timer
  unsigned int rand_seed = time_us_32(); 
  srand(rand_seed);

  // set font
  const bitmap::font_t * font = &font8;
  graphics.set_font(font);
  float font_scale = 2;
  int max_char_width = ceil(font_scale * font->max_width * font_scale);
  int char_height = ceil(font_scale * font->height);
  
  // create pens
  pimoroni::Pen WHITE = graphics.create_pen(255, 255, 255);
  pimoroni::Pen GREEN = graphics.create_pen(50, 205, 50);
  pimoroni::Pen RED = graphics.create_pen(255, 0, 0);
  pimoroni::Pen BLUE = graphics.create_pen(0, 0, 255);
  
  pimoroni::Pen TEXT_PEN = WHITE;


  // Create setup screen with way to set date/time
  pico_trivia::Clock clock = pico_trivia::Clock();
  pico_trivia::DayTime set_time = pico_trivia::DayTime(0, 0, 0, 0);
  SettingsMenuCursor cursor = SettingsMenuCursor::DAY;
  
  bool done_pressed = false;
  while(!done_pressed) 
  {
    graphics.set_pen(BLUE);
    graphics.clear();
    int32_t setup_text_width = graphics.measure_text("Setup", font_scale, 1);
    graphics.set_pen(WHITE);
    graphics.text("Setup", pimoroni::Point(SCREEN_WIDTH/2 - setup_text_width/2, HEADER_HEIGHT), SCREEN_WIDTH, font_scale);
    graphics.set_pen(cursor == SettingsMenuCursor::DAY ? GREEN : WHITE);
    graphics.text("Day: " + std::to_string(set_time.day), pimoroni::Point(INDENT, CHOICE_A_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    graphics.set_pen(cursor == SettingsMenuCursor::HOUR ? GREEN : WHITE);
    graphics.text("Hour: " + std::to_string(set_time.hour), pimoroni::Point(INDENT, CHOICE_B_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    graphics.set_pen(cursor == SettingsMenuCursor::MINUTE ? GREEN: WHITE);
    graphics.text("Minute: " + std::to_string(set_time.minute), pimoroni::Point(INDENT, CHOICE_X_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    int32_t enter_text_width = graphics.measure_text("Done", font_scale, 1);
    graphics.set_pen(cursor == SettingsMenuCursor::DONE ? GREEN : WHITE);
    graphics.text("Done", pimoroni::Point(INDENT, CHOICE_Y_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    st7789.update(&graphics);
    bool button_pressed = false;
    while(!button_pressed)
    {
      if (button_a.read() && cursor > SettingsMenuCursor::DAY) 
      {
        cursor = (SettingsMenuCursor)(((int)cursor)- 1);
        button_pressed = true;
      }
      else if(button_b.read() && cursor < SettingsMenuCursor::DONE) {
        cursor = (SettingsMenuCursor)(((int)cursor)+ 1);
        button_pressed = true;

      }
      else if(button_x.read()) {
        switch (cursor) 
        {
          case SettingsMenuCursor::DAY:
            set_time.day++;
            button_pressed = true;
            break;
          case SettingsMenuCursor::HOUR:
            set_time.hour += set_time.hour < 23 ? 1: 0;
            button_pressed = true;
            break;
          case SettingsMenuCursor::MINUTE:
            set_time.minute += set_time.minute < 59 ? 1: 0;
            button_pressed = true;
            break;
          case SettingsMenuCursor::DONE:
            done_pressed = true;
            button_pressed = true;
            break;
        }
      }
      else if(button_y.read()) {
        switch (cursor)
        {
          case SettingsMenuCursor::DAY:
            set_time.day -= set_time.day > 0 ? 1 : 0;
            button_pressed = true;
            break;
          case SettingsMenuCursor::HOUR:
            set_time.hour -= set_time.hour > 0 ?  1: 0;
            button_pressed = true;
            break;
          case SettingsMenuCursor::MINUTE:
            set_time.minute -= set_time.minute > 0 ? 1 : 0;
            button_pressed = true;
            break;
          case SettingsMenuCursor::DONE:
            done_pressed = true;
            button_pressed = true;
            break;
        }
      }
    }
  }
  clock.set_time(set_time);
  
  int daynumber = clock.get_time().day;
  pico_trivia::TriviaQuestion trivia_q = pico_trivia::get_todays_question(daynumber);
  std::array<std::string, NUM_ANSWER_CHOICES> answer_choices = trivia_q.get_shuffled_answer_choices();
  AnswerStatistics answer_stats;

  while(true) {
  
    // get current time
    pico_trivia::DayTime now = clock.get_time();
    std::string hour_str = std::to_string(now.get_12_normalized_hour());
    std::string minute_str = now.minute < 10 ? "0" + std::to_string(now.minute) : std::to_string(now.minute);
    std::string time_str = hour_str + ":" + minute_str;
    
    // if day has changed, get new trivia question
    if (now.day != daynumber)
    {
      daynumber = now.day;
      trivia_q = pico_trivia::get_todays_question(daynumber);
    }
    
    // draw background
    graphics.set_pen(BLUE);
    graphics.clear();
    
    // Draw Trivia Question on Screen
    graphics.set_pen(TEXT_PEN);
    int32_t header_width = graphics.measure_text("H2O Daily Trivia", font_scale, 1);
    graphics.text("H2O Daily Trivia", pimoroni::Point(SCREEN_WIDTH/2 - header_width/2, HEADER_HEIGHT), SCREEN_WIDTH, font_scale);
    
    int32_t time_width = graphics.measure_text(time_str, font_scale, 1);
    graphics.text(time_str, pimoroni::Point(SCREEN_WIDTH - time_width - TIME_LEFT_OFFSET, HEADER_HEIGHT), SCREEN_WIDTH, font_scale);
    
    graphics.text(trivia_q.question, pimoroni::Point(0, QUESTION_HEIGHT), SCREEN_WIDTH, font_scale);
    graphics.text("A) " + answer_choices[AnswerChoice::A], pimoroni::Point(INDENT, CHOICE_A_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    graphics.text("B) " + answer_choices[AnswerChoice::B], pimoroni::Point(INDENT, CHOICE_B_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    graphics.text("X) " + answer_choices[AnswerChoice::X], pimoroni::Point(INDENT, CHOICE_X_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    graphics.text("Y) " + answer_choices[AnswerChoice::Y], pimoroni::Point(INDENT, CHOICE_Y_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    
    // update screen
    st7789.update(&graphics);
    
    std::string selected_letter = "";
    AnswerChoice selected_answer = AnswerChoice::NO_ANSWER;
    
    bool time_changed = clock.get_time().minute != now.minute;
    
    // Keep Checking for button press until button is pressed or time changes, in which case screen needs to be redrawn
    while(selected_answer == AnswerChoice::NO_ANSWER && !time_changed)
    {
      time_changed = clock.get_time().minute != now.minute;
      if (button_a.read()) 
      {
        selected_answer = AnswerChoice::A;
        selected_letter = "A";
      }
      else if(button_b.read()) {
        selected_answer = AnswerChoice::B;
        selected_letter = "B";
      }
      else if(button_x.read()) {
        selected_answer = AnswerChoice::X;
        selected_letter = "X";
      }
      else if(button_y.read()) {
        selected_answer = AnswerChoice::Y;
        selected_letter = "Y";
      }
    }
    
    // if while loop exited due to time change, continue instead of showing answer screen
    if (selected_answer == AnswerChoice::NO_ANSWER) continue;
            
      
    // clear screen
    graphics.set_pen(BLUE);
    graphics.clear();

    graphics.set_pen(TEXT_PEN);
    graphics.text("You selected answer " + selected_letter, pimoroni::Point(INDENT, SELECTED_ANSWER_MESSAGE_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    graphics.text("Come back tommorow for another question!", pimoroni::Point(INDENT, COME_BACK_MESSAGE_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);

    
    if (answer_stats.num_answers == 0)
    {
      graphics.text("You were the first person to answer today's question.", pimoroni::Point(INDENT, ANSWER_STATISTICS_MESSAGE_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    }
    else 
    {
      int percent_correct = 100 * ((float)answer_stats.num_correct)/answer_stats.num_answers;
      std::string percent_string = std::to_string(percent_correct);
      graphics.text(percent_string + "% of other people got this question correct today.", pimoroni::Point(INDENT, ANSWER_STATISTICS_MESSAGE_HEIGHT), SCREEN_WIDTH-INDENT, font_scale);
    }

    if (answer_choices[selected_answer] == trivia_q.correct_answer)
    {
      answer_stats.num_correct++;
      graphics.set_pen(GREEN);
      graphics.text("Correct!", pimoroni::Point(INDENT, ANSWER_CORRECTNESS_MESSAGE_HEIGHT), SCREEN_WIDTH-INDENT, font_scale*2);
    }
    else {
      graphics.set_pen(RED);
      graphics.text("Incorrect :(", pimoroni::Point(INDENT, ANSWER_CORRECTNESS_MESSAGE_HEIGHT), SCREEN_WIDTH-INDENT, font_scale*2);
    }
    
    st7789.update(&graphics);
    answer_stats.num_answers++;
    sleep_ms(MILLISECONDS_TO_SHOW_ANSWER_SCREEN);
  }
  return 0;
}
