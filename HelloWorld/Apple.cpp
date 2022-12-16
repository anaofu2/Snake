#include "Apple.h"
#include "Play.h"

Apple::Apple() 
{	
	int x = (rand() % 63) * 10 + 5;
	int y = (rand() % 35) * 10 + 5;
	posApple = { x,y };
}

void Apple::drawApple() 
{
	Play::DrawCircle(posApple, rad, Play::cRed);
}

Point2D Apple::getPos()
{
	return posApple;
}

int Apple::getRad()
{
	return rad;
}