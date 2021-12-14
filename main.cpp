#include "NewGarphics.h"

int main()
{
	NewGarphics game;
	
	if (!game.ConstructConsole(460, 300, 2,2, L"Course Work'"))
		game.Loop();

	return 0;
}