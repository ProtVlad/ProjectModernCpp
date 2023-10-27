#include <string>
#include <vector>

#pragma once
class Chat
{

public:
	Chat(std::vector<std::string> guesses, std::vector<std::pair<Player, std::string>> playerActivity,
		bool right, bool close, std::vector<Player> playerList, std::string rightWord);
	const std::vector<std::string>& getGuesses();
	const std::vector<Player>& getPlayerList();
	const std::string& getRightWord();
	void setPlayerActivity(std::vector<std::pair<Player, std::string>> playerActivity);
	~Chat();

private:
	std::vector<std::string> m_guesses;
	std::vector<std::pair<Player, std::string>> m_playerActivity;
	bool m_right, m_close;
	std::vector<Player> m_playerList;
	std::string m_rightWord;
};