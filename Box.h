#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Box : public Object
{
	Box(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject);
	virtual void reObject();
	virtual void Draw(sf::RenderWindow& w);
};

