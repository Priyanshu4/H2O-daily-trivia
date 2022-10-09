#pragma once
#include "trivia_question.hpp"
#include "themes_data.hpp"

namespace pico_trivia {
	
	// This question appears normal to users, but indicates to me that new trivia questions need to be added
	TriviaQuestion ERROR_QUESTION = TriviaQuestion("In which year was the first iPhone released?", "2007", {"2005", "2009", "2010"}, &tech_theme);
	
	std::array<TriviaQuestion, 25> trivia_questions = {
		TriviaQuestion("What is the approximate diameter of a water molecule?", "0.27 nanometers", {"4.2 angstroms", "35 picometers", "315 picometers"}, &H2O_theme),
		TriviaQuestion("In what year was the first moon landing?", "1969", {"1974", "1959", "1962"}, &space_theme),
		TriviaQuestion("Which of the following is not a real chess opening?", "Black Tiger Attack", {"Bongcloud Attack", "Pterodactyl Defense", "Frankenstein-Dracula Variation"}, &chess_theme),
		TriviaQuestion("Approximately how many documented species of bamboo are there?", "1000", {"Exactly 1", "100", "800"}, &bamboo_theme),
		TriviaQuestion("What is the highest grossing film of all time?", "Avatar", {"Avengers Endgame", "Titanic", "The Force Awakens"}, &movie_theme),
		TriviaQuestion("Approximately up to how tall can the world's tallest species of bamboo grow?", "50 meters", {"5 meters", "15 meters", "25 meters"}, &bamboo_theme),
		TriviaQuestion("What material was this device's case 3d printed from?", "Polylactic Acid", {"Nylon", "Polycarbonate", "Polypropylene"}, &tech_theme),
		TriviaQuestion("In what year was the first Star Wars movie released?", "1977", {"2002", "1969", "1985"}, &space_theme),
		TriviaQuestion("How many bones do sharks have in their bodies?", "0", {"235", "206", "1095"}, &H2O_theme),
		TriviaQuestion("Who is the highest rated chess player of all time?", "Magnus Carlsen", {"Bobby Fischer", "Garry Kasparov", "Hikaru Nakamura"}, &chess_theme),
		TriviaQuestion("What was the original name of the Google search engine?", "BackRub", {"Alphabet", "WebCrawler", "JumpStation"}, &tech_theme),
		TriviaQuestion("What type of photosynthesis does bamboo use?", "C3", {"C4", "C2", "CAM"}, &bamboo_theme),
		TriviaQuestion("What song plays in the opening credits of Guardians of the Galaxy?", "Come and Get Your Love", {"Back in Black", "Hooked on a Feeling", "Blitzkrieg Bop"}, &movie_theme),
		TriviaQuestion("Which European country technically shares a border with Brazil?", "France", {"Portgual", "Spain", "Italy"}, &space_theme),
		TriviaQuestion("How much RAM does this device have?", "256 kilobytes", {"2 megabytes", "64 kilobytes", "1 gigabyte"}, &tech_theme),
		TriviaQuestion("In chess, what is the shortest possible number of moves for a checkmate?", "2", {"3", "4", "6"}, &chess_theme),
		TriviaQuestion("Does saltwater or freshwater freeze faster?", "Saltwater", {"Freshwater", "They freeze at the same temperature", "Depends on the exact salt concentration"}, &H2O_theme),
		TriviaQuestion("Which of the following molecules is not found in bamboo?", "C12H22O11", {"H2O", "(C6H10O5)n", "SiO2"}, &bamboo_theme),
		TriviaQuestion("For what movie did Steven Spielberg win his first Oscar for Best Director", "Schindler's List", {"Tintin", "Indiana Jones", "ET"}, &movie_theme),
		TriviaQuestion("Who is credited with inventing the first compiler for a computer programming language?", "Grace Hopper", {"Alan Turing", "George Bool", "Charles Babbage"}, &tech_theme),
		TriviaQuestion("Approximately how many years old is the universe believed to be?", "13.8 billion", {"12.5 billion", "7.3 billion", "890 million"}, &space_theme),
		TriviaQuestion("Which of the following countries is bamboo not natively found?", "Germany", {"United States", "China", "Australia"}, &bamboo_theme),
		TriviaQuestion("When did halloween first come to the United States?", "1840s", {"1780s", "1600s", "1890s"}, &halloween_theme),
		TriviaQuestion("How long does it take light to travel to the Earth from the Sun?", "8 minutes", {"3 seconds", "2 milliseconds", "14 minutes"}, &space_theme),
		TriviaQuestion("What was the first feature length animated movie ever released?", "Snow White", {"Lion King", "Nemo", "Cinderella"}, &movie_theme),
	};
}
		

