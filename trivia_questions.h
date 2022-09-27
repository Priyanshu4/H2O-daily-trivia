#include <string>
#include <array>

# define NUM_WRONG_ANSWER_CHOICES 3

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
	};

	// TODO: python scripts for trivia question generation
	std::array<TriviaQuestion, 1> trivia_questions = {
		TriviaQuestion("1 + 1", "2", {"0", "1", "4"})
	};
		
}
