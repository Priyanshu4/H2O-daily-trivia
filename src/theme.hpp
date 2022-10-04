#include "background.hpp"

namespace pico_trivia 
{
	// Class for visual theme of a trivia question
	class Theme
	{
		pico_trivia::Background *background;
		std::array<uint8_t, 3> text_rgb;
		std::array<uint8_t, 3> led_rgb;

		public:
			Theme(pico_trivia::Background *background, std::array<uint8_t, 3> text_rgb, std::array<uint8_t, 3> led_rgb) 
			: background(background)
			, text_rgb(text_rgb)
			, led_rgb(led_rgb) 
			{}
			pico_trivia::Background* get_background() {return background;}
			std::array<uint8_t, 3> get_text_rgb() {return text_rgb;}
			std::array<uint8_t, 3> get_led_rgb() {return led_rgb;}
	};
}
