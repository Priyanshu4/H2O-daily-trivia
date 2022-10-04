#pragma once
#include "trivia_question.hpp"

namespace pico_trivia {
	
	// This question appears normal to users, but indicates to me that new trivia questions need to be added
	TriviaQuestion ERROR_QUESTION = TriviaQuestion("In which year was the first iPhone released?", "2007", {"2005", "2009", "2010"});
	
	std::array<TriviaQuestion, 1> trivia_questions = {
		TriviaQuestion("How many bones do sharks have in their bodies?", "0", {"235", "206", "1095"})
	};
	
	TriviaQuestion get_todays_question(int daynumber)
	{
		if (daynumber < 0 || daynumber >= trivia_questions.size())
		{
			return ERROR_QUESTION;
		}
		return trivia_questions[daynumber];
	}
}
		

