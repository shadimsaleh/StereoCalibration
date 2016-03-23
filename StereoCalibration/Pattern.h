#ifndef PATTERN_H
#define PATTERN_H

#pragma once
class Pattern
{
public:
	Pattern();
	Pattern(int r, int c, double s);
	~Pattern();
	int getCol();
	int getRow();
	int getSize();
private:
	int row;
	int col;
	double sizeSqare;
};

#endif PATTERN_H

