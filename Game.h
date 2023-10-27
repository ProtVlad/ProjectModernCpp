#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <fstream>

class Game
{
public:
	Game(uint16_t timer, uint16_t m_indexDrawer, uint16_t m_round,
		std::vector<std::string> wordList, std::vector<std::string> wordChoices, Chat chat);
private:
	uint16_t m_timer;
	uint16_t m_indexDrawer;
	uint16_t m_round;
	std::vector <std::string> m_wordList;
	std::vector <std::string> m_wordChoices;
	Chat m_chat;
};

