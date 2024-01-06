#include "Settings.h"
#include <vector>



Settings::Settings()
{
	//EMPTY
}

Settings::Settings(uint16_t time,
	uint16_t language,
	uint16_t numberPlayers,
	uint16_t numberWords,
	uint16_t numberHints):
	m_time(time),
	m_language(language),
	m_maxNumberPlayers(numberPlayers),
	m_numberWords(numberWords),
	m_numberHints(numberHints)
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

uint16_t Settings::GetNumberWords()
{
	return m_numberWords;
}

uint16_t Settings::GetNumberHints()
{
	return m_numberHints;
}

const uint16_t Settings::GetNumberRounds()
{
	return m_numberRounds;
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

void Settings::SetNumberWords(uint16_t numberWords)
{
	m_numberWords = numberWords;
}

void Settings::SetNumberHints(uint16_t numberHints)
{
	m_numberHints = numberHints;
}

void Settings::SetNumberRounds(uint16_t numberRounds)
{
	m_numberRounds = numberRounds;
}


















