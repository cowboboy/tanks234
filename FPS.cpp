#include "FPS.h"

FPS::FPS() : fps(0), frames(0), timer(0)
{
	font.loadFromFile("fonts/Samson.ttf");
	fpsText.setString("");
	fpsText.setFont(font);
	fpsText.setFillColor(sf::Color(0, 0, 0));
	fpsText.setCharacterSize(50);
	fpsText.setPosition(20, 20);
}

void FPS::Update(float gameTime)
{
	timer += gameTime;
	if (timer >= 1000.f) {
		timer = 0;
		fps = frames;
		frames = 0;
		fpsText.setString(std::to_string(fps));
	}
	++frames;
}

void FPS::Draw(sf::RenderWindow& w)
{
	w.draw(fpsText);
}

int FPS::getFPS()
{
	return fps;
}
