#include "Round.h"

Round::Round(uint16_t timer, std::vector<uint16_t> scores) :
	m_timer(timer),
	m_scores(scores)
{
}

const uint16_t& Round::getTimer()
{
	return m_timer;
}

const std::vector<uint16_t>& Round::getScores()
{
	return m_scores;
}

const std::string& Round::getChosenWord()
{
	return m_chosenWord;
}

const std::string& Round::getHints()
{
	return m_hints;
}

void Round::setChosenWord(const std::string& chosenWord)
{
	m_chosenWord = chosenWord;
}
