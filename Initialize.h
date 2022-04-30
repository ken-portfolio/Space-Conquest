#pragma once
#ifndef INITIALIZE_SPACECONQUEST_HEADER
#define INITIALIZE_SPACECONQUEST_HEADER

//Builds initial graphics and game state; 
//only needs to be called when game loads
void initialize() {
	window.setMouseCursorVisible(false);
}


//Resets variables and start conditions for a new game; 
//called anytime a new game is created or loaded
void initializeReset() {

}

#endif 
