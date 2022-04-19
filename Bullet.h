#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Config.h"
#include "Player.h"
#include "OBB.h"
#include "Object.h"

class Player;

class Bullet {
	sf::Sprite spriteBullet;

	sf::Sprite spriteExplosion;

	sf::Vector2f position;
	sf::Vector2f velocity;

	std::string nameBullet;

	const int widthFrame = 130;
	int iFrames, jFrames;
	int iCurrFrame, jCurrFrame;
	float animationTime;
	bool explode;

	float speed;

	float rotation;

	bool shooting;

	float timeLife;
	float currTimeLife;

	int damage;

	bool deleteBullet;
public:
	Bullet(sf::Sprite _spriteBullet, sf::Sprite _spriteExplosion, std::string _nameBullet, float _timeLife = 3000);
	void Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool shoot, std::list<Player*> tanks,
		std::list<Object*> objects);
	void Draw(sf::RenderWindow& w);
	bool getDeleteBullet();
	sf::Vector2f angleToVector2f(float angle, float speed);
	sf::Vector2f getPosition();
	float getRotation();
	sf::Sprite& getSprite();
};



