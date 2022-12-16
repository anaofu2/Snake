#pragma once
#include "Play.h"

class Apple 
{
	Point2D posApple;
	int rad = 5;
	public:
		Apple();
		void drawApple();
		Point2D getPos();
		int getRad();		
};




