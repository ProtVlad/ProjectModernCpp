#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

#pragma once
class Chat
{

public:
	Chat();
	const std::vector<Player>& GetPlayerList();
	void ShowOpinion(Player player);
	~Chat();

private:
	std::vector<Player> m_playerList;

};