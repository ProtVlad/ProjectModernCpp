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
	const uint16_t getTimer();
	const std::vector<std::string>& getWordList();
	const std::vector<std::string>& getWordChoices();
	const Chat& getChat();
	const uint16_t getIndexDrawer();
	const uint16_t getRound();
	uint16_t setTimer(const uint16_t timer);
	std::vector<std::string>& setWordList(const std::vector<std::string>& wordList);
	std::vector<std::string>& setWordChoices(const std::vector<std::string>& wordChoices);
	Chat& setChat(const Chat& chat);
	uint16_t setIndexDrawer(const uint16_t indexDrawer);
	uint16_t setRound(const uint16_t round);
private:
	uint16_t m_timer;
	uint16_t m_indexDrawer;
	uint16_t m_round;
	std::vector <std::string> m_wordList;
	std::vector <std::string> m_wordChoices;
	Chat m_chat;
};

