#pragma once
#ifndef GLOBALS_SPACECONQUEST_HEADER
#define GLOBALS_SPACECONQUEST_HEADER


const unsigned int SCREEN_WIDTH = 1920;
const unsigned int SCREEN_HEIGHT = 1080;


bool GAME_IS_RUNNING = true;


sf::ContextSettings settings;
sf::RenderWindow window; 
sf::Event windowEvent;


//Graphics loaded from 'images' game folder
Graphic2D imgMouseCursor("images/cursor.png");
Graphic2D imgGalaxyBackground("images/galaxy.jpg");


//Graphics constructed at launch (CustomGraphics.h)
Graphic2D imgSolarSystemGraphic(320, 32);



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