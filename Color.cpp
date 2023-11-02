#include "Color.h"

Color ConvertStringToColor(const std::string& color)
{
	if (color == "White")
		return Color::White;
	if (color == "Green")
		return Color::Green;
	throw std::exception("Color Invalid");
}
