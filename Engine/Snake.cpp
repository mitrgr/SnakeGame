#include "Snake.h"
#include "Location.h"
#include "Bord.h"


Snake::Snake()
	:
	Dir(1, 0)
{
	Location l(2, 2);
	Seg[0].SetLoc(l,0);
}

void Snake::AddSeg()
{
	if (gotFood) {
		size++;
		Seg[size].SetLoc(Seg[size - 1].GetLoc(),size);
		gotFood = false;
	}
}

void Snake::MoveSnake(const Keyboard & K, Food food, bool & gameover)
{
	gameover = hit;
	if (!hit) {
		MoveSeg();
		Seg[0] += Dir;
		GotHit();
		GotFood(food);
		KeepIn();
		ChangeDir(K);
	}
	
	
}

Location Snake::GetL(int i) const
{
	return Seg[i].GetLoc();
}

int Snake::GetSize() const
{
	return size;
}

bool Snake::Eaten()
{
	return gotFood;
}

Color Snake::GetC(int i)
{
	return Seg[i].GetColor();
}

void Snake::MoveSeg()
{
	for (int i = (size-1) ; i > 0; i--) {
		Seg[i].SetLoc(Seg[i - 1].GetLoc(),i);
	}
}

void Snake::GotHit()
{
	bool k = false;
	for (int i = size - 1; i > 0; i--) {
		k = k || (Seg[0].GetLoc() == Seg[i].GetLoc());
	}
	hit = k;
}

void Snake::GotFood(Food & food)
{
	if ( ( (Seg[0].GetLoc()) == (food.GetL()))) {
		gotFood = true;
	}
}

void Snake::ChangeDir(const Keyboard & K)
{
	if (K.KeyIsPressed('W')) {
		if (Dir.y!=1) {
			Dir.x = 0;
			Dir.y = -1;
		}
	}
	if (K.KeyIsPressed('S')) {
		if (Dir.y != -1) {
			Dir.x = 0;
			Dir.y = 1;
		}
	}
	if (K.KeyIsPressed('A')) {
		if (Dir.x != 1) {
			Dir.x = -1;
			Dir.y = 0;
		}
	}
	if (K.KeyIsPressed('D')) {
		if (Dir.x != -1) {
			Dir.x = 1;
			Dir.y = 0;
		}
	}
	
}

void Snake::Segments::SetLoc(const Location l, int s)
{
	unsigned char r, g, b;
	if ((s) % 4 == 0) {
		r =10, b =32, g =100 ;
	}
	else if(((s ) % 4 == 1))
	{
		r =10, b =48, g =130 ;
	}
	else if (((s ) % 4 == 2))
	{
		r =18, b =48, g =160 ;
	}
	else if (((s ) % 4 == 3))
	{
		r = 10, b = 48, g = 130;
	}


	c = { r, g ,b };

	Loc = l;
	
}

Location Snake::Segments::GetLoc() const
{
	return Loc;
}

Color Snake::Segments::GetColor()
{
	return c;
}

void Snake::Segments::operator+=(const Location l)
{
	Loc += l;
}

void Snake::KeepIn() {
	
	if (Seg[0].GetLoc().x < 1) {
		Location l(Bord::BordSizex/ width -1, Seg[0].GetLoc().y);
		Seg[0].SetLoc(l,0);
	}
	if (Seg[0].GetLoc().y < 1) {
		Location l(Seg[0].GetLoc().x, Bord::BordSizey / Height - 1);
		Seg[0].SetLoc(l,0);
	}
	if (Seg[0].GetLoc().x > Bord::BordSizex/ width - 1) {
		Location l(1, Seg[0].GetLoc().y);
		Seg[0].SetLoc(l,0);
	}
	if (Seg[0].GetLoc().y > Bord::BordSizey /Height - 1 ) {
		Location l(Seg[0].GetLoc().x, 1);
		Seg[0].SetLoc(l,0);
	}
}
