#pragma once
#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
#include "Game.h"

#include <cstdint>

#include <random>

namespace sql = sqlite_orm;

import utils;
import word;
import user;

namespace http
{
	inline auto CreateStorage(const std::string& filename)
	{
		return sql::make_storage(
			filename,
			sql::make_table(
				"Words",
				sql::make_column("id", &Word::SetId, &Word::GetId, sql::primary_key().autoincrement()),
				sql::make_column("word", &Word::SetWord, &Word::GetWord),
				sql::make_column("price", &Word::SetPrice, &Word::GetPrice)
			),
			sql::make_table(
				"Users",
				sql::make_column("id", &User::SetId, &User::GetId, sql::primary_key().autoincrement()),
				sql::make_column("username", &User::SetUsername, &User::GetUsername, sql::unique()),
				sql::make_column("password", &User::SetPassword, &User::GetPassword)
			)
		);
	}

	using Storage = decltype(CreateStorage(""));

	class GameStorage
	{
	public:
		bool Initialize();

		std::vector<Word> GetWords();
		std::vector<User> GetUsers();
		std::vector<Game> GetGames();

		void AddUserToDatabase(std::string& username, std::string& password);
		void AddGame(std::string& roomcode, std::string& host);
		void AddPlayerInRoom(std::string& roomcode, std::string& user);
		void ModifySettings(std::string& roomcode, uint16_t time, uint16_t language, uint16_t noPlayers,
			uint16_t noWords, uint16_t hints, uint16_t rounds);
		void AddGuess(std::string& roomcode, std::string& guess);
		void ModifyGameState(std::string& roomcode, std::string& gameState);
		void AddPointInDrawing(std::string& roomcode, uint16_t x, uint16_t y, uint16_t r, uint16_t g, uint16_t b,
			uint8_t brushSize, bool inWindow);
		void AddWordInChosenWords(std::string& roomcode);
		uint16_t GenerateRandomNumber(uint16_t min, uint16_t max);

	private:
		void PopulateWordsStorage();

	private:
		const std::string kDbFile{ "database.sqlite" };

	private:
		Storage m_db = CreateStorage(kDbFile);
		std::vector<Game> m_games;

	};

	class AddUserHandler {
	public:
		AddUserHandler(GameStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_db;

	};

	class AddGameHandler {
	public:
		AddGameHandler(GameStorage& storage);
		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_games;
	};

	class AddPlayerHandler {
	public:
		AddPlayerHandler(GameStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_games;
	};

	class ModifySettingsHandler {
	public:
		ModifySettingsHandler(GameStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_games;
	};

	class AddGuessHandler {
	public:
		AddGuessHandler(GameStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_games;
	};

	class ModifyGameStateHandler {
	public:
		ModifyGameStateHandler(GameStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_games;
	};

	class AddPointsHandler {
	public:
		AddPointsHandler(GameStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_games;
	};

	class AddChosenWordsHandler {
	public:
		AddChosenWordsHandler(GameStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		GameStorage& m_data;
	};

}