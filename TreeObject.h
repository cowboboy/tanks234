#pragma once
#include "Object.h"

class TreeObject : public Object
{
public:
	TreeObject(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject);
	virtual void reObject();
	virtual void Draw(sf::RenderWindow& w);
};

