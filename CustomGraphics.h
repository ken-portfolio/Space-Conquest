#pragma once
#ifndef CUSTOMGRAPHICS_SPACECONQUEST_HEADER
#define CUSTOMGRAPHICS_SPACECONQUEST_HEADER

#include "Globals.h"

/// <summary>
/// Small circular graphics on the galaxy view screen
/// used to annotate the position of a system
/// </summary>
void buildSolarSystemCustomGraphic() {
	const sf::Color solarSystemColors[3] = {sf::Color(100,100,100), sf::Color::Green, sf::Color::Red};

	for (int i = 0; i < 3; i++) {
		std::cout << solarSystemColors[i].r << std::endl;
	}
}

#endif 