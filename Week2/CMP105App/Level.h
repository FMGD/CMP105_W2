#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here
	sf::Font font;
	sf::Text mouse_position_txt;

	int mouseX_position_ini = -1;
	int mouseY_position_ini = -1;

	int mouseX_position_fin;
	int mouseY_position_fin;

	bool measuring = false;
	float d = 0;
};