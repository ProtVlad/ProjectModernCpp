#include "Game.h"
#include <random>

Game::Game()
{
}

Game::Game(std::string roomcode, uint16_t timer, uint16_t indexDrawer, Settings settings, std::string gameState/*,
std::vector<uint16_t> anteriorWordsChoices/, Chat chat */) :
	m_roomcode(roomcode),
	m_timer(timer),
	m_indexDrawer(indexDrawer),
	m_settings(settings),
	m_gameState(gameState)
	/*m_anteriorWordsChoices(anteriorWordsChoices),
	m_chat(chat)*/
{}

const std::string& Game::GetRoomcode() const
{
	return m_roomcode;
}

const uint16_t Game::GetIndexDrawer() const
{
	return m_indexDrawer;
}

const Settings Game::GetSettings() const
{
	return m_settings;
}

const std::vector<std::string>& Game::GetUsers() const
{
	return m_users;
}

const std::vector<std::string>& Game::GetGuesses() const
{
	return m_guesses;
}

const std::string& Game::GetGameState() const
{
	return m_gameState;
}

const std::vector<Points>& Game::GetPoints() const
{
	return m_points;
}

const GameTimer& Game::GetTimer() const
{
	return m_timer;
}

const std::vector<std::string>& Game::GetChosenWords() const
{
	return m_chosenWords;
}

/*const std::vector<std::string>& Game::GetWordList()
{
	return m_wordList;
}*/

/*const std::vector<std::string>& Game::GetWordChoices()
{
	return m_wordChoices;
}*/

/*const Chat& Game::GetChat()
{
	return m_chat;
}*/


void Game::SetRoomcode(const std::string roomcode)
{
	m_roomcode = roomcode;
}

void Game::SetTimer(const uint16_t timer)
{
	m_timer = timer;
}

void Game::SetIndexDrawer(const uint16_t indexDrawer)
{
	m_indexDrawer = indexDrawer;
}

void Game::SetSettings(const Settings settings)
{
	m_settings = settings;
}

void Game::SetGameState(const std::string gameState)
{
	m_gameState = gameState;
}

/*void Game::SetWordList(const std::vector<std::string>& wordList)
{
	m_wordList = wordList;
}*/

/*void Game::SetWordChoices(const std::vector<std::string>& wordChoices)
{
	m_wordChoices = wordChoices;
}*/

/*void Game::SetChat(const Chat& chat)
{
	m_chat = chat;
}*/


/*void Game::ReadWordList(std::ifstream& file)
{
	while (!file.eof())
	{
		std::string element;
		std::getline(file, element);
		m_wordList.emplace_back(element);
	}
}*/

void Game::AddPlayer(const std::string& user)
{
	m_users.push_back(user);
}

void Game::AddGuess(const std::string& guess)
{
	m_guesses.push_back(guess);
}

void Game::AddPoint(const Points& point)
{
	m_points.push_back(point);
}

void Game::AddChosenWord(const std::string& word)
{
	m_chosenWords.push_back(word);
}

std::vector<uint16_t> Game::TotalScore(const std::vector<std::vector<uint16_t>>& playerScores)
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

uint16_t Game::GenerateRandomNumber(uint16_t min, uint16_t max)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<uint16_t> distribution(min, max);
	int randomValue = distribution(generator);
	return randomValue;
}

//void Game::ChooseWords()
//{
//	uint16_t min = 1;
//	Storage db = createStorage("words.sqlite");
//	uint16_t max = db.count<Word>();
//	uint16_t nr = m_settings.GetNumberWords();
//	for (uint16_t index = 0; index < nr; index++)
//	{
//		uint16_t p = GenerateRandomNumber(min, max);
//		int cuv = db.get<Word>(p).id;
//		m_wordsChoices.emplace_back(cuv);
//	}
//}
