#pragma once
struct Location
{
	Location(int inx, int iny) {
		x = inx;
		y = iny;
	}

	void operator+=(Location l) {
		x += l.x;
		y += l.y;
	}
	bool operator==(Location l) {
		return(x == l.x && y == l.y);
	}

	int x;
	int y;

}; 


