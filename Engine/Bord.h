#include "Snake.h"
#include "Graphics.h"
#include "Food.h"
#include "Obsticle.h"

#pragma once
class Bord
{
public:
	Bord();
	
	void Update(Keyboard& K, bool & Gameover, bool& newOBS );

	void DrawSnake(Graphics & gfx);
	void DrawFood(Graphics & gfx);
	void DrawBorder(Graphics & gfx);
	void DrawOBS(Graphics & gfx);

	static constexpr int offsety = 200;
	static constexpr int offsetx = 200;
	static constexpr int BordSizex = Graphics::ScreenWidth - offsetx;
	static constexpr int BordSizey = Graphics::ScreenHeight - offsety;
	static constexpr int CenterX = 400;
	static constexpr int CenterY = 300;
private:
	
	
	Snake snake;
	Food food;
	Obsticle obs;

};

