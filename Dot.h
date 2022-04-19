#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "World.h"
#include "Config.h"
#include <BulletController.h>
#include "Object.h"

class Dot : public Object
{
	float rotation;
	int speedRotate;

	int widthSprite, heightSprite;

	b2PolygonShape shape;
	b2BodyDef bdef;
	b2Body* body;

	BulletController bombing;
public:
	Dot(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject);
	virtual void Update(float gameTime, std::list<Player*> tanks, std::list<Object*> objects);
	virtual void Draw(sf::RenderWindow& w);
};

