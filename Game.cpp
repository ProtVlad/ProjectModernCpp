#include "Game.h"

Game::Game(uint16_t timer, uint16_t indexDrawer, uint16_t round, 
	std::vector<std::string> wordList, std::vector<std::string> wordChoices, Chat chat):
	m_timer(timer),
	m_indexDrawer(indexDrawer),
	m_round(round),
	m_wordList(wordList),
	m_wordChoices(wordChoices),
	m_chat(chat)
{}
