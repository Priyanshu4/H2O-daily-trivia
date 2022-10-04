#pragma once
#include "theme.hpp"
#include "backgrounds_data.hpp"

namespace pico_trivia
{
	pico_trivia::Theme bamboo_theme(&pico_trivia::bamboo_background, {255, 0, 0}, {0, 255, 0});
	pico_trivia::Theme *default_theme_ptr = &bamboo_theme;

}
