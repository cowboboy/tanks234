#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Player;

class Object
{
public:
	sf::Image imageObject1;
	sf::Texture textureObject1;
	sf::Image imageObject2;
	sf::Texture textureObject2;
	sf::Sprite spriteObject;

	std::string nameObject;

	sf::Vector2f position;

	bool life;

	Object(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject);
	virtual void reObject();
	virtual void Update(float gameTime, std::list<Player*> tanks, std::list<Object*> objects);
	virtual void Draw(sf::RenderWindow& w);
	virtual ~Object();
};

