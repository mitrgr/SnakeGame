#include "Location.h"
#include "Colors.h"
#include "Keyboard.h"
#include "Food.h"

#pragma once
class Snake
{
public:
	Snake();

	class Segments
	{
	public:
		Segments():
			Loc(0,0)
		{
		
		}
		void SetLoc(const Location l, int s);
		Location GetLoc() const;
		Color GetColor();
		

		void operator+=(const Location l);
	private:
		Color c = { (0,(255),0) };
		Location Loc;
	};

	
public:
	void AddSeg();
	void MoveSnake(const Keyboard & K, Food food, bool & gameover);
	Location GetL(int i) const;
	int GetSize() const;
	bool Eaten();
	Color GetC(int i);

	static constexpr int Height = 10;
	static constexpr int width = 10;

private:
	void MoveSeg();
	void GotHit();
	void GotFood(Food & food);
	void ChangeDir(const Keyboard& K);
	void KeepIn();

	

private:
	bool gotFood = false;
	bool hit = false;
	int Speed = 1, size=3;
	Location Dir;

	static constexpr int MaxSeg = 1000;

	Segments Seg[MaxSeg];

	
};

