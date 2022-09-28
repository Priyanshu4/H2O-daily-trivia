#include <string>
#include <array>
#include <algorithm>

#define NUM_WRONG_ANSWER_CHOICES 3
#define NUM_ANSWER_CHOICES NUM_WRONG_ANSWER_CHOICES+1

namespace pico_trivia {
	
	class TriviaQuestion 
	{
		public:
			const std::string question;
			const std::string correct_answer;
			const std::array<std::string, NUM_WRONG_ANSWER_CHOICES> wrong_answers;
			TriviaQuestion(std::string question, std::string correct_answer, std::array<std::string, NUM_WRONG_ANSWER_CHOICES> wrong_answers)
				: question(question)
				, correct_answer(correct_answer)
				, wrong_answers(wrong_answers) 
				{}
			std::array<std::string, NUM_ANSWER_CHOICES> get_shuffled_answer_choices() 
			{
				std::array<std::string, NUM_ANSWER_CHOICES> answer_choices;
				for (int i = 0; i < NUM_WRONG_ANSWER_CHOICES; i++) answer_choices[i] = wrong_answers[i];
				answer_choices[NUM_ANSWER_CHOICES-1] = correct_answer;
				std::random_shuffle(std::begin(answer_choices), std::end(answer_choices));
				return answer_choices;
			}
	};

	// TODO: python scripts for trivia question generation
	std::array<TriviaQuestion, 1> trivia_questions = {
		TriviaQuestion("How many bones do sharks have in their bodies?", "0", {"235", "206", "1095"})
	};
		
}
