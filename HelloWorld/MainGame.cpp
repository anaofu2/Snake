#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Apple.h"
#include "SnakePart.h"

int DISPLAY_WIDTH = 640;
int DISPLAY_HEIGHT = 360;
int DISPLAY_SCALE = 2;

int frames = 0;
Snake snake; //test code
Apple* apple = new Apple;
// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
	srand(time(0)); //seeds rand() to time to make numbers more random.
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	Play::ClearDrawingBuffer( Play::cBlack );
	snake.draw();
	apple->drawApple();
	snake.handleInput();
	if (frames % 6 == 0)
	{
		snake.move();
		frames = 0;
	}
	if (snake.collide(*apple))
	{
		snake.addPart();
		delete apple;
		apple = new Apple;
	}
	frames++;
	Play::PresentDrawingBuffer();
	return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	delete apple;
	Play::DestroyManager();
	return PLAY_OK;
}
