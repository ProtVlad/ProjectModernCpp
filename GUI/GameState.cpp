#include "GameState.h"

GameState ConvertStringToGameState(const std::string& gameState)
{
	if (gameState == "MainMenu")
		return GameState::MainMenu;
	if (gameState == "LoginOrRegister")
		return GameState::LoginOrRegister;
	if (gameState == "LoggedIn")
		return GameState::LoggedIn;
	if (gameState == "EnterCode")
		return GameState::EnterCode;
	if (gameState == "MeetingRoom")
		return GameState::MeetingRoom;
	if (gameState == "InGame")
		return GameState::InGame;
	throw std::exception("GameState Invalid");
}

std::string ConvertGameStateToString(const GameState& gameState)
{
	if (gameState == GameState::MainMenu)
		return "MainMenu";
	if (gameState == GameState::LoginOrRegister)
		return "LoginOrRegister";
	if (gameState == GameState::LoggedIn)
		return "LoggedIn";
	if (gameState == GameState::EnterCode)
		return "EnterCode";
	if (gameState == GameState::MeetingRoom)
		return "MeetingRoom";
	if (gameState == GameState::InGame)
		return "InGame";
	throw std::exception("GameState Invalid");
}
