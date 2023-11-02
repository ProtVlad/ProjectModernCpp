#pragma once
#include <cstdint>
#include <vector>
class Round
{
public:
	Round(uint16_t timer, std::vector<uint16_t> scores);
	const uint16_t& getTimer();
	const std::vector<uint16_t>& getScores();

private:
	uint16_t m_timer;
	std::vector<uint16_t> m_scores;
};

