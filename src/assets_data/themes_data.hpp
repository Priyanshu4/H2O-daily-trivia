#pragma once
#include "theme.hpp"
#include "backgrounds_data.hpp"

namespace pico_trivia
{
	pico_trivia::Theme bamboo_theme(&pico_trivia::bamboo_background, {0, 0, 0}, {0, 120, 0});
	pico_trivia::Theme *default_theme_ptr = &bamboo_theme;

}
