#pragma once
#include "theme.hpp"
#include "backgrounds_data.hpp"

namespace pico_trivia
{
	pico_trivia::Theme H2O_theme(&pico_trivia::H2O_molecules_background, {32, 255, 0});
	pico_trivia::Theme bamboo_theme(&pico_trivia::bamboo_background, {0, 0, 0});
	pico_trivia::Theme tech_theme(&pico_trivia::pcb_trace_background, {255, 255, 255});
	pico_trivia::Theme chess_theme(&pico_trivia::chess_background, {255, 255, 255});
	pico_trivia::Theme space_theme(&pico_trivia::space_background, {255, 255, 255});
	pico_trivia::Theme movie_theme(&pico_trivia::movie_background, {255, 255, 255});
	pico_trivia::Theme halloween_theme(&pico_trivia::halloween_background, {255, 213, 128});
}
