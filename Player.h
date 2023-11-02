#pragma once
#include<string>
#include "Color.h"
#include"Opinion.h"
class Player
{
public:
	Player();
	Player(std::string name, uint16_t score, bool drawOrNot, uint16_t rank, Color color, Opinion opinion);
	Player(std::string name);
	void setName(const std::string& name);
	const std::string& getName();

	void setScore(uint16_t score);
	uint16_t getScore();

	void setDrawOrNot(bool drawOrNot);
	bool getDrawOrNot();

	void setRank(uint16_t rank);
	uint16_t getRank();

	void setColor(Color color);
	Color  getColor() const;

	void setOpinion(Opinion opinion);
	Opinion getOpinion() const;

	void setAnswerTime(uint16_t answerTime);
	uint16_t getAnswerTime();

private:
	std::string m_name;
	uint16_t m_score;
	bool m_drawOrNot;
	uint16_t m_rank;
	Color m_color;
	Opinion  m_opinion;
	uint16_t m_answerTime;

};

