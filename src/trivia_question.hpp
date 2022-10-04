#include <string>
#include <array>
#include <algorithm>
#include "assets_data/themes_data.hpp"

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
			TriviaQuestion(std::string question, std::string correct_answer, std::array<std::string, NUM_WRONG_ANSWER_CHOICES> wrong_answers, pico_trivia::Theme *theme = default_theme_ptr)
				: question(question)
				, correct_answer(correct_answer)
				, wrong_answers(wrong_answers) 
				, theme(theme)
				{}
			std::array<std::string, NUM_ANSWER_CHOICES> get_shuffled_answer_choices() 
			{
				std::array<std::string, NUM_ANSWER_CHOICES> answer_choices;
				for (int i = 0; i < NUM_WRONG_ANSWER_CHOICES; i++) answer_choices[i] = wrong_answers[i];
				answer_choices[NUM_ANSWER_CHOICES-1] = correct_answer;
				std::random_shuffle(std::begin(answer_choices), std::end(answer_choices));
				return answer_choices;
			}
			TriviaQuestion& operator=(const TriviaQuestion& other)
			{
				question = other.question;
				correct_answer = other.correct_answer;
				wrong_answers = other.wrong_answers;
				return *this;
			}
	};
	
}
