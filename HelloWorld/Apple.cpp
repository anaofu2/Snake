#include "Apple.h"
#include "Play.h"



Apple::Apple() {
	//srand(time(0));
	int x = (rand() % 64) * 10;
	int y = (rand() % 36) * 10;
	posApple = {x,y};

}

void Apple::DrawApple() {

	Play::DrawCircle(posApple, rad, Play::cRed);

	
}