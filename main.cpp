//************************************
//********** SPACE CONQUEST **********
//************************************
// Programmer: Ken Scattergood
//************************************

#include <SFML/Graphics.hpp>
#include "Primitives.h"
#include "Graphic2D.h"

#include "Globals.h"

void initialize();
void reset();
void doUserEvents(sf::Event&);
void updateMousePosition();
void doLogicLoop();
void doDrawLoop();

int main() {
	initialize();
	reset();
	while (window.isOpen() && GAME_IS_RUNNING) {
		sf::Event event;
		while (window.pollEvent(event)) {
			doUserEvents(event);
		}
		doLogicLoop();
		updateMousePosition();
		doDrawLoop();
	}
	window.close();
	return 0;
}

//Builds initial graphics and game state; only needs to be called when game loads
void initialize() {
	window.setMouseCursorVisible(false);
}

//Resets variables for a new game; called everytime a new game is created or loaded
void reset() {

}

//Handles user input
void doUserEvents(sf::Event& e) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) GAME_IS_RUNNING = false;
}

//Handles the game logic
void doLogicLoop() {

}

//Redraws the game
void doDrawLoop() {
	window.clear();
	window.draw(imgGalaxyBackground);
	window.draw(imgMouseCursor);
	window.display();
}

void updateMousePosition() {
	imgMouseCursor.setPosition(sf::Mouse::getPosition(window));
}

