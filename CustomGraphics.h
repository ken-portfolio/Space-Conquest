#pragma once
#ifndef CUSTOMGRAPHICS_SPACECONQUEST_HEADER
#define CUSTOMGRAPHICS_SPACECONQUEST_HEADER

#include "Globals.h"

/// <summary>
/// Small circular graphics on the galaxy view screen
/// used to annotate the position of a system
/// </summary>
void buildSolarSystemCustomGraphic() {
	const sf::Color solarSystemColors[8] = {sf::Color(100,100,100), sf::Color::Green, sf::Color::Red,
																					sf::Color::Blue, sf::Color::Yellow, sf::Color::Cyan,
																					sf::Color::Black, sf::Color::White };

	for (int i = 0; i < 8; i++) {
		
	}
}

#endif 