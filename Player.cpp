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

void Player::setName(const std::string& name)
{
	m_name = name;
}

const std::string& Player::getName()
{
	return m_name;
}

void Player::setScore(const uint16_t& score)
{
	m_score = score;
}

const uint16_t& Player::getScore()
{
	return m_score;
}

void Player::setDrawOrNot(const bool& drawOrNot)
{
	m_drawOrNot = drawOrNot;
}

const bool& Player::getDrawOrNot()
{
	return m_drawOrNot;
}

void Player::setRank(const uint16_t rank)
{
	m_rank = rank;
}

const uint16_t& Player::getRank()
{
	return m_rank;
}

void Player::setColor(const std::string& color)
{
	m_color = color;
}

const std::string& Player::getColor()
{
	return m_color;
}