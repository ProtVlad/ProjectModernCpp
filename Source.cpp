#include <filesystem>
#include <iostream>
#include <memory>

#include <sqlite_orm/sqlite_orm.h>

#include "gameDatabase.h"
#include "routing.h"

import word;
import user;

using namespace http;
namespace sql = sqlite_orm;

int main()
{
	GameStorage storage;
	if (!storage.Initialize())
	{
		std::cout << "Failed to initialize the database!";
		return -1;
	}

	Routing r;
	r.Run(storage);

	return 0;
}