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

void Player::SetName(const std::string& name)
{
	m_name = name;
}

const std::string& Player::GetName()
{
	return m_name;
}

void Player::SetScore(uint16_t score)
{
	m_score = score;
}

uint16_t Player::GetScore()
{
	return m_score;
}

void Player::SetDrawOrNot(bool drawOrNot)
{
	m_drawOrNot = drawOrNot;
}

bool Player::GetDrawOrNot()
{
	return m_drawOrNot;
}


void Player::SetRank(uint16_t rank)
{
	m_rank = rank;
}

uint16_t Player::GetRank()
{
	return m_rank;
}

void Player::SetColor(Color color)
{
	m_color = color;
}

Color Player::GetColor() const
{
	return m_color;
}

void Player::SetOpinion(Opinion opinion)
{
	m_opinion = opinion;
}

Opinion Player::GetOpinion() const
{
	return m_opinion;
}

void Player::SetAnswerTime(uint16_t answerTime)
{
	m_answerTime = answerTime;
}

uint16_t Player::GetAnswerTime()
{
	return m_answerTime;
}

