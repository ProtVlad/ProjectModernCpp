#pragma once
#include <cstdint>
#include <string>

class Settings
{
public:
	Settings(uint16_t time, const std::string& language, uint16_t numberPlayers);
	uint16_t getTime();
	const std::string& getLanguage();
	uint16_t getMaxNumberPlayers();
	uint16_t getDrawtime();
	uint16_t getMaxClues();
	void setTime(uint16_t time);
	void setLanguage(const std::string& language);
	void setNumberPlayers(uint16_t maxNumberPlayers);
	void setMaxClues(uint16_t maxClues);
	void setDrawtime();

private:
	uint16_t m_time;
	std::string m_language;
	uint16_t m_maxNumberPlayers;
	uint16_t m_drawtime;
	uint16_t m_maxClues;
	
};

