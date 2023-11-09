#include "Game.h"

Game::Game(uint16_t timer, uint16_t indexDrawer, Settings settings, 
	std::vector<std::string> wordList, std::vector<std::string> wordChoices, Chat chat):
	m_timer(timer),
	m_indexDrawer(indexDrawer),
	m_settings(settings),
	m_wordList(wordList),
	m_wordChoices(wordChoices),
	m_chat(chat)
{}

const uint16_t Game::getTimer()
{
	return m_timer;
}

const std::vector<std::string>& Game::getWordList()
{
	return m_wordList;
}

const std::vector<std::string>& Game::getWordChoices()
{
	return m_wordChoices;
}

const Chat& Game::getChat()
{
	return m_chat;
}

const uint16_t Game::getIndexDrawer()
{
	return m_indexDrawer;
}

void Game::setTimer(const uint16_t timer)
{
	m_timer = timer;
}

void Game::setWordList(const std::vector<std::string>& wordList)
{
	m_wordList = wordList;
}

void Game::setWordChoices(const std::vector<std::string>& wordChoices)
{
	m_wordChoices = wordChoices;
}

void Game::setChat(const Chat& chat)
{
	m_chat = chat;
}

void Game::setIndexDrawer(const uint16_t indexDrawer)
{
	m_indexDrawer = indexDrawer;
}

uint16_t Game::totalScore(Player player, const uint16_t maxRounds)
{
	uint16_t score=0;
	for (uint16_t round=0;round<maxRounds;round++)
		score += player.getScore()[round];
	return score;
}


