#include "Chat.h"
#include "Player.h"

Chat::Chat()
{
	//EMPTY
}

Chat::Chat(std::string guess, std::vector<std::pair<Player, std::string>> playerActivity,
	bool right, bool close, std::vector<Player> playerList, std::string rightWord) :
	m_guess(guess),
	m_playerActivity(playerActivity),
	m_right(right),
	m_close(close),
	m_playerList(playerList),
	m_rightWord(rightWord)
{
}

const std::string& Chat::getGuess()
{
	return m_guess;
}

const std::vector<Player>& Chat::getPlayerList()
{
	return m_playerList;
}

const std::string& Chat::getRightWord()
{
	return m_rightWord;
}

void Chat::setPlayerActivity(std::vector<std::pair<Player, std::string>> playerActivity)
{
	m_playerActivity = playerActivity;
}

void Chat::ShowOpinion(Player player)
{
	if (player.getOpinion() == ConvertStringToOpinion("Like"))
		std::cout << player.getName() << " liked the drawing";
	if (player.getOpinion() == ConvertStringToOpinion("Dislike"))
		std::cout << player.getName() << " disliked the drawing";
}

void Chat::ShowGuess(Player player, std::string guess)
{
	std::cout << player.getName() << ": " << guess;
}

bool Chat::isClose()
{
	return m_close;
}

bool Chat::isRight()
{
	return m_right;
}

Chat::~Chat()
{
	m_playerActivity.clear();
	m_playerList.clear();
}

int Chat::calculateScore(Player player, uint16_t maxTime)
{
	if (isRight() && player.getAnswerTime() <= maxTime / 2)
		return 100;
	if (isRight() && player.getAnswerTime() > maxTime / 2)
		return ((maxTime - player.getAnswerTime()) * 100) / (maxTime / 2);
	if (player.getAnswerTime() == maxTime)
		return -50;
}

