#include "Player.h"

Player::Player()
{
	m_name = "random";
	m_score = 0;
	m_drawOrNot = false;
	m_rank = 0;
	m_color = "white";
}

Player::Player(std::string name, uint16_t score, bool drawOrNot, uint16_t rank, std::string color) :
	m_name(name),
	m_score(score),
	m_drawOrNot(drawOrNot),
	m_rank(rank),
	m_color(color)
{
}

Player::Player(std::string name) :
	m_name(name),
	m_score(0),
	m_drawOrNot(false),
	m_rank(0),
	m_color("white")
{
}

