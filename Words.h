#pragma once
#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

#include "Game.h"

import utils;
import word;
import chosenwords;
import user;

namespace http
{
	inline auto CreateStorage(const std::string& filename)
	{
		return sql::make_storage(
			filename,
			sql::make_table(
				"Word",
				sql::make_column("id", &Word::SetId, &Word::GetId, sql::primary_key().autoincrement()),
				sql::make_column("word", &Word::SetWord, &Word::GetWord),
				sql::make_column("price", &Word::SetPrice, &Word::GetPrice)
			),
			sql::make_table(
				"ChosenWords",
				sql::make_column("id", &ChosenWords::SetId, &ChosenWords::GetId, sql::primary_key().autoincrement()),
				sql::make_column("numberWords", &ChosenWords::SetNumberWords, &ChosenWords::GetNumberWords)
			),
			sql::make_table(
				"User",
				sql::make_column("id", &User::SetId, &User::GetId/*, sql::primary_key().autoincrement()*/),
				sql::make_column("username", &User::SetUsername, &User::GetUsername),
				sql::make_column("password", &User::SetPassword, &User::GetPassword)
			)
		);
	}

	using Storage = decltype(CreateStorage(""));


	class WordStorage
	{
	public:
		bool Initialize();

		std::vector<Word> GetWords();
		void AddWordToChosenWords(int id, int numberWords);
		std::vector<std::tuple<std::string, int, int>> GetChosenWords();


	private:
		void PopulateListWords();

	private:
		const std::string kDbFile{ "words.sqlite" };

	private:
		Storage m_db = CreateStorage(kDbFile);
	};


	class AddUserHandler {
	public:
		AddUserHandler(Storage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		Storage& m_db;
	};

	class AddGameHandler {
	public:
		AddGameHandler(std::vector<Game>& game);

		crow::response operator() (const crow::request& req) const;

	private:
		std::vector<Game>& m_games;
	};

	class AddPlayerHandler {
	public:
		AddPlayerHandler(std::vector<Game>& games);

		crow::response operator() (const crow::request& req) const;

	private:
		std::vector<Game>& m_games;
	};

	class ModifySettingsHandler {
	public:
		ModifySettingsHandler(std::vector<Game>& games);

		crow::response operator() (const crow::request& req) const;

	private:
		std::vector<Game>& m_games;
	};

	class AddGuessHandler {
	public:
		AddGuessHandler(std::vector<Game>& games);

		crow::response operator() (const crow::request& req) const;

	private:
		std::vector<Game>& m_games;
	};

	class ModifyGameStateHandler {
	public:
		ModifyGameStateHandler(std::vector<Game>& games);

		crow::response operator() (const crow::request& req) const;

	private:
		std::vector<Game>& m_games;
	};

	class AddToChosenWordsHandler {
	public:
		AddToChosenWordsHandler(WordStorage& storage);

		crow::response operator() (const crow::request& req) const;

	private:
		WordStorage& m_db;
	};

	class AddPointsHandler {
	public:
		AddPointsHandler(std::vector<Game>& games);

		crow::response operator() (const crow::request& req) const;

	private:
		std::vector<Game>& m_games;
	};
}