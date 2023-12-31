#include "Chat.h"
#include "Game.h"
#include "Player.h"
#include "Settings.h"
#include "Words.h"
#include "GameTimer.h"

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

	CROW_ROUTE(app, "/addProduct/<int>")([&db]
	(const crow::request& request, int wordId) {
			char* quantityChar = request.url_params.get("quantity");
			int quantity = std::stoi(quantityChar);
			ChoosenWords row;
			row.word = wordId;
			row.price = quantity;
			db.insert(row);
			return crow::response(200);
		});

	CROW_ROUTE(app, "/users")([&db]() {
		std::vector<crow::json::wvalue>usersJson;
		for (const auto& user : db.iterate<User>())
		{
			crow::json::wvalue uJson{
				{"id",user.id},
				{"username",user.username},
				{"password",user.password}
			};
			usersJson.push_back(uJson);
		}
		return crow::json::wvalue{ usersJson };
		});

	CROW_ROUTE(app, "/addUser/<int>")([&db](const crow::request& request, int userId = -1)
		{

			char* username = request.url_params.get("username");
			char* password = request.url_params.get("password");

			User user;
			user.id = userId;
			user.username = username;
			user.password = password;
			db.insert(user);

			return crow::response(200);
		});

	auto& addUserPut = CROW_ROUTE(app, "/addUser")
		.methods(crow::HTTPMethod::PUT);
	addUserPut(AddUserHandler(db));

	app.port(13034).multithreaded().run();
	return 0;
}