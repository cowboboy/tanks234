#include "Menu.h"

Menu::Menu(std::string text)
{
	imageButtonStart2.loadFromFile("images/gamepad2.png");
	imageButtonStart3.loadFromFile("images/gamepad3.png");
	imageButtonStart4.loadFromFile("images/gamepad4.png");
	darkScreen.setSize(sf::Vector2f(W, H));
	darkScreen.setFillColor(sf::Color(0, 0, 0, 200));
	buttonStart2 = Button(imageButtonStart2, sf::Vector2f(W / 4, H / 2));
	buttonStart3 = Button(imageButtonStart3, sf::Vector2f(W / 2, H / 2));
	buttonStart4 = Button(imageButtonStart4, sf::Vector2f(3 * W / 4, H / 2));

	imageIcon1.loadFromFile("images/ikonka2.png");
	textureIcon1.loadFromImage(imageIcon1);
	spriteIcon1.setTexture(textureIcon1);

	font.loadFromFile("fonts/Samson.ttf");
	winPlayer.setFont(font);
	winPlayer.setCharacterSize(30);
	winPlayer.setFillColor(sf::Color::Yellow);
	winPlayer.setString(text);
}

void Menu::Update(float gameTime, sf::RenderWindow& w)
{
	buttonStart2.Update(gameTime, w);
	buttonStart3.Update(gameTime, w);
	buttonStart4.Update(gameTime, w);
}

void Menu::Draw(sf::RenderWindow& w)
{
	w.draw(darkScreen);
	buttonStart2.Draw(w);
	buttonStart3.Draw(w);
	buttonStart4.Draw(w);
	spriteIcon1.setOrigin(spriteIcon1.getLocalBounds().width / 2, spriteIcon1.getLocalBounds().height / 2);
	spriteIcon1.setPosition(W / 2, H / 4);
	spriteIcon1.setScale(2, 2);
	w.draw(spriteIcon1);
	winPlayer.setPosition(W / 2, 3 * H / 4);
	winPlayer.setOrigin(winPlayer.getLocalBounds().width / 2, winPlayer.getLocalBounds().height / 2);
	w.draw(winPlayer);
}

int Menu::isGame()
{
	if (buttonStart2.getClick()) {
		return 2;
	}
	else if (buttonStart3.getClick()) {
		return 3;
	}
	else if (buttonStart4.getClick()) {
		return 4;
	}
	else {
		return 0;
	}
	
}
