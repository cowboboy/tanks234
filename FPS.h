#pragma once
#include <SFML/Graphics.hpp>

class FPS
{
	int fps, frames;
	float timer;
	sf::Clock clock;

	sf::Font font;
	sf::Text fpsText;
public:
	FPS();
	void Update(float gameTime);
	void Draw(sf::RenderWindow& w);
	int getFPS();
};

