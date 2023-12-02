#include "AnswerChat.h"
#include "Player.h"

AnswerChat::AnswerChat()
{
	//EMPTY
}

AnswerChat::AnswerChat(std::string guess, bool isDrawing,
	bool right, bool close, std::vector<Player> playerList, std::string rightWord) :
	m_guess(guess),
	m_isDrawing(isDrawing),
	m_right(right),
	m_close(close),
	m_playerList(playerList),
	m_rightWord(rightWord)
{
}

const std::string& AnswerChat::GetGuess()
{
	return m_guess;
}

const std::vector<Player>& AnswerChat::GetPlayerList()
{
	return m_playerList;
}

const std::string& AnswerChat::GetRightWord()
{
	return m_rightWord;
}

void AnswerChat::SetIsDrawing(bool isDrawing)
{
	m_isDrawing = isDrawing;
}

void AnswerChat::ShowOpinion(Player player)
{
	if (player.GetOpinion() == ConvertStringToOpinion("Like"))
		std::cout << player.GetName() << " liked the drawing";
	if (player.GetOpinion() == ConvertStringToOpinion("Dislike"))
		std::cout << player.GetName() << " disliked the drawing";
}

void AnswerChat::ShowGuess(Player player, std::string guess)
{
	std::cout << player.GetName() << ": " << guess;
}

bool AnswerChat::IsClose()
{
	return m_close;
}

bool AnswerChat::IsRight()
{
	return m_right;
}

AnswerChat::~AnswerChat()
{
	m_playerList.clear();
}

int AnswerChat::CalculateScore(Player player, uint16_t maxTime)
{
	if (IsRight() && player.GetAnswerTime() <= maxTime / 2)
		return 100;
	if (IsRight() && player.GetAnswerTime() > maxTime / 2)
		return ((maxTime - player.GetAnswerTime()) * 100) / (maxTime / 2);
	if (player.GetAnswerTime() == maxTime)
		return -50;
}