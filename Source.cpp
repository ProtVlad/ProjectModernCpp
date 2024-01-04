#include "Chat.h"
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

	auto& addUserPut = CROW_ROUTE(app, "/addUser")
		.methods(crow::HTTPMethod::PUT);
	addUserPut(AddUserHandler(db));

	std::vector<Game> games;

	CROW_ROUTE(app, "/games")([&games]()
		{
			std::vector<crow::json::wvalue>gamesJson;
			for (const auto& game : games)
			{
				crow::json::wvalue gameJson{
					{"roomcode",game.GetRoomcode()},
					{"timer",game.GetTimer()},
					{"indexDrawer",game.GetIndexDrawer()}
				};
				/*crow::json::wvalue gameJson;
				gameJson["roomcode"] = game.GetRoomcode();
				gameJson["timer"] = game.GetTimer();
				gameJson["indexDrawer"] = game.GetIndexDrawer();*/
				gamesJson.push_back(gameJson);
			}
			return crow::json::wvalue{ gamesJson };
		});

	auto& addGamePut = CROW_ROUTE(app, "/addGame")
		.methods(crow::HTTPMethod::PUT);
	addGamePut(AddGameHandler(games));

	CROW_ROUTE(app, "/<string>/players")([&games](std::string roomcode)
		{
			for (const auto& game : games)
				if (game.GetRoomcode() == roomcode)
				{
					crow::json::wvalue playersJson{
						{"noPlayers", game.GetUsers().size()}
					};
					std::string key;
					for (int index = 0; index < game.GetUsers().size(); index++)
					{
						key = "user" + std::to_string(index);
						playersJson[key] = game.GetUsers()[index];
					}
					return crow::json::wvalue{ playersJson };
				}
			return crow::json::wvalue{  };
		});

	auto& addPlayerPut = CROW_ROUTE(app, "/addPlayer")
		.methods(crow::HTTPMethod::PUT);
	addPlayerPut(AddPlayerHandler(games));

	CROW_ROUTE(app, "/<string>/settings")([&games](std::string roomcode)
		{
			for (const auto& game : games)
				if (game.GetRoomcode() == roomcode)
				{
					crow::json::wvalue settingsJson{
					{"time",game.GetSettings().GetTime()},
					{"language",game.GetSettings().GetLanguage()},
					{"maxNoPlayers",game.GetSettings().GetMaxNumberPlayers()},
					{"noWords",game.GetSettings().GetNumberWords()},
					{"hints",game.GetSettings().GetNumberHints()}
					};
					return crow::json::wvalue{ settingsJson };
				}
			return crow::json::wvalue{  };
		});

	auto& modifySettingsPut = CROW_ROUTE(app, "/modifySettings")
		.methods(crow::HTTPMethod::PUT);
	modifySettingsPut(ModifySettingsHandler(games));

	app.port(13034).multithreaded().run();
	return 0;
}