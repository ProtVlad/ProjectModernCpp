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
	void SetName(const std::string& name);
	const std::string& GetName();

	void SetScore(uint16_t score);
	uint16_t GetScore();

	void SetDrawOrNot(bool drawOrNot);
	bool GetDrawOrNot();

	void SetRank(uint16_t rank);
	uint16_t GetRank();

	void SetColor(Color color);
	Color  GetColor() const;

	void SetOpinion(Opinion opinion);
	Opinion GetOpinion() const;

	void SetAnswerTime(uint16_t answerTime);
	uint16_t GetAnswerTime();

private:
	std::string m_name;
	uint16_t m_score;
	bool m_drawOrNot;
	uint16_t m_rank;
	Color m_color;
	Opinion  m_opinion;
	uint16_t m_answerTime;

};

