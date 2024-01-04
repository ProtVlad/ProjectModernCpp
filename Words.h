#pragma once

#include <string>
#include <vector>

#include <crow.h>
#include "Game.h"
#include "Settings.h"

#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

import utils;

struct Words
{
	int id;
	std::string word;
	int price;
};

struct ChoosenWords
{
	int id;
	std::string word;
	int price;
};

struct User
{
	int id;
	std::string username;
	std::string password;
};


inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"Words",
			sql::make_column("id", &Words::id, sql::primary_key().autoincrement()),
			sql::make_column("word", &Words::word),
			sql::make_column("price", &Words::price)
		),
		sql::make_table(
			"ChoosenWords",
			sql::make_column("id", &ChoosenWords::id, sql::primary_key().autoincrement()),
			sql::make_column("word", &ChoosenWords::word),
			sql::make_column("price", &ChoosenWords::price)
		),
		sql::make_table(
			"Users",
			sql::make_column("id", &User::id, sql::primary_key().autoincrement()),
			sql::make_column("username", &User::username, sql::unique()),
			sql::make_column("password", &User::password)
		)
	);
}

using Storage = decltype(createStorage(""));


void populateListWords(Storage& storage);


class AddChoosenWord {
public:
	AddChoosenWord(Storage& storage);

	crow::response operator() (const crow::request& req) const;

private:
	Storage& m_db;
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