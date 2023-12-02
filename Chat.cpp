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
	if (player.GetOpinion() == ConvertStringToOpinion("Like"))
		std::cout << player.GetName() << " liked the drawing";
	if (player.GetOpinion() == ConvertStringToOpinion("Dislike"))
		std::cout << player.GetName() << " disliked the drawing";
}



Chat::~Chat()
{
	m_playerList.clear();
}


