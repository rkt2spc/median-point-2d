#pragma once

class Point2D
{
public:
	int hCost = 0;
	int vCost = 0;
	int x, y;

	Point2D(int X, int Y)
	{
		x = X;
		y = Y;
	}
	int TotalCost()
	{
		return hCost + vCost;
	}
};