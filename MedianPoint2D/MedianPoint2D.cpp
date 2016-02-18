#include <vector>
#include <algorithm>
#include "Point2D.h"
using namespace std;

Point2D FindMedianPoint(vector<Point2D> points)
{
	#pragma region Calculating Horizontal Cost
	//===========================================================================================
	//O(NLogN) Sort - sort horizontal x-coor increasing
	sort(points.begin(), points.end(), [](Point2D a, Point2D b) {
		return a.x < b.x;
	});

	//O(N) Calculate the total horizontal distance from each point to all the points from its left-side
	vector<int> lDist(points.size(), 0);
	for (int i = 1; i < points.size(); i++)
	{
		lDist[i] += (points[i].x - points[i - 1].x) * i;
		lDist[i] += lDist[i - 1];
	};

	//O(N) Calculate the total horizontal distance from each point to all the points from its right-side
	vector<int> rDist(points.size(), 0);
	for (int i = points.size() - 2; i >= 0; i--)
	{
		rDist[i] += (points[i + 1].x - points[i].x) * (points.size() - (i + 1));
		rDist[i] += rDist[i + 1];
	};

	//O(N) hCost[i] = lDist[i] + rDist[i]
	for (int i = 0; i < points.size(); i++)
		points[i].hCost = lDist[i] + rDist[i];
	//===========================================================================================
	#pragma endregion
	
	#pragma region Calculating Vertical Cost
	//===========================================================================================
	//O(NLogN) Sort - sort vertical y-coor increasing
	sort(points.begin(), points.end(), [](Point2D a, Point2D b) {
		return a.y < b.y;
	});

	//O(N) Calculate the total vertical distance from each point to all the points from its upper-side
	vector<int> upDist(points.size(), 0);
	for (int i = 1; i < points.size(); i++)
	{
		upDist[i] += (points[i].y - points[i - 1].y) * i;
		upDist[i] += upDist[i - 1];
	};

	//O(N) Calculate the total vertical distance from each point to all the points from its lower-side
	vector<int> lwDist(points.size(), 0);
	for (int i = points.size() - 2; i >= 0; i--)
	{
		lwDist[i] += (points[i + 1].y - points[i].y) * (points.size() - (i + 1));
		lwDist[i] += lwDist[i + 1];
	};

	//O(N) hCost[i] = lDist[i] + rDist[i]
	for (int i = 0; i < points.size(); i++)
		points[i].vCost = upDist[i] + lwDist[i];
	//===========================================================================================
	#pragma endregion

	//O(N) The Point closest to all other-points will have the smallest hCost & vCost
	Point2D result = points[0];
	for (int i = 1; i < points.size(); i++)
	{
		if (points[i].TotalCost() < result.TotalCost())
			result = points[i];
	}

	return result;
}


