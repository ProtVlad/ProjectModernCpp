#include "Opinion.h"

Opinion ConvertStringToOpinion(const std::string& opinion)
{
	if (opinion == "NoOpinion")
		return Opinion::NoOpinion;
	if (opinion == "Like")
		return Opinion::Like;
	if (opinion == "Dislike")
		return Opinion::Dislike;
	throw std::exception("Opinion Invalid");
}
