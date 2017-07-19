#include "Location.h"
#include "Colors.h"
#include <stdlib.h>
#include "Snake.h"

#pragma once
class Obsticle
{


public:
	class OBS
	{
	public:
		OBS() :
			Loc(0, 1)
		{
		}
		
		Color GetC();
		void Update(const Snake& snake, const Food& food);
		Location GetL();

	private:
		
		Color c = { 200,50,50 };
		Location Loc;
	};
public:
	
	bool HitOBS(const Snake& snake);

	int getNum();

	static constexpr int size = 10;
	static constexpr int MAXobst = 1000;
	OBS obs[MAXobst];
	void addOBS();

	Obsticle();


private:
	
	int numberOBS = 0;
	


};

