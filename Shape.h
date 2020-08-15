/*
This file defines the classes Circle and Square with Shape as their parent interface.
*/
#pragma once

#include<tuple>

class Circle;
class Square;

class Shape
{
public:
	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual bool IsInside(float X, float Y) const = 0;
	virtual std::tuple<float, float> GetCenterCoordinates() const = 0;
	virtual ~Shape();
};

class Circle : public Shape
{
public:
	Circle(float X, float Y, float r) : centerX(X), centerY(Y), radius(r) {};
	virtual std::tuple<float, float> GetCenterCoordinates() const final;
	virtual float GetArea() const final;
	virtual float GetPerimeter() const final;
	virtual bool IsInside(float X, float Y) const final;
	float GetRadius() const;
	bool FitInsideCircle(Square square) const;
private:
	float centerX;
	float centerY;
	float radius;
};

/*A general assumption made is that the square is parallel to the axis.
If it is not, the formula for the coordinates of square corners varies*/
class Square : public Shape
{
public:
	Square(float X, float Y, float l) : centerX(X), centerY(Y), length(l) {};
	virtual std::tuple<float, float> GetCenterCoordinates() const final;
	virtual float GetArea() const final;
	virtual float GetPerimeter() const final;
	virtual bool IsInside(float X, float Y) const final;
	float GetLength() const;
	bool FitInsideSquare(Circle circle) const;
private:
	float centerX;
	float centerY;
	float length;
};
