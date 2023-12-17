﻿#include "Chat.h"
#include "Game.h"
#include "Player.h"
#include "Settings.h"
#include "Words.h"

#include <filesystem>
#include <iostream>
#include <memory>
#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;


int main()
{
	Storage db = createStorage("word.sqlite");
	db.sync_schema();
	auto initialWordsCount = db.count<Words>();
	if (initialWordsCount == 0)
		populateListWords(db);
	//std::cout << db.count<Words>();

	crow::SimpleApp app;
	CROW_ROUTE(app, "/")([]() {
		return "This is the path";
		});

	CROW_ROUTE(app, "/products")([&db]() {
		std::vector<crow::json::wvalue>wordsJson;
		for (const auto& word : db.iterate<Words>())
		{
			crow::json::wvalue pJson{
				{"id",word.id},
				{"name",word.word},
				{"price",word.price}
			};
			wordsJson.push_back(pJson);
		}
		return crow::json::wvalue{ wordsJson };
		});

	app.port(13034).multithreaded().run();
	return 0;
}