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

uint16_t Settings::GetTime()
{
	return m_time;
}

const std::string& Settings::GetLanguage()
{
	return m_language;
}

uint16_t Settings::GetMaxNumberPlayers()
{
	return m_maxNumberPlayers;
}

uint16_t Settings::GetDrawtime()
{
	return m_drawtime;
}

uint16_t Settings::GetMaxClues()
{
	return m_maxClues;
}

uint16_t Settings::GetNumberWords()
{
	return m_numberWords;
}

uint16_t Settings::GetNumberHints()
{
	return m_numberHints;
}

void Settings::SetTime(uint16_t time)
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

void Settings::SetLanguage(const std::string& language)
{
	m_language = language;
}

void Settings::SetNumberPlayers(uint16_t numberPlayers)
{
	switch (numberPlayers) {
	case 2:
		m_maxNumberPlayers = numberPlayers;
		break;
	case 3:
		m_maxNumberPlayers = numberPlayers;
		break;
	case 4:
		m_maxNumberPlayers = numberPlayers;
		break;
	case 5:
		m_maxNumberPlayers = numberPlayers;
		break;
	case 6:
		m_maxNumberPlayers = numberPlayers;
		break;
	case 7:
		m_maxNumberPlayers = numberPlayers;
		break;
	case 8:
		m_maxNumberPlayers = numberPlayers;
		break;

	default:

		break;
	}
}

void Settings::SetMaxClues(uint16_t maxClues)
{
	m_maxClues = maxClues;
}

void Settings::SetDrawtime(uint16_t drawtime)
{
	m_drawtime = drawtime;
}

void Settings::SetNumberWords(uint16_t numberWords)
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

void Settings::SetNumberHints(uint16_t numberHints)
{
	m_numberHints = numberHints;
}


















