#pragma once
#include "theme.hpp"
#include "backgrounds_data.hpp"

namespace pico_trivia
{
	pico_trivia::Theme bamboo_theme(&pico_trivia::bamboo_background, {0, 0, 0});
	pico_trivia::Theme tech_theme(&pico_trivia::pcb_trace_background, {255, 255, 255});
	pico_trivia::Theme chess_theme(&pico_trivia::chess_background, {255, 255, 255});
}
