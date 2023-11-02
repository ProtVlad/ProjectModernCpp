#pragma once
#include <cstdint>
#include <string>
enum class Opinion : uint16_t
{ 
	NoOpinion, 
	Like, 
	Dislike 
};
Opinion ConvertStringToOpinion(const std::string& opinion);
