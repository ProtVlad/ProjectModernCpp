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
		Words{-1,"limba",50}

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




