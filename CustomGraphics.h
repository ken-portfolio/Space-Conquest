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
	sf::CircleShape c;
	c.setOutlineThickness(-1.f);
	for (int i = 0; i < 8; i++) {
		c.setFillColor(solarSystemColors[i]);
		c.setOutlineColor(solarSystemColors[i]);
		c.setPosition(6.f + (24 * i), 6.f);
		c.setRadius(6.f);
		imgSolarSystemGraphic.draw(c);
		c.setFillColor(sf::Color::Transparent);
		c.setPosition(2.f + (24 * i), 2.f);
		c.setRadius(10);
		imgSolarSystemGraphic.draw(c);
	}
	imgSolarSystemGraphic.setTileHeight(24);
	imgSolarSystemGraphic.setTileWidth(24);
}

#endif 

/*
#pragma once
#ifndef ASSEMBLEDART_HEADER
#define ASSEMBLEDART_HEADER

#include "Graphic2D.h"

class SolarSystemIcon : public Graphic2D {
public:
	SolarSystemIcon(sf::Color);
private:
};
SolarSystemIcon::SolarSystemIcon(sf::Color clr) : Graphic2D(16, 16) {
	sf::CircleShape c;
	c.setFillColor(clr);
	c.setPosition(4.f, 4.f);
	c.setRadius(4);
	draw(c);
	c.setFillColor(sf::Color::Transparent);
	c.setOutlineColor(clr);
	c.setOutlineThickness(-1.f);
	c.setPosition(1.f, 1.f);
	c.setRadius(7);
	draw(c);
}


#endif
*/