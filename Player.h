#pragma once
#include<string>
class Player
{
public:
	Player();
	Player(std::string name, uint16_t score, bool drawOrNot, uint16_t rank, std::string color);
	Player(std::string name);
	void setName(const std::string& name);
	const std::string &  getName();
	void setScore(const uint16_t & score);
	const uint16_t & getScore();
	void setDrawOrNot(const bool & drawOrNot);
	const bool & getDrawOrNot();
	void setRank(const uint16_t& rank);
	const uint16_t & getRank();
	void setColor(const std::string& color);
	const std::string &  getColor();

private:
	std::string m_name;
	uint16_t m_score;
	bool m_drawOrNot;
	uint16_t m_rank;
	std::string m_color;
};

