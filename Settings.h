#pragma once
#include <cstdint>
#include <string>

class Settings
{
public:
	Settings(uint16_t time, const std::string& language, uint16_t numberPlayers);
	uint16_t getTime();
	const std::string& getLanguage();
	uint16_t getNumberPlayers();
	void setTime(uint16_t time);
	void setLanguage(const std::string& language);
	void setNumberPlayers(uint16_t numberPlayers);

private:
	uint16_t m_time;
	std::string m_language;
	uint16_t m_numberPlayers;
};

