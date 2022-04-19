#pragma once
#include <SFML/Graphics.hpp>
#include <Button.h>
#include "Config.h"

class Menu
{
	sf::RectangleShape darkScreen;
	Button buttonStart2;
	Button buttonStart3;
	Button buttonStart4;
	sf::Image imageButtonStart2;
	sf::Image imageButtonStart3;
	sf::Image imageButtonStart4;

	sf::Image imageIcon1;
	sf::Texture textureIcon1;
	sf::Sprite spriteIcon1;

	sf::Font font;
	sf::Text winPlayer;
public:
	Menu(std::string text = "");
	void Update(float gameTime, sf::RenderWindow& w);
	void Draw(sf::RenderWindow& w);
	int isGame();
};

