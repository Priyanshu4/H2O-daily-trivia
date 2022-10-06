#include "trivia_question.hpp"
#include <algorithm>

std::array<std::string, NUM_ANSWER_CHOICES> pico_trivia::TriviaQuestion::get_shuffled_answer_choices() 
{
	std::array<std::string, NUM_ANSWER_CHOICES> answer_choices;
    for (int i = 0; i < NUM_WRONG_ANSWER_CHOICES; i++) answer_choices[i] = wrong_answers[i];
	answer_choices[NUM_ANSWER_CHOICES-1] = correct_answer;
	std::random_shuffle(std::begin(answer_choices), std::end(answer_choices));
	return answer_choices;
}
			
pico_trivia::TriviaQuestion& pico_trivia::TriviaQuestion::operator=(const TriviaQuestion& other)
{
	question = other.question;
	correct_answer = other.correct_answer;
	wrong_answers = other.wrong_answers;
	return *this;
}