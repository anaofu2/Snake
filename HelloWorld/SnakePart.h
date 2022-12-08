#pragma once
#include "Play.h"

enum Heading{North, East, South, West};

class SnakePart
{
	friend class Snake; //either friend class or getters/setters for position
	Point2D pos;
	Play::Colour colour = Play::cWhite;
	const int size = 10; //diameter in pixels
	
public:
	SnakePart();
	SnakePart(Point2D position);
	void draw();
	Point2D getPos(); 
	void setPos(Point2D newPos);
};

class Snake
{

	Heading heading = North;
	int length = 2;
	SnakePart** parts = new SnakePart*[2];
	SnakePart* head = new SnakePart;

public:
	Snake();
	void AddPart();
	void draw();
	void move();
	void HandleInput();
	~Snake();
};
