#include "Settings.h"

Settings::Settings(uint16_t time,
	const std::string& language,
	uint16_t numberPlayers):
	m_time(time),
	m_language(language),
	m_maxNumberPlayers(numberPlayers)
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

uint16_t Settings::getMaxNumberPlayers()
{
	return m_maxNumberPlayers;
}

uint16_t Settings::getDrawtime()
{
	return m_drawtime;
}

uint16_t Settings::getMaxClues()
{
	return m_maxClues;
}

uint16_t Settings::getNumberWords()
{
	return m_numberWords;
}

uint16_t Settings::getNumberHints()
{
	return m_numberHints;
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
	m_maxNumberPlayers = numberPlayers;
}

void Settings::setMaxClues(uint16_t maxClues)
{
	m_maxClues = maxClues;
}

void Settings::setDrawtime(uint16_t drawtime)
{
	m_drawtime = drawtime;
}

void Settings::setNumberWods(uint16_t numberWords)
{
	m_numberWords = numberWords;
}

void Settings::setNumberHints(uint16_t numberHints)
{
	m_numberHints = numberHints;
}










