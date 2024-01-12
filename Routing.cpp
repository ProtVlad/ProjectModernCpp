#include "Routing.h"
//#include "Words.h"

using namespace http;

import word;

void Routing::Run(WordStorage& storage)
{
	CROW_ROUTE(m_app, "/")([]() {
		return "This is an example app of crow and sql-orm";
		});

	CROW_ROUTE(m_app, "/products")([&storage]() {
		std::vector<crow::json::wvalue> products_json;

		auto words = storage.GetWords();
		for (const auto& word : words)
		{
			products_json.push_back(crow::json::wvalue{
				{"id", word.GetId()},  // product_json["id"] = product.id;
				{"word", word.GetWord()},
				{"price", word.GetPrice()}
				});

			//std::string product_json = db.dump(product);	
		}
		return crow::json::wvalue{ products_json };
		});


	CROW_ROUTE(m_app, "/addproducttobasket/<int>")([&storage, this](const crow::request& req, int productId) {
		return AddWordToChosenWord(storage, req, productId);

		});

	auto& addToBasketPut = CROW_ROUTE(m_app, "/addproducttobasket")
		.methods(crow::HTTPMethod::PUT); // https://stackoverflow.com/a/630475/12388382
	addToBasketPut(AddToChosenWordsHandler(storage));


	CROW_ROUTE(m_app, "/basket")([&storage]() {
		auto rows = storage.GetChosenWords();

		std::vector<crow::json::wvalue> results;
		for (const auto& row : rows) {
			const auto& [word, idWord, numberWords] = row;
			results.push_back(crow::json::wvalue{
				{ "id", word },
				{ "price", idWord },
				{ "numberWords", numberWords }
				});
		}



		//CROW_ROUTE(app, "/addProduct/<int>")([&db]
		//(const crow::request& request, int wordId) {
		//		char* quantityChar = request.url_params.get("quantity");
		//		int quantity = std::stoi(quantityChar);
		//		ChoosenWords row;
		//		row.word = wordId;
		//		row.price = quantity;
		//		db.insert(row);
		//		return crow::response(200);
		//	});

		//CROW_ROUTE(app, "/users")([&db]() {
		//	std::vector<crow::json::wvalue>usersJson;
		//	for (const auto& user : db.iterate<User>())
		//	{
		//		crow::json::wvalue uJson{
		//			{"id",user.id},
		//			{"username",user.username},
		//			{"password",user.password}
		//		};
		//		usersJson.push_back(uJson);
		//	}
		//	return crow::json::wvalue{ usersJson };
		//	});

		//auto& addUserPut = CROW_ROUTE(app, "/addUser")
		//	.methods(crow::HTTPMethod::PUT);
		//addUserPut(AddUserHandler(db));

		//std::vector<Game> games;

		//CROW_ROUTE(app, "/games")([&games]()
		//	{
		//		std::vector<crow::json::wvalue>gamesJson;
		//		for (const auto& game : games)
		//		{
		//			crow::json::wvalue gameJson{
		//				{"roomcode",game.GetRoomcode()},
		//				{"timer",game.GetTimer().GetDuration()},
		//				{"indexDrawer",game.GetIndexDrawer()},
		//				{"gameState",game.GetGameState()}
		//			};
		//			/*crow::json::wvalue gameJson;
		//			gameJson["roomcode"] = game.GetRoomcode();
		//			gameJson["timer"] = game.GetTimer();
		//			gameJson["indexDrawer"] = game.GetIndexDrawer();*/
		//			gamesJson.push_back(gameJson);
		//		}
		//		return crow::json::wvalue{ gamesJson };
		//	});

		//auto& addGamePut = CROW_ROUTE(app, "/addGame")
		//	.methods(crow::HTTPMethod::PUT);
		//addGamePut(AddGameHandler(games));

		//CROW_ROUTE(app, "/<string>/players")([&games](std::string roomcode)
		//	{
		//		for (const auto& game : games)
		//			if (game.GetRoomcode() == roomcode)
		//			{
		//				crow::json::wvalue playersJson{
		//					{"noPlayers", game.GetUsers().size()}
		//				};
		//				std::string key;
		//				for (int index = 0; index < game.GetUsers().size(); index++)
		//				{
		//					key = "user" + std::to_string(index);
		//					playersJson[key] = game.GetUsers()[index];
		//				}
		//				return crow::json::wvalue{ playersJson };
		//			}
		//		return crow::json::wvalue{  };
		//	});

		//auto& addPlayerPut = CROW_ROUTE(app, "/addPlayer")
		//	.methods(crow::HTTPMethod::PUT);
		//addPlayerPut(AddPlayerHandler(games));

		//CROW_ROUTE(app, "/<string>/settings")([&games](std::string roomcode)
		//	{
		//		for (const auto& game : games)
		//			if (game.GetRoomcode() == roomcode)
		//			{
		//				crow::json::wvalue settingsJson{
		//				{"time",game.GetSettings().GetTime()},
		//				{"language",game.GetSettings().GetLanguage()},
		//				{"maxNoPlayers",game.GetSettings().GetMaxNumberPlayers()},
		//				{"noWords",game.GetSettings().GetNumberWords()},
		//				{"hints",game.GetSettings().GetNumberHints()},
		//				{"noRounds",game.GetSettings().GetNumberRounds()}
		//				};
		//				return crow::json::wvalue{ settingsJson };
		//			}
		//		return crow::json::wvalue{  };
		//	});

		//CROW_ROUTE(app, "/<string>/guesses")([&games](std::string roomcode)
		//	{
		//		crow::json::wvalue guessesJson;
		//		for (const auto& game : games)
		//			if (game.GetRoomcode() == roomcode)
		//			{
		//				guessesJson["noGuesses"] = game.GetGuesses().size();
		//				std::string key;
		//				for (int index = 0; index < game.GetGuesses().size(); index++)
		//				{
		//					key = "guess" + std::to_string(index);
		//					guessesJson[key] = game.GetGuesses()[index];
		//				}
		//				break;
		//			}
		//		return crow::json::wvalue{ guessesJson };
		//	});

		//CROW_ROUTE(app, "/<string>/points")([&games](std::string roomcode)
		//	{
		//		for (const auto& game : games)
		//			if (game.GetRoomcode() == roomcode)
		//			{
		//				crow::json::wvalue pointsJson{
		//					{"noPoints", game.GetPoints().size()}
		//				};
		//				std::string keyX;
		//				std::string keyY;
		//				std::string keyR;
		//				std::string keyG;
		//				std::string keyB;
		//				std::string keyBrushSize;
		//				std::string keyInWindow;
		//				for (int index = 0; index < game.GetPoints().size(); index++)
		//				{
		//					keyX = "x" + std::to_string(index);
		//					pointsJson[keyX] = game.GetPoints()[index].GetX();
		//					keyY = "y" + std::to_string(index);
		//					pointsJson[keyY] = game.GetPoints()[index].GetY();
		//					keyR = "red" + std::to_string(index);
		//					pointsJson[keyR] = game.GetPoints()[index].GetRed();
		//					keyG = "green" + std::to_string(index);
		//					pointsJson[keyG] = game.GetPoints()[index].GetGreen();
		//					keyB = "blue" + std::to_string(index);
		//					pointsJson[keyB] = game.GetPoints()[index].GetBlue();
		//					keyBrushSize = "brushSize" + std::to_string(index);
		//					pointsJson[keyBrushSize] = game.GetPoints()[index].GetBrushSize();
		//					keyInWindow = "inWindow" + std::to_string(index);
		//					pointsJson[keyInWindow] = game.GetPoints()[index].GetInWindow();
		//				}
		//				return crow::json::wvalue{ pointsJson };
		//			}
		//		return crow::json::wvalue{  };
		//	});

		//auto& addPointsPut = CROW_ROUTE(app, "/addPoints")
		//	.methods(crow::HTTPMethod::PUT);
		//addPointsPut(AddPointsHandler(games));

		//auto& addGuessPut = CROW_ROUTE(app, "/addGuess")
		//	.methods(crow::HTTPMethod::PUT);
		//addGuessPut(AddGuessHandler(games));

		//auto& modifySettingsPut = CROW_ROUTE(app, "/modifySettings")
		//	.methods(crow::HTTPMethod::PUT);
		//modifySettingsPut(ModifySettingsHandler(games));

		//auto& modifyGameStatePut = CROW_ROUTE(app, "/modifyGameState")
		//	.methods(crow::HTTPMethod::PUT);
		//modifyGameStatePut(ModifyGameStateHandler(games));

		return crow::json::wvalue{ results };
		});

	m_app.port(13034).multithreaded().run();

}

crow::response Routing::AddWordToChosenWord(WordStorage& storage, const crow::request& req, int productId) const
{
	
	char* quantity_chr = req.url_params.get("numberWords");
	int quantity = 1;
	if (quantity_chr != nullptr) {
		quantity = std::stoi(quantity_chr); 
	}

	storage.AddWordToChosenWords(productId, quantity);

	return crow::response(200);
}