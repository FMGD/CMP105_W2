#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects


	//Text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}
	mouse_position_txt.setFont(font);
	mouse_position_txt.setString("Mouse Position (x,y)");
	mouse_position_txt.setCharacterSize(24);
	mouse_position_txt.setFillColor(sf::Color::Red);
	mouse_position_txt.setStyle(sf::Text::Bold | sf::Text::Underlined);

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{

	//Output to the console when 'W' is pressed
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "'W' was pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close(); //Run ones time more before close, giving the opportunity to store everything on memory
	}

	//Output to the console when 'J', 'K' and 'L' are pressed together
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "'J', 'K' and 'L' were pressed\n";
	}
	//CheckMouseDrag();
	if (input->isMouseLDown() && !measuring)
	{
		mouseX_position_ini = input->getMouseX();
		mouseY_position_ini = input->getMouseY();
		measuring = true;
	}
	else if( !input->isMouseLDown() && measuring )
	{
		mouseX_position_fin = input->getMouseX();
		mouseY_position_fin = input->getMouseY();

		//Following pitagoras
		d = sqrt( pow(mouseX_position_fin - mouseX_position_ini, 2) + pow(mouseY_position_fin - mouseY_position_ini, 2) );
		std::cout << "Distance of the drag: " + std::to_string(d) + "\n";

		measuring = false;
	}

}

// Update game objects
void Level::update()
{
	//Update mouse_position_txt
	mouse_position_txt.setString("Mouse Position (" + std::to_string(input->getMouseX()) + "," + std::to_string(input->getMouseY()) + ")");

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(mouse_position_txt);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}