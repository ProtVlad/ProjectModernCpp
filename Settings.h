#pragma once
#include <cstdint>
#include <string>

class Settings
{
public:
	Settings();
	Settings(uint16_t time, const std::string& language, uint16_t numberPlayers);
	uint16_t GetTime();
	const std::string& GetLanguage();
	uint16_t GetMaxNumberPlayers();
	uint16_t GetDrawtime();
	uint16_t GetMaxClues();
	uint16_t GetNumberWords();
	uint16_t GetNumberHints();
	void SetTime(uint16_t time);
	void SetLanguage(const std::string& language);
	void SetNumberPlayers(uint16_t maxNumberPlayers);
	void SetMaxClues(uint16_t maxClues);
	void SetDrawtime(uint16_t drawtime);
	void SetNumberWords(uint16_t numberWords);
	void SetNumberHints(uint16_t numberHints);
	//optionHints de dezbatut
	//void optionsHints(uint16_t maxHints);
	// de dezbatut daca e nevoie
	//void choosePublicOrPrivate();
	

private:
	uint16_t m_time;
	std::string m_language;
	uint16_t m_maxNumberPlayers;
	uint16_t m_drawtime;
	uint16_t m_maxClues;
	uint16_t m_numberWords;
	uint16_t m_numberHints;
	//bool optionPrivate;

	
};

