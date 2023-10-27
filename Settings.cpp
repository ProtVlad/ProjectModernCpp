#include "Settings.h"

Settings::Settings(uint16_t time,
	const std::string& language,
	uint16_t numberPlayers):
	m_time(time),
	m_language(language),
	m_numberPlayers(numberPlayers)
{
}

uint16_t Settings::getTime()
{
	return m_time;
}

const std::string& Settings::getLanguage()
{
	return m_language;
}

uint16_t Settings::getNumberPlayers()
{
	return m_numberPlayers;
}

void Settings::setTime(uint16_t time)
{
	m_time == time;
}

void Settings::setLanguage(const std::string& language)
{
	m_language = language;
}

void Settings::setNumberPlayers(uint16_t numberPlayers)
{
	m_numberPlayers = numberPlayers;
}










