#include "Chat.h"
#include "Game.h"
#include "Player.h"
#include "Settings.h"

#include <crow.h>


int main()
{
	crow::SimpleApp app;
	CROW_ROUTE(app, "/")([]() {
		return "This is the path";
		});

	CROW_ROUTE(app, "/products")([]() {
		return "Test server";
		});
	app.port(13034).multithreaded().run();
	return 0;
}