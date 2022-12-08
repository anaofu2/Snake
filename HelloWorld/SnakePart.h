#pragma once
#include "play.h"

class SnakePart
{
	Point2D pos;
	Play::Colour colour = Play::cBlack;
	const int size = 10; //diameter in pixels
	
public:
	SnakePart(Point2D position);
	void draw();
};