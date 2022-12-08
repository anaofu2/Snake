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

SnakePart::SnakePart()
{
	pos = { 320,180 };
}

void SnakePart::draw()
{
	Play::DrawCircle(pos, size/2, colour);
}

Point2D SnakePart::getPos()
{
	return pos;
}

void SnakePart::setPos(Point2D newPos)
{
	pos = newPos;
}


Snake::Snake()
{
	parts[0] = head;
	parts[1] = new SnakePart({ 320,190 });
}

void Snake::AddPart() //WIP
{
	length += 1;
	SnakePart** newParts = new SnakePart*[length];
	memcpy(newParts, parts, sizeof(SnakePart) * length-1);
	newParts[length - 1] = new SnakePart(newParts[length - 2]->pos);
	delete[] parts;
	parts = newParts;
}

void Snake::draw()
{
	for (int i = 0; i < length; i++)
	{
		parts[i]->SnakePart::draw();
	}
}

void Snake::move()
{
	for (int i = length - 1; i > 0; i--)
	{
		parts[i]->pos = (parts[i - 1]->pos);
	}
	
	switch (heading)
	{
		case North:
			head->pos.y -= 10;
			break;
		case East:
			head->pos.x += 10;
			break;
		case South:
			head->pos.y += 10;
			break;
		case West:
			head->pos.x -= 10;
			break;
	}
}

void Snake::HandleInput()
{
	if (Play::KeyDown(VK_UP))
		heading = North;
	if (Play::KeyDown(VK_RIGHT))
		heading = East;
	if (Play::KeyDown(VK_DOWN))
		heading = South;
	if (Play::KeyDown(VK_LEFT))
		heading = West;
}

Snake::~Snake()
{
	for (int i = 0; i < length; i++)
		delete parts[i];
	delete[] parts;
}