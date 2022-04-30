//************************************
//********** SPACE CONQUEST **********
//************************************
// Programmer: Ken Scattergood
//************************************


//Generic headers
#include <SFML/Graphics.hpp>
#include "Primitives.h"
#include "Graphic2D.h"

//Specific 'Space Conquest' headers
#include "Globals.h"
#include "CustomGraphics.h"
#include "Initialize.h"
#include "UserEvents.h"
#include "AIEvents.h"
#include "ProcessingEvents.h"
#include "WindowDrawing.h"



int main() {

	initialize(); //one time execution at program launch
	initializeReset(); //executes each time a new game is created/loaded

	while (window.isOpen() && GAME_IS_RUNNING) {

		//Process User Events (mouse & keyboard)
		sf::Event event;
		while (window.pollEvent(event)) {
			processUserEvents(event);
		}
		
		//Basic game processes handled at timer tick (resource income+, ship movement, etc.)
		processGameEvents();

		drawWindow();
	}

	window.close();
	return 0;
}

