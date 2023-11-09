#pragma once
#include <cstdint>
#include <vector>
#include "Settings.h"
class Round
{
public:
	Round(uint16_t timer, std::vector<uint16_t> scores);
	const uint16_t& getTimer();
	const std::vector<uint16_t>& getScores();
	const std::string& getChosenWord();
	const std::string& getHints();
	void setChosenWord(const std::string& chosenWord);

private:
	std::string m_chosenWord;
	std::string m_hints;
	uint16_t m_timer;
	std::vector<uint16_t> m_scores;
};

