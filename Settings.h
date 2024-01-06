#pragma once
#include <cstdint>
#include <string>

class Settings
{
public:
	Settings();
	Settings(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
	const uint16_t GetTime();
	const uint16_t GetLanguage();
	const uint16_t GetMaxNumberPlayers();
	const uint16_t GetNumberWords();
	const uint16_t GetNumberHints();
	const uint16_t GetNumberRounds();
	void SetTime(uint16_t);
	void SetLanguage(uint16_t);
	void SetNumberPlayers(uint16_t);
	void SetNumberWords(uint16_t);
	void SetNumberHints(uint16_t);
	void SetNumberRounds(uint16_t);
	//optionHints de dezbatut
	//void optionsHints(uint16_t maxHints);
	// de dezbatut daca e nevoie
	//void choosePublicOrPrivate();
	

private:
	uint16_t m_time;
	uint16_t m_language;
	uint16_t m_maxNumberPlayers;
	uint16_t m_numberWords;
	uint16_t m_numberHints;
	uint16_t m_numberRounds;
	//bool optionPrivate;

	
};

