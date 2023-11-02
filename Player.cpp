#include "Player.h"

Player::Player()
{
	m_name = "random";
	m_score = 0;
	m_drawOrNot = false;
	m_rank = 0;
	m_color = ConvertStringToColor("White");
	m_opinion = ConvertStringToOpinion("NoOpinion");
}

Player::Player(std::string name, uint16_t score, bool drawOrNot, uint16_t rank, Color color, Opinion opinion) :
	m_name(name),
	m_score(score),
	m_drawOrNot(drawOrNot),
	m_rank(rank),
	m_color(color),
	m_opinion(opinion)
{
}

Player::Player(std::string name) :
	m_name(name),
	m_score(0),
	m_drawOrNot(false),
	m_rank(0),
	m_color(ConvertStringToColor("White")),
	m_opinion(ConvertStringToOpinion("NoOpinion"))
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

void Player::setScore(uint16_t score)
{
	m_score = score;
}

uint16_t Player::getScore()
{
	return m_score;
}

void Player::setDrawOrNot(bool drawOrNot)
{
	m_drawOrNot = drawOrNot;
}

bool Player::getDrawOrNot()
{
	return m_drawOrNot;
}


void Player::setRank(uint16_t rank)
{
	m_rank = rank;
}

uint16_t Player::getRank()
{
	return m_rank;
}

void Player::setColor(Color color)
{
	m_color = color;
}

Color Player::getColor() const
{
	return m_color;
}

void Player::setOpinion(Opinion opinion)
{
	m_opinion = opinion;
}

Opinion Player::getOpinion() const
{
	return m_opinion;
}

void Player::setAnswerTime(uint16_t answerTime)
{
	m_answerTime = answerTime;
}

uint16_t Player::getAnswerTime()
{
	return m_answerTime;
}

