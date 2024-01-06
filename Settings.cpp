#include "Settings.h"
#include <vector>



Settings::Settings()
{
	//EMPTY
}

Settings::Settings(uint16_t time,
	uint16_t language,
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

uint16_t Settings::GetLanguage()
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
	m_time = time;
}

void Settings::SetLanguage(uint16_t language)
{
	m_language = language;
}

void Settings::SetNumberPlayers(uint16_t numberPlayers)
{
	m_maxNumberPlayers = numberPlayers;
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
	m_numberWords = numberWords;
}

void Settings::SetNumberHints(uint16_t numberHints)
{
	m_numberHints = numberHints;
}


















