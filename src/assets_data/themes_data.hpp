#pragma once
#include "theme.hpp"
#include "backgrounds_data.hpp"

namespace pico_trivia
{
	pico_trivia::Theme bamboo_theme(&pico_trivia::bamboo_background, {0, 0, 0}, {0, 120, 0});
	pico_trivia::Theme tech_theme(&pico_trivia::pcb_trace_background, {255, 255, 255}, {0, 0, 125});
	pico_trivia::Theme *default_theme_ptr = &bamboo_theme;

}
