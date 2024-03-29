#pragma once
#include <vector>
#include <string>
#include "Settings.h"
#include "PointsDLL/Points.h"

class Game
{
public:

	Game();


	Game(std::string roomcode, uint16_t timer, uint16_t indexDrawer, Settings settings, std::string gameState
	/* std::vector<uint16_t> anteriorWordsChoices, Chat chat*/);

	const std::string& GetRoomcode() const;
	const uint16_t GetIndexDrawer() const;
	const Settings GetSettings() const;
	const std::vector<std::string>& GetUsers() const;
	const std::vector<std::string>& GetGuesses() const;
	const std::string& GetGameState() const;
	const std::vector<Points>& GetPoints()const; 
	const uint16_t GetTimer()const;
	const std::vector<std::string>& GetChosenWords() const;
	//const std::vector<std::string>& GetWordList();
	//const std::vector<std::string>& GetWordChoices();
	//const Chat& GetChat();

	void SetRoomcode(const std::string roomcode);
	void SetTimer(const uint16_t timer);
	void SetIndexDrawer(const uint16_t indexDrawer);
	void SetSettings(const Settings settings);
	void SetGameState(const std::string gameState);
	//void SetWordList(const std::vector<std::string>& wordList);
	//void SetWordChoices(const std::vector<std::string>& wordChoices);
	//void SetChat(const Chat& chat);

	void AddPlayer(const std::string& user);
	void AddGuess(const std::string& guess);
	void AddPoint(const Points& point);
	void AddChosenWord(const std::string& word);
	//void ReadWordList(std::ifstream& file);
	std::vector<uint16_t> TotalScore(const std::vector<std::vector<uint16_t>>& scores);

private:
	uint16_t GenerateRandomNumber(uint16_t min, uint16_t max);

private:
	std::string m_roomcode;
	uint16_t m_indexDrawer;
	Settings m_settings;
	std::vector<std::string> m_users;
	std::vector<std::string> m_guesses;
	std::vector<std::string> m_chosenWords;
	//std::vector<uint16_t> m_anteriorWordsChoices;
	//std::vector<uint16_t> m_wordsChoices;
	std::string m_gameState;
	std::vector<Points> m_points;
	uint16_t m_timer;
};

