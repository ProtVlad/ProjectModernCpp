#pragma once
#include <crow.h>
#include "Words.h"


namespace http
{
	class Routing
	{
	public:
		void Run(WordStorage& storage);

	private:
		crow::response AddWordToChosenWord(WordStorage& storage, const crow::request& req, int productId)const;

	private:
		crow::SimpleApp m_app;
	};
};


