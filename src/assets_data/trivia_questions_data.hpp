#pragma once
#include "trivia_question.hpp"
#include "themes_data.hpp"

namespace pico_trivia {
	
	// This question appears normal to users, but indicates to me that new trivia questions need to be added
	TriviaQuestion ERROR_QUESTION = TriviaQuestion("In which year was the first iPhone released?", "2007", {"2005", "2009", "2010"}, &tech_theme);
	
	std::array<TriviaQuestion, 10> trivia_questions = {
		TriviaQuestion("How many bones do sharks have in their bodies?", "0", {"235", "206", "1095"}, &H2O_theme),
		TriviaQuestion("Which of the following is not a real chess opening?", "Black Tiger Attack", {"Bongcloud Attack", "Pterodactyl Defense", "Frankenstein-Dracula Variation"}, &chess_theme),
		TriviaQuestion("In what year was the first moon landing?", "1969", {"1974", "1959", "1962"}, &space_theme),
		TriviaQuestion("How much RAM does this device have?", "256 kilobytes", {"2 megabytes", "64 kilobytes", "1 gigabyte"}, &tech_theme),
		TriviaQuestion("In what year was the first Star Wars movie released?", "1977", {"2002", "1969", "1985"}, &space_theme),
		TriviaQuestion("Who is the highest rated chess player of all time?", "Magnus Carlsen", {"Bobby Fischer", "Garry Kasparov", "Hikaru Nakamura"}, &chess_theme),
		TriviaQuestion("What was the original name of the Google search engine?", "BackRub", {"Alphabet", "WebCrawler", "JumpStation"}, &tech_theme),
		TriviaQuestion("What material was this device's case 3d printed from?", "Polylactic Acid", {"Nylon", "Polycarbonate", "Polypropylene"}, &tech_theme),
		TriviaQuestion("What type of photosynthesis does bamboo use?", "C3", {"C4", "C2", "CAM"}, &bamboo_theme),
		TriviaQuestion("When did halloween first come to the United States?", "1840s", {"1780s", "1600s", "1890s"}, &halloween_theme),
		

	};
}
		

