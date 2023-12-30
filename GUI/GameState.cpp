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
