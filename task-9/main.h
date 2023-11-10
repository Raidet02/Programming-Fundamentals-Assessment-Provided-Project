#pragma once
#include <iostream>
using namespace std;


//TODO: Build Vector2 structure
//TODO: Write function to return distance between two Vector2s called GetDistanceBetweenPoints.

//You will need the Euclidean distance formula to complete this task. It is
//given in the article:
//
// - https://en.wikipedia.org/wiki/Euclidean_distance

struct Vector2 //creates the struct Vector2
{
public:
	float xCoordinates = 0.0f;
	float yCoordinates = 0.0f;
};

float GetDistanceBetweenPoints(Vector2 vector2P, Vector2 vector2Q) //creates the function GetDistanceBetweenPoints
{
	float distanceBetween = 0.0f; //creates the varibales needed
	float distanceX = 0.0f;
	float distanceY = 0.0f;
	float distanceXY = 0.0f;

	distanceX = pow((vector2Q.xCoordinates - vector2P.xCoordinates), 2); //squares the value of coordinate 1 - coordinate 2 for both the X and Y
	distanceY = pow((vector2Q.yCoordinates - vector2P.yCoordinates), 2);

	cout << "This is the distance between X1 (P1) and X2 (Q1): " << sqrt(distanceX) << endl << "This is the distance between Y1 (P2) and Y2 (Q2): " << sqrt(distanceY) << endl; //pints out each distance to the console

	distanceXY = distanceX + distanceY;

	distanceBetween = sqrt(distanceXY); //square roots the added distances

	return distanceBetween;
}
