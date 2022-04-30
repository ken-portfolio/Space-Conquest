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
Graphic2D imgSolarSystemGraphic(240, 24);



#endif 