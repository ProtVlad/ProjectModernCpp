#pragma once
#include <cstdint>
#include <string>
enum class GameState : uint16_t
{
	MainMenu,
	LoginOrRegister,
	LoggedIn,
	EnterCode,
	Settings,
	InGame
};
GameState ConvertStringToGameState(const std::string& gameState);

