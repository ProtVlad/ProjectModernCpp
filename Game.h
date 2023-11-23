#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <fstream>
#include "Chat.h"
#include "Player.h"
#include "Settings.h"

class Game
{
public:
	Game();
	Game(uint16_t timer, uint16_t m_indexDrawer, Settings m_settings,
		std::vector<std::string> wordList, std::vector<std::string> wordChoices, Chat chat);
	const uint16_t getTimer();
	const std::vector<std::string>& getWordList();
	const std::vector<std::string>& getWordChoices();
	const Chat& getChat();
	const uint16_t getIndexDrawer();
	void setTimer(const uint16_t timer);
	void setWordList(const std::vector<std::string>& wordList);
	void setWordChoices(const std::vector<std::string>& wordChoices);
	void setChat(const Chat& chat);
	void setIndexDrawer(const uint16_t indexDrawer);
	void readWordList(std::ifstream& file);
	std::vector<uint16_t> totalScore(const std::vector<std::vector<uint16_t>>& scores);
private:
	uint16_t m_timer;
	uint16_t m_indexDrawer;
	Settings m_settings;
	std::vector <std::string> m_wordList;
	std::vector <std::string> m_wordChoices;
	Chat m_chat;
};

