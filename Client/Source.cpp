#include <iostream>
#include <cpr/cpr.h>
#include <crow.h>

int main()
{
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:13034/products" });
	

	return 0;
}