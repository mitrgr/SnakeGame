#include "Obsticle.h"
#include "Bord.h"
#include <stdlib.h>
#include <time.h>

void Obsticle::addOBS()
{
	numberOBS += 1;
}

Obsticle::Obsticle()
{
}


bool Obsticle::HitOBS(const Snake & snake)
{
	bool b=false;
	for(int i = 0;i<=snake.GetSize();i++){
		for (int j = 0; j < numberOBS; j++) {
			b = b || (obs[j].GetL() == snake.GetL(i));
		}
	}

	return b;
}

int Obsticle::getNum()
{
	return numberOBS;
}


Color Obsticle::OBS::GetC()
{
	return c;
}

void Obsticle::OBS::Update(const Snake& snake, const Food& food) {
	
	bool cond;
	do {
		Loc.x = ((rand() % (Bord::BordSizex / size - 5)) + 2);
		Loc.y = ((rand() % (Bord::BordSizey / size - 5)) + 2);
		bool Cond = false;
		for (int i = 0; i < snake.GetSize(); i++) {
			Cond = Cond || (Loc == snake.GetL(i));
		}
		Cond = Cond || (Loc == food.GetL());
		cond = Cond;
	} while (cond);
}

Location Obsticle::OBS::GetL()
{
	return Loc;
}
