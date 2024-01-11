#include "Points.h"

Points::Points(uint16_t x, uint16_t y, uint8_t R, uint8_t G, uint8_t B, 
	uint8_t brushSize, bool inWindow):
	m_x(x),
	m_y(y),
	m_R(R),
	m_G(G),
	m_B(B),
	m_brushSize(brushSize),
	m_inWindow(inWindow)
{
}

const uint16_t Points::GetX() const
{
	return m_x;
}

const uint16_t Points::GetY() const
{
	return m_y;
}

const uint8_t Points::GetRed() const
{
	return m_R;
}

const uint8_t Points::GetGreen() const
{
	return m_G;
}

const uint8_t Points::GetBlue() const
{
	return m_B;
}

const uint8_t Points::GetBrushSize() const
{
	return m_brushSize;
}

const bool Points::GetInWindow() const
{
	return m_inWindow;
}

void Points::SetX(uint16_t x)
{
	m_x = x;
}

void Points::SetY(uint16_t y)
{
	m_y = y;
}

void Points::SetRed(uint16_t red)
{
	m_R = red;
}

void Points::SetGreen(uint16_t green)
{
	m_G = green;
}

void Points::SetBlue(uint16_t blue)
{
	m_B = blue;
}

void Points::SetBrushSize(uint8_t brushSize)
{
	m_brushSize = brushSize;
}

void Points::SetInWindow(bool inWindow)
{
	m_inWindow = inWindow;
}
