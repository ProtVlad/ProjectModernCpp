#include "Chat.h"
#include "Game.h"
#include "Player.h"
#include "Settings.h"

#include <crow.h>
#include <libpq-fe.h>

int main()
{

    PGconn* conn = PQconnectdb("host=localhost user=postgres password=1q2w3e dbname=romanian_words");

    if (PQstatus(conn) == CONNECTION_OK) {
        std::cout << "Conectat la baza de date PostgreSQL!\n";
     //ag=daugare interogari
        PQfinish(conn);
    }
    else {
        std::cerr << "Eroare de conectare la baza de date PostgreSQL: " << PQerrorMessage(conn) << "\n";
    }

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