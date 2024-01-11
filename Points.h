#pragma once
#include <iostream>
class Points
{
public:
	Points(uint16_t x, uint16_t y, uint16_t R, uint16_t G, uint16_t B, uint8_t brushSize, bool inWindow);
	const uint16_t GetX() const;
	const uint16_t GetY() const;
	const uint16_t GetRed() const;
	const uint16_t GetGreen() const;
	const uint16_t GetBlue() const;
	const uint8_t GetBrushSize() const;
	const bool GetInWindow() const;
	void SetX(uint16_t x);
	void SetY(uint16_t y);
	void SetRed(uint16_t red);
	void SetGreen(uint16_t green);
	void SetBlue(uint16_t blue);
	void SetBrushSize(uint8_t brushSize);
	void SetInWindow(bool inWindow);
	

private:
	uint16_t m_x;
	uint16_t m_y;
	uint16_t m_R;
	uint16_t m_G;
	uint16_t m_B;
	uint8_t m_brushSize;
	bool m_inWindow;
	
};

