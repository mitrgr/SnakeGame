#include "Food.h"
#include "Bord.h"
#include "Graphics.h"


Food::Food():
	Loc((rand()%(Bord::BordSizex/size-4)+2 ), ((rand() % Bord::BordSizey/size-4)+2 )),
	c(rand()%255, rand() % 255, rand() % 255)
{

}


Food::~Food()
{
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	c = { (r,g,b) };
}

void Food::Update()
{
	
			Loc.x = ((rand() % (Bord::BordSizex / size - 5)) + 2);
			Loc.y = ((rand() % (Bord::BordSizey / size - 5)) + 2);
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;

}

void Food::UpdateCol()
{
	if (r < 255) {
		r += 10;
	}
	else
	{
		r = 0;
	}
	if (g < 255) {
		g += 10;
	}
	else
	{
		g = 0;
	}
	if (b < 255) {
		b += 10;
	}
	else
	{
		b = 0;
	}

	c = { r,g,b };


}


Color Food::GetC() const 
{
	return c; 
}

int Food::GetS() const
{
	return size;
}

Location Food::GetL() const
{
	return Loc;
}
