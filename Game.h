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
	const uint16_t GetTimer();
	const std::vector<std::string>& GetWordList();
	const std::vector<std::string>& GetWordChoices();
	const Chat& GetChat();
	const uint16_t GetIndexDrawer();
	void SetTimer(const uint16_t timer);
	void SetWordList(const std::vector<std::string>& wordList);
	void SetWordChoices(const std::vector<std::string>& wordChoices);
	void SetChat(const Chat& chat);
	void SetIndexDrawer(const uint16_t indexDrawer);
	void ReadWordList(std::ifstream& file);
	std::vector<uint16_t> TotalScore(const std::vector<std::vector<uint16_t>>& scores);
	uint16_t NumberLines(std::ifstream& file);
	void ChooseWords();
private:
	uint16_t GenerateRandomNumber(uint16_t min, uint16_t max);
private:
	uint16_t m_timer;
	uint16_t m_indexDrawer;
	Settings m_settings;
	std::vector <std::string> m_wordList;
	std::vector <std::string> m_wordChoices;
	Chat m_chat;
};

