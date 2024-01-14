#pragma once
#include <iostream>
class Points
{
public:
	Points() = default;
	Points(uint16_t x, uint16_t y, uint8_t R, uint8_t G, uint8_t B, uint8_t brushSize, bool inWindow);
	const uint16_t GetX() const;
	const uint16_t GetY() const;
	const uint8_t GetRed() const;
	const uint8_t GetGreen() const;
	const uint8_t GetBlue() const;
	const uint8_t GetBrushSize() const;
	const bool GetInWindow() const;
	void SetX(uint16_t x);
	void SetY(uint16_t y);
	void SetRed(uint8_t red);
	void SetGreen(uint8_t green);
	void SetBlue(uint8_t blue);
	void SetBrushSize(uint8_t brushSize);
	void SetInWindow(bool inWindow);
	bool operator == (Points point2);
	bool SameColor(Points point2);


private:
	uint16_t m_x;
	uint16_t m_y;
	uint8_t m_R;
	uint8_t m_G;
	uint8_t m_B;
	uint8_t m_brushSize;
	bool m_inWindow;

};

