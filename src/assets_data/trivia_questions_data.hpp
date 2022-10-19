#pragma once
#include "trivia_question.hpp"
#include "themes_data.hpp"

namespace pico_trivia {
	
	// This question appears normal to users, but indicates to me that new trivia questions need to be added
	TriviaQuestion ERROR_QUESTION = TriviaQuestion("In which year was the first iPhone released?", "2007", {"2005", "2009", "2010"}, &tech_theme);
	
	std::array<TriviaQuestion, 27> trivia_questions = {
		TriviaQuestion("How many bones do sharks have in their bodies?", "0", {"235", "206", "1095"}, &H2O_theme),
		TriviaQuestion("What is the highest grossing film of all time?", "Avatar", {"Avengers Endgame", "Titanic", "The Force Awakens"}, &movie_theme),
		TriviaQuestion("How many countries have landed on the moon?", "3", {"1", "2", "4"}, &space_theme),
		TriviaQuestion("What is the most commonly used word in the english language?", "the", {"a", "I", "is"}, &generic_theme),
		TriviaQuestion("In what year did Apple release its first computer, the Apple I?", "1976", {"1983", "1996", "2004"}, &tech_theme),
		TriviaQuestion("What was the first feature length animated movie ever released?", "Snow White", {"Lion King", "Nemo", "Cinderella"}, &movie_theme),
		TriviaQuestion("Which of the following countries is bamboo not natively found?", "Germany", {"United States", "China", "Australia"}, &bamboo_theme),
		TriviaQuestion("Which country drinks the most coffee per person?", "Finland", {"United States", "Italy", "Canada"}, &generic_theme),
		TriviaQuestion("In what year was the first Star Wars movie released?", "1977", {"2002", "1969", "1985"}, &space_theme),
		TriviaQuestion("What was the original name of the Google search engine?", "BackRub", {"Alphabet", "WebCrawler", "JumpStation"}, &tech_theme),
		TriviaQuestion("Which country has won the most FIFA world cups?", "Brazil", {"Argentina", "Germany", "Italy"}, &sports_theme),
		TriviaQuestion("What was the first soda consumed in space?", "Coca-Cola", {"Pepsi", "Dr Pepper", "Sprite"}, &space_theme),
		TriviaQuestion("What song plays in the opening credits of Guardians of the Galaxy?", "Come and Get Your Love", {"Back in Black", "Hooked on a Feeling", "Blitzkrieg Bop"}, &movie_theme),
		TriviaQuestion("Which video on youtube has the the most views?", "Baby Shark Dance", {"Gangam Style", "Despacito", "Uptown Funk"}, &generic_theme),
		TriviaQuestion("Which carnivorous plant can digest not only insects, but also lizards and rodents?", "Pitcher Plant", {"Venus Flyrap", "Cobra Lily", "Portuguese Sundew"}, &generic_theme),
		TriviaQuestion("Which two states don't observe daylight savings time?", "Arizona and Hawaii", {"Hawaii and Alaska", "Florida and Texas", "California and Nevada"}, &generic_theme),
		TriviaQuestion("In what year was the first moon landing?", "1969", {"1974", "1959", "1962"}, &space_theme),
		TriviaQuestion("Which popular kid's show did Stephen Hillenburg create?", "Spongebob Squarepants", {"Dora the Explorer", "Power Rangers", "Sesame Street"}, &generic_theme),
		TriviaQuestion("Which European country technically shares a border with Brazil?", "France", {"Portgual", "Spain", "Italy"}, &space_theme),
		TriviaQuestion("Which tech company used the motto \"Think Different\" from 1997 to 2002?", "Apple", {"Google", "Microsoft", "Intel"}, &tech_theme),
		TriviaQuestion("Approximately up to how tall can the world's tallest species of bamboo grow?", "50 meters", {"5 meters", "15 meters", "25 meters"}, &bamboo_theme),
		TriviaQuestion("How long does it take light to travel to the Earth from the Sun?", "8 minutes", {"3 seconds", "2 milliseconds", "14 minutes"}, &space_theme),
		TriviaQuestion("When did halloween first come to the United States?", "1840s", {"1780s", "1600s", "1890s"}, &halloween_theme),
		TriviaQuestion("How many stomachs do cows have?", "4", {"7", "2", "1"}, &generic_theme),
		TriviaQuestion("How often does a full moon occur?", "Every 29.5 days", {"Exactly 12 times an year", "Every 27 days", "Every 30.5 days"}, &space_theme),
		TriviaQuestion("Which of the following languages is not written from right to left?", "Indonesian", {"Hebrew", "Arabic", "Farsi"}, &generic_theme),
		TriviaQuestion("What is the name of the field outside Werth?", "Nancy Stevens Field", {"Peter J. Werth Field", "Harry L. Garrigus Field", "Diane Wright Field"}, &sports_theme),

	};
}
		


