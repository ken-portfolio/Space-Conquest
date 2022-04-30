#pragma once
#ifndef INITIALIZE_SPACECONQUEST_HEADER
#define INITIALIZE_SPACECONQUEST_HEADER


/// <summary>
/// Only executes one time at program launch; 
/// responsible for initializing window, 
/// persistant game states, and creating 
/// custom graphics and images.
/// </summary>
void initialize() {

	settings.antialiasingLevel = 10;
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "", sf::Style::Fullscreen, settings);
	window.setMouseCursorVisible(false);

	//Found in CustomGraphics.h
	buildSolarSystemCustomGraphic();


}


/// <summary>
/// Executes each time a new game is started or loaded;
/// Responsible for resetting startup variables, game
/// states, regenerating universe, OR loading a pre-existing
/// game from file.
/// </summary>
void initializeReset() {

}

#endif 
