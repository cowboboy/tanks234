#pragma once
#include <SFML/Graphics.hpp>

class Button
{
	sf::Image imageButton;
	sf::Texture textureButton;
	sf::Sprite spriteButton;

	sf::Vector2f position;

	bool isPressed, press, active;

	float timeDelay;
	float timer;
public:
	Button();
	Button(sf::Image _imageButton, sf::Vector2f _position);
	void Update(float gameTime, sf::RenderWindow& w);
	void Draw(sf::RenderWindow& w);
	bool getClick();
};

