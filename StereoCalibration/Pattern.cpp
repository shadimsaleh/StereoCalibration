#include "Pattern.h"


Pattern::Pattern()
{
	row = 0;
	col = 0;
	sizeSqare = 0;
}

Pattern::Pattern(int r, int c, double s){
	row = r;
	col = c;
	sizeSqare = s;
}

Pattern::~Pattern()
{
}


int Pattern::getCol(){
	return col;
}

int Pattern::getRow(){
	return row;
}

int Pattern::getSize(){
	return sizeSqare;
}
