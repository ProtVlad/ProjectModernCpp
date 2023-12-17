#include <iostream>
#include <vector>
#include "Player.h"

#pragma once
class AnswerChat
{

public:
	AnswerChat();
	AnswerChat(std::string guess, bool isDrawing,
		bool right, bool close, std::vector<Player> playerList, std::string rightWord);
	const std::string& GetGuess();
	const std::vector<Player>& GetPlayerList();
	const std::string& GetRightWord();
	void SetIsDrawing(bool isDrawing);
	void ShowOpinion(Player player);
	void ShowGuess(Player player, std::string guess);
	bool IsClose();
	bool IsRight();
	~AnswerChat();
	int CalculateScore(Player player, uint16_t maxTime);

private:
	std::string m_guess;
	bool m_right, m_close, m_isDrawing;
	std::vector<Player> m_playerList;
	std::string m_rightWord;
};