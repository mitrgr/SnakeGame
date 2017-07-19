#include "Location.h"
#include <time.h>
#include <stdlib.h>
#include "Colors.h"


#pragma once
class Food
{
public:
	Food();
	~Food();
	void Update();
	void UpdateCol();
	Color GetC() const;
	int GetS() const;
	Location GetL() const;
private:
	Color c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	static constexpr int size = 10;
	Location Loc;
	
};

