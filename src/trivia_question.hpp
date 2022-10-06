#pragma once
#include <string>
#include <array>
#include "theme.hpp"

#define NUM_WRONG_ANSWER_CHOICES 3
#define NUM_ANSWER_CHOICES NUM_WRONG_ANSWER_CHOICES+1

namespace pico_trivia {
	
	class TriviaQuestion 
	{
		public:
			std::string question;
			std::string correct_answer;
			std::array<std::string, NUM_WRONG_ANSWER_CHOICES> wrong_answers;
			pico_trivia::Theme * theme;
			TriviaQuestion(std::string question, std::string correct_answer, std::array<std::string, NUM_WRONG_ANSWER_CHOICES> wrong_answers, pico_trivia::Theme *theme)
				: question(question)
				, correct_answer(correct_answer)
				, wrong_answers(wrong_answers) 
				, theme(theme)
				{}
			std::array<std::string, NUM_ANSWER_CHOICES> get_shuffled_answer_choices();
			TriviaQuestion& operator=(const TriviaQuestion& other);
	};
	
}
