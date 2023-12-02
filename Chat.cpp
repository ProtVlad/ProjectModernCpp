#include "Chat.h"
#include "Player.h"

Chat::Chat()
{
	//EMPTY
}

const std::vector<Player>& Chat::GetPlayerList()
{
	return m_playerList;
}


void Chat::ShowOpinion(Player player)
{
	if (player.getOpinion() == ConvertStringToOpinion("Like"))
		std::cout << player.getName() << " liked the drawing";
	if (player.getOpinion() == ConvertStringToOpinion("Dislike"))
		std::cout << player.getName() << " disliked the drawing";
}



Chat::~Chat()
{
	m_playerList.clear();
}


