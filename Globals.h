#pragma once
#ifndef GLOBALS_SPACECONQUEST_HEADER
#define GLOBALS_SPACECONQUEST_HEADER

#include "Graphic2D.h"

const unsigned int SCREEN_WIDTH = 1920;
const unsigned int SCREEN_HEIGHT = 1080;

bool GAME_IS_RUNNING = true;

sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "", sf::Style::Fullscreen);
sf::Event windowEvent;

Graphic2D imgMouseCursor("images/cursor.png");
Graphic2D imgGalaxyBackground("images/galaxy.jpg");



#endif 
