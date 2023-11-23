#include "Game.h"
#include<ctime>
#include <random>
Game::Game()
{
	//EMPTY
}

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

void Game::readWordList(std::ifstream& file)
{
	while (!file.eof())
	{
		std::string element;
		std::getline(file, element);
		m_wordList.emplace_back(element);
	}
}

std::vector<uint16_t> Game::totalScore(const std::vector<std::vector<uint16_t>>& playerScores)
{
	std::vector<uint16_t> scores;
	for (uint16_t player = 0; player < playerScores.size(); player++)
	{
		uint16_t score = 0;
		for (uint16_t round = 0; round < playerScores[player].size(); round++)
			score += playerScores[player][round];
		scores.emplace_back(score);
	}
	return scores;
}

uint16_t Game::numberLines(std::ifstream& file)
{
	uint16_t numLines = 0;
	std::string line;
	while (std::getline(file, line))
		numLines++;
	return numLines;
}

uint16_t Game::GenerateRandomNumber(uint16_t min, uint16_t max)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<uint16_t> distribution(min, max);
	int randomValue = distribution(generator);
	return randomValue;
}

void Game::chooseWords()
{
	uint16_t min = 0;
	std::ifstream file("RoWords.txt");
	uint16_t max = numberLines(file);
	uint16_t nr = m_settings.getNumberWords();
	for (uint16_t index = 0; index < nr; index++)
	{
		uint16_t p = GenerateRandomNumber(min, max);
		std::string cuv = m_wordList[p];
		m_wordChoices.emplace_back(cuv);
	}
}
