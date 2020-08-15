/*
Check the header for description
*/

#include "Shape.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <tuple>

using namespace std;

Shape::~Shape()
{
}

/*Implementaton of Circle Functions*/

float Circle::GetArea() const
{
	return 3.14*pow(radius, 2);
}

float Circle::GetPerimeter() const
{
	return 2*3.14*radius;
}

tuple<float, float> Circle::GetCenterCoordinates() const
{
	return make_tuple(centerX, centerY);
}

bool Circle::IsInside(float X, float Y) const
{
	return pow(X - centerX, 2) + pow(Y - centerY, 2) <= pow(radius, 2) ? true : false;
}

float Circle::GetRadius() const
{
	return radius;
}

bool Circle::FitInsideCircle(Square square) const
{
	auto halfLength = square.GetLength() / 2;
	auto[sqCenterX, sqCenterY] = square.GetCenterCoordinates();
	auto sqTop(sqCenterY + halfLength), sqBottom(sqCenterY - halfLength), sqLeft(sqCenterX - halfLength), sqRight(sqCenterX + halfLength);

	//farthest corner of square from circle center
	auto maxX = max(centerX - sqLeft, sqRight - centerX);
	auto maxY = max(centerY - sqTop, sqBottom - centerY);

	return pow(maxX, 2) + pow(maxY, 2) <= pow(radius, 2);
}

/*Implementation of Square Funcions*/

float Square::GetArea() const
{
	return pow(length, 2);
}

float Square::GetPerimeter() const
{
	return 4*length;
}

float Square::GetLength() const
{
	return length;
}

tuple<float, float> Square::GetCenterCoordinates() const
{
	return make_tuple(centerX, centerY);
}

bool Square::IsInside(float X, float Y) const
{
	auto halfLength = length / 2;
	auto sqTop(centerY + halfLength), sqBottom(centerY - halfLength), sqLeft(centerX - halfLength), sqRight(centerX + halfLength);

	if ((sqLeft <= X <= sqRight) && (sqBottom <= Y <= sqTop))
		return true;

	return false;
}

bool Square::FitInsideSquare(Circle circle) const
{
	auto radius = circle.GetRadius();
	auto[cCenterX, cCenterY] = circle.GetCenterCoordinates();

	auto halfLength = length / 2;
	auto sqTop(centerY + halfLength), sqBottom(centerY - halfLength), sqLeft(centerX - halfLength), sqRight(centerX + halfLength);

	/* The reason why I have this split is to make the code more readable.
	Another option is to store each condition in separate variable and use C++17 fold expression */
	if ((cCenterX + radius) > sqRight)
		return false;
	else if ((cCenterX - radius) < sqLeft)
		return false;
	else if ((cCenterY + radius) > sqTop)
		return false;
	else if ((cCenterY - radius) < sqBottom)
		return false;

	return true;
}