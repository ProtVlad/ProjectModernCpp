#pragma once
#include <cstdint>
#include <string>
enum class Color : uint16_t
{
	White,
	Green
};
Color ConvertStringToColor(const std::string& color);

