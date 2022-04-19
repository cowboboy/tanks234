#pragma once
#include "Object.h"
#include <SFML\Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Config.h"
#include "World.h"

class Hedgehog : public Object
{
	b2PolygonShape shape;
	b2BodyDef bdef;
	b2Body* body;

	int widthSprite, heightSprite;
	public:
		Hedgehog(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject);
		virtual void Draw(sf::RenderWindow& w);
		virtual ~Hedgehog();
};

