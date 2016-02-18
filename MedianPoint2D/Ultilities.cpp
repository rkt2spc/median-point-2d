#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Point2D.h"
using namespace std;

vector<Point2D> GenerateRandomPoints(int count, int lowerH = 0, int upperH = 10, int lowerV = 0, int upperV = 10)
{
	srand(time(NULL));
	vector<Point2D> randomPoints;
	for (int i = 0; i < count; i++)
	{
		int x = rand() % upperH + lowerH;
		int y = rand() % upperV + lowerV;
		randomPoints.push_back(Point2D(x, y));
	}

	return randomPoints;
}