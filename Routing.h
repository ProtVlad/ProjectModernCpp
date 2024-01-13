#pragma once
#include <crow.h>
#include "GameDatabase.h"


namespace http
{
	class Routing
	{
	public:
		void Run(GameStorage& storage);

	private:
		//crow::response AddWordToChosenWord(GameStorage& storage, const crow::request& req, int productId)const;

	private:
		crow::SimpleApp m_app;
	};
};


