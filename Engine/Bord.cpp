#include "Bord.h"
#include <stdlib.h>
#include <time.h>

Bord::Bord()
{
	srand((unsigned int)time(NULL));
}

void Bord::Update(Keyboard & K, bool & Gameover, bool& newOBS)
{
	snake.MoveSnake(K,food, Gameover); 
	if (snake.Eaten()) {
		bool cond;
		do {
			food.Update();
			bool Cond = false;
			for (int i = 0; i < obs.getNum(); i++) {
				Cond = Cond || food.GetL() == obs.obs[i].GetL();
			}
			cond = Cond;
		} while (cond);
	}
	snake.AddSeg();
	if (!Gameover){
	Gameover = obs.HitOBS(snake);
	}
	if (newOBS) {
		obs.obs[obs.getNum()].Update(snake, food);
		obs.addOBS();
		newOBS = false;
	}
	food.UpdateCol();

}


void Bord::DrawSnake(Graphics & gfx)
{
	int W = snake.width;
	int H = snake.Height;
	for (int i = 0; i < snake.GetSize(); i++) {
		Location l = snake.GetL(i);
		gfx.DrawRect(l.x*W + offsetx/2, l.y*H +offsety/2, W-1, H-1, snake.GetC(i));
	}
	
}

void Bord::DrawFood(Graphics & gfx)
{
	Location l = food.GetL();
	int s = food.GetS();
	gfx.DrawRect(l.x * s + offsetx/2 , l.y * s + offsety/2, s-1, s-1, food.GetC());
}

void Bord::DrawBorder(Graphics & gfx)
{

	for (int i = 0; i < BordSizex; i++) {
		
			gfx.PutPixel(i + CenterX - BordSizex / 2, CenterY - BordSizey / 2,255,255,255);
			gfx.PutPixel( CenterX + BordSizex / 2-i, CenterY + BordSizey / 2, 255, 255, 255);
		}

	for (int j = 0; j < BordSizey; j++) {
		gfx.PutPixel( CenterX - BordSizex/2 , j +CenterY- BordSizey / 2, 255, 255, 255);
		gfx.PutPixel(CenterX +BordSizex/2, CenterY + BordSizey / 2 -j, 255, 255, 255);
	}
}

void Bord::DrawOBS(Graphics & gfx)
{
	int s = obs.size;
	for (int i = 0; i < obs.getNum(); i++) {
		Location l = obs.obs[i].GetL();
		gfx.DrawRect(l.x*s + offsetx / 2, l.y*s + offsety / 2, s - 1, s - 1, obs.obs[i].GetC());
	}
}
