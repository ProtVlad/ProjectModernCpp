#pragma once
#include <cstdint>
#include <string>
enum class GameState : uint16_t
{
	MainMenu,
	LoginOrRegister,
	LoggedIn,
	EnterCode,
	MeetingRoom,
	InGame
};
GameState ConvertStringToGameState(const std::string& gameState);
std::string ConvertGameStateToString(const GameState& gameState);
