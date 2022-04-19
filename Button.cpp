#include "Button.h"

Button::Button()
{
}

Button::Button(sf::Image _imageButton, sf::Vector2f _position)
{
	imageButton = _imageButton;
	textureButton.loadFromImage(imageButton);
	spriteButton.setTexture(textureButton);
	spriteButton.setOrigin(spriteButton.getLocalBounds().width / 2,
		spriteButton.getLocalBounds().height / 2);

	position = _position;

	press = true;
	isPressed = false;
	active = false;

	timer = 0;
	timeDelay = 1000;
}

void Button::Update(float gameTime, sf::RenderWindow& w)
{
	isPressed = false;

	sf::Vector2i pixelPos = sf::Mouse::getPosition(w);
	sf::Vector2f pos = w.mapPixelToCoords(pixelPos);

	if (spriteButton.getGlobalBounds().contains(pos.x, pos.y)) {
		active = true;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
			press) {
			isPressed = true;
		}
	}
	else {
		active = false;
	}

	if (isPressed) {
		press = false;
	}
	if (!press) {
		timer += gameTime;
		if (timer >= timeDelay) {
			timer = 0;
			press = true;
		}
	}
}

void Button::Draw(sf::RenderWindow& w)
{
	spriteButton.setTexture(textureButton);
	if (isPressed) {
		spriteButton.setColor(sf::Color(0, 255, 255));
	}
	else {
		spriteButton.setColor(sf::Color(120, 255, 255));
	}
	if (active) {
		spriteButton.setColor(sf::Color(255, 255, 0));
	}
	else {
		spriteButton.setColor(sf::Color(153, 153, 153));
	}
	spriteButton.setPosition(position);
	spriteButton.setScale(2.f, 2.f);
	w.draw(spriteButton);
}

bool Button::getClick()
{
	return isPressed;
}
