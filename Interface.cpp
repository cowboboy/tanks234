#include "Interface.h"
#include "Map.h"

Interface::Interface() : timer(900)
{
	font.loadFromFile("fonts/Samson.ttf");
	timerText.setString("00:00");
	timerText.setFont(font);
	timerText.setFillColor(sf::Color(0, 0, 0));
	timerText.setCharacterSize(100);
	
}

void Interface::Update(float time)
{
	if (timer > 0) {
		timerText.setString(clock(timer)); 
		if (timer < 10)
			timerText.setCharacterSize(100 + 50 * cos(timer)); 
		sf::FloatRect textRect = timerText.getLocalBounds();
		timerText.setOrigin(textRect.width / 2, textRect.height / 2);
		timerText.setPosition(W / 2, textRect.height);
		 
		timer -= time;
	} else {
		timerText.setString("Конец боя!");
	}
}

std::string Interface::clock(int time) // formst time in seconds to XX:XX form
{
	std::string result = "00:00";
	int minutes = time / 60, seconds = time % 60;
	for (int i = 1;; --i) {
		result[i] = (minutes % 10) + '0';
		minutes /= 10;
		if (minutes == 0) break;
	}
	for (int i = 4;; --i) {
		result[i] = seconds % 10 + '0';
		seconds /= 10;
		if (seconds == 0) break;
	}
	return result;
}

void Interface::draw(sf::RenderWindow& w)
{
	w.draw(timerText);
}

int Interface::getTime()
{
	return timer;
}
