#include "Words.h"
import utils;

void populateListWords(Storage& storage)
{
	std::vector<Words> words{
		Words{-1,"trandafir",100},
		Words{-1,"artificii",150},
		Words{-1,"cuptor cu microunde",150},
		Words{-1,"clovn",150},
		Words{-1,"cuvant",50},
		Words{-1,"limba",50},
		Words{-1,"calcultator",150},
		Words{-1,"Traian Basescu",50},
		Words{-1,"caseta",100},
		Words{-1,"buton",150},
		Words{-1,"grafic",150},
		Words{-1,"schema",50},
		Words{-1,"litera",50},
		Words{-1,"matematica",150},
		Words{-1,"profesor",150},
		Words{-1,"cana",150},
		Words{-1,"cafea",150},
		Words{-1,"Google",150},
		Words{-1,"ochelari",150},
		Words{-1,"oftalmolog",100},
		Words{-1,"dentist",150},
		Words{-1,"telefon fix",150},
		Words{-1,"sticla",100},
		Words{-1,"servetel",100},
		Words{-1,"raceala",100},
		Words{-1,"nervos",50},
		Words{-1,"bucle",100},
		Words{-1,"frizerie",150},
		Words{-1,"lumina",50},
		Words{-1,"arhitect",100},
		Words{-1,"programator",150},
		Words{-1,"sofer",150},
		Words{-1,"masina",150},
		Words{-1,"autobuz scolar",150},
		Words{-1,"camera video",100},
		Words{-1,"botez",100},
		Words{-1,"mireasa",150},
		Words{-1,"bebelus",150},
		Words{-1,"covrig",100},
		Words{-1,"creioane colorate",150},
		Words{-1,"tablou",100},
		Words{-1,"violet",50},
		Words{-1,"trandafiriu",50},
		Words{-1,"rebus",50},
		Words{-1,"Kaufland",150},
		Words{-1,"setari",50},
		Words{-1,"Victor Ponta",50},
		Words{-1,"rulouri",100},
		Words{-1,"Selly",50},
		Words{-1,"tigaie",150},
		Words{-1,"geometrie",100},
		Words{-1,"gnom",50},
		Words{-1,"avizier",100},
		Words{-1,"oglinda",150},
		Words{-1,"Aurora Boreala",100},
		Words{-1,"dolar",150},
		Words{-1,"cabana",100},
		Words{-1,"curcubeu",150},
		Words{-1,"veioza",150},
		Words{-1,"suc",150},
		Words{-1,"acnee",150},
		Words{-1,"aparat dentar",100},
		Words{-1,"miopie",50},
		Words{-1,"adolescent",50},
		Words{-1,"ghiozdan",150},
		Words{-1,"pusca",50},
		Words{-1,"palarie",150},
		Words{-1,"curea",150},
		Words{-1,"ghilotina",100},
		Words{-1,"ascensor",100},
		Words{-1,"convexitate",100},
		Words{-1,"descendent",50},
		Words{-1,"peste",150},
		Words{-1,"RAM",50},
		Words{-1,"instalator",100},
		Words{-1,"plata",50},
		Words{-1,"ciob",50},
		Words{-1,"trabuc",100},
		Words{-1,"uscat",50},
		Words{-1,"umed",50},
		Words{-1,"mar",150},
		Words{-1,"diferenta",100},
		Words{-1,"mare",100},
		Words{-1,"mic",50},
		Words{-1,"fantoma",150},
		Words{-1,"pamant",50},
		Words{-1,"univers",150},
		Words{-1,"mormant",150},
		Words{-1,"Statuia Libertatii",100},
		Words{-1,"credinta",100},
		Words{-1,"idee",100},
		Words{-1,"ventilator",150},
		Words{-1,"feon",100},
		Words{-1,"Facebook",150},
		Words{-1,"portiera",100},
		Words{-1,"motor",100},
		Words{-1,"ghidon",100},
		Words{-1,"parcare",150},
		Words{-1,"gara",100},
		Words{-1,"carte",150},
		Words{ -1,"locuinta",50 }
	};
	storage.insert_range(words.begin(), words.end());
}

AddChoosenWord::AddChoosenWord(Storage& storage)
	: m_db{ storage }
{
}

crow::response AddChoosenWord::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto productIdIter = bodyArgs.find("word");
	auto quantityIter = bodyArgs.find("price");
	if (productIdIter != end && quantityIter != end)
	{
		Words sbrow;
		sbrow.word = std::stoi(productIdIter->second);
		sbrow.price = std::stoi(quantityIter->second);
		m_db.insert(sbrow);
	}
	return crow::response(201);
}







