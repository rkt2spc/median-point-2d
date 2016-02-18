#include <vector>
#include <stdio.h>
#include "Point2D.h"
using namespace std;

//Functions
Point2D FindMedianPoint(vector<Point2D> points);
vector<Point2D> GenerateRandomPoints(int count, int lowerH = 0, int upperH = 10, int lowerV = 0, int upperV = 10);

int main()
{
	vector<Point2D> points = GenerateRandomPoints(10);
	for (int i = 0; i < 10; i++)
		printf("[%d,%d] ", points[i].x, points[i].y);

	Point2D medianPoint = FindMedianPoint(points);
	printf("\n\nMedianPoint: [%d,%d]\n", medianPoint.x, medianPoint.y);

	return 0;
}