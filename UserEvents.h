#pragma once
#ifndef USEREVENTS_SPACECONQUEST_HEADER
#define USEREVENTS_SPACECONQUEST_HEADER

#include <SFML/Graphics.hpp>

void processUserEvents(sf::Event&) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) GAME_IS_RUNNING = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) GAME_IS_RUNNING = false;
}

#endif 
