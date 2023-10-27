#include "Chat.h"

Chat::Chat(std::vector<std::string> guesses, std::vector<std::pair<Player, std::string>> playerActivity,
	bool right, bool close, std::vector<Player> playerList, std::string rightWord) :
	m_guesses(guesses),
	m_playerActivity(playerActivity),
	m_right(right),
	m_close(close),
	m_playerList(playerList),
	m_rightWord(rightWord)
{

Chat::~Chat()
{
	m_guesses.clear();
	m_playerActivity.clear();
	m_playerList.clear();
}
