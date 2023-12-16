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





