#include "SnakePart.h"

SnakePart::SnakePart(Point2D position)
{
	srand(time(0)); //seeds rand() to time to make numbers more random.
	pos = position;
	int red = rand() % 100;
	int green = rand() % 100;
	int blue = rand() % 100;
	colour = Play::Colour(red, green, blue);
}

void SnakePart::draw()
{
	Play::DrawCircle(pos, size/2, colour);
}