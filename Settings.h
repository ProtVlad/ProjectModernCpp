#pragma once
#include <cstdint>
#include <string>

class Settings
{
public:
	Settings(uint16_t time, const std::string& language, uint16_t numberPlayers);
	uint16_t getTime();
	const std::string& getLanguage();
	uint16_t getMaxNumberPlayers();
	uint16_t getDrawtime();
	uint16_t getMaxClues();
	uint16_t getNumberWords();
	uint16_t getNumberHints();
	void setTime(uint16_t time);
	void setLanguage(const std::string& language);
	void setNumberPlayers(uint16_t maxNumberPlayers);
	void setMaxClues(uint16_t maxClues);
	void setDrawtime(uint16_t drawtime);
	//ai doua randuri din corectatea setterilor pt saptamana viitoare+3 randuri din functii=>1 commit
	void setNumberWods(uint16_t numberWords);
	void setNumberHints(uint16_t numberHints);
	void optionsTime();
	void optionsNumberPlayers();
	void optionsNumberRounds();
	void optionsNumberChosenWords();
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
	//uint16_t m_numberHints;
	//bool optionPrivate;
	uint16_t m_chosenWords;
	
};

