#pragma once
#ifndef WINDOWDRAWING_SPACECONQUEST_HEADER
#define WINDOWDRAWING_SPACECONQUEST_HEADER

#include <SFML/Graphics.hpp>
#include "Graphic2D.h"

/// <summary>
/// Redraws all the window contents
/// </summary>
void drawWindow() {

	//Restores background image
	window.clear();
	window.draw(imgGalaxyBackground);

	//Updates mouse
	imgMouseCursor.setPosition(sf::Mouse::getPosition(window));
	window.draw(imgMouseCursor);

	//Draws window buffer
	window.display();
}

#endif 
