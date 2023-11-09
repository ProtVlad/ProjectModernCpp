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
