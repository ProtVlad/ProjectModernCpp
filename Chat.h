#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

#pragma once
class Chat
{

public:
	Chat(std::string guess, std::vector<std::pair<Player, std::string>> playerActivity,
		bool right, bool close, std::vector<Player> playerList, std::string rightWord);
	const std::string& getGuess();
	const std::vector<Player>& getPlayerList();
	const std::string& getRightWord();
	void setPlayerActivity(std::vector<std::pair<Player, std::string>> playerActivity);
	void ShowOpinion(Player player);
	void ShowGuess(Player player, std::string guess);
	~Chat();

private:
	std::string m_guess;
	std::vector<std::pair<Player, std::string>> m_playerActivity;
	bool m_right, m_close;
	std::vector<Player> m_playerList;
	std::string m_rightWord;
};