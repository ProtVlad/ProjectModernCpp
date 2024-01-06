#pragma once
#include <cstdint>
#include <string>

class Settings
{
public:
	Settings();
	Settings(uint16_t, uint16_t, uint16_t);
	uint16_t GetTime();
	uint16_t GetLanguage();
	uint16_t GetMaxNumberPlayers();
	uint16_t GetDrawtime();
	uint16_t GetMaxClues();
	uint16_t GetNumberWords();
	uint16_t GetNumberHints();
	void SetTime(uint16_t);
	void SetLanguage(uint16_t);
	void SetNumberPlayers(uint16_t);
	void SetMaxClues(uint16_t);
	void SetDrawtime(uint16_t);
	void SetNumberWords(uint16_t);
	void SetNumberHints(uint16_t);
	//optionHints de dezbatut
	//void optionsHints(uint16_t maxHints);
	// de dezbatut daca e nevoie
	//void choosePublicOrPrivate();
	

private:
	uint16_t m_time;
	uint16_t m_language;
	uint16_t m_maxNumberPlayers;
	uint16_t m_drawtime;
	uint16_t m_maxClues;
	uint16_t m_numberWords;
	uint16_t m_numberHints;
	//bool optionPrivate;

	
};

