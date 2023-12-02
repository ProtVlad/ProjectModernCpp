#include "Settings.h"
#include <vector>



Settings::Settings()
{
	//EMPTY
}

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
	switch (time) {
	case 20:
		m_time = 20;
		break;
	case 30:
		m_time = 30;
		break;
	case 40:
		m_time = 40;
		break;
	case 50:
		m_time = 50;
		break;
	case 60:
		m_time = 60;
		break;
	case 70:
		m_time = 70;
		break;
	case 80:
		m_time = 80;
		break;
	default:

		break;
	}
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

void Settings::setNumberWords(uint16_t numberWords)
{
	switch (numberWords) {
	case 1:
		m_numberWords = 1;
		break;
	case 2:
		m_numberWords = 2;
		break;
	case 3:
		m_numberWords = 3;
		break;
	case 4:
		m_numberWords = 4;
		break;
	case 5:
		m_numberWords = 5;
		break;

	default:

		break;
	}
}

void Settings::setNumberHints(uint16_t numberHints)
{
	m_numberHints = numberHints;
}


















