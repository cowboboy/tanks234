#include "Bullet.h"

Bullet::Bullet(sf::Sprite _spriteBullet, sf::Sprite _spriteExplosion, std::string _nameBullet, float _timeLife)
{
	spriteBullet = _spriteBullet;
	spriteExplosion = _spriteExplosion;

	shooting = false;

	speed = 2;

	iCurrFrame = 0;
	jCurrFrame = 0;
	iFrames = spriteExplosion.getLocalBounds().width / widthFrame;
	jFrames = spriteExplosion.getLocalBounds().height / widthFrame;
	explode = false;
	animationTime = 0;  

	//position = sf::Vector2f(0, 0);

	currTimeLife = timeLife;

	damage = 30;

	deleteBullet = false;

	nameBullet = _nameBullet;

	timeLife = _timeLife;
}

void Bullet::Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool shoot, std::list<Player*> tanks,
	std::list<Object*> objects)
{
	if (!shooting && !explode) {
		shooting = shoot;
		position = positionTank;
		rotation = rotationGun;
		currTimeLife = timeLife;
	}
	if (currTimeLife <= 0) {
		shooting = false;
		explode = true;
	}

	velocity = angleToVector2f(rotation, speed);

	if (shooting) {
		//position += speed * sf::Vector2f(cos(rotation * DEGTORAD), sin(rotation * DEGTORAD)) * gameTime; 
		position += velocity * gameTime;
	}

	if (explode) {
		if (animationTime > 0.1) {
			if ((iCurrFrame + 1) * (jCurrFrame + 1) == iFrames * jFrames) {
				iCurrFrame = 0;
				jCurrFrame = 0;
				explode = false;
				deleteBullet = true;
			}
			else {
				if (iCurrFrame < iFrames - 1) {
					++iCurrFrame;
				}
				else {
					iCurrFrame = 0;
					++jCurrFrame;
				}
			}
			animationTime = 0;
		}
		else {
			animationTime += gameTime;
		}
	}

	for (auto& tank : tanks) {
		if (shooting && nameBullet != tank->getName() && tank->takeDamage(damage, spriteBullet, velocity, position, rotation) == 1) {
			
			shooting = false;
			explode = true;
		}
	}
	for (auto& object : objects) {
		sf::Vector2f a;
		if (testCollision(spriteToRecShape(spriteBullet, position, rotation),
			spriteToRecShape(object->spriteObject, object->position, 0), a)) {
			if (object->life && object->nameObject != nameBullet) {
				object->reObject();
				shooting = false;
				explode = true;
				object->life = false;
			}
			if (object->nameObject == "dot" && object->nameObject != nameBullet) {
				shooting = false;
				explode = true;
			}
		}
	}

	currTimeLife -= gameTime;
}
void Bullet::Draw(sf::RenderWindow& w)
{
	if (explode) {
		spriteExplosion.setPosition(position);
		spriteExplosion.setRotation(rotation);
		spriteExplosion.setTextureRect(sf::IntRect(iCurrFrame * widthFrame, jCurrFrame * widthFrame, widthFrame, widthFrame));
		spriteExplosion.setScale(0.8, 0.8);
		spriteExplosion.setOrigin(spriteExplosion.getLocalBounds().width / 2, spriteExplosion.getLocalBounds().height / 2);
		w.draw(spriteExplosion);
	}
	if (shooting) {
		spriteBullet.setPosition(position);
		spriteBullet.setRotation(rotation);
		spriteBullet.setOrigin(spriteBullet.getLocalBounds().width / 2, spriteBullet.getLocalBounds().height / 2);
		w.draw(spriteBullet);
	}
}

bool Bullet::getDeleteBullet()
{
	return deleteBullet;
}

sf::Vector2f Bullet::angleToVector2f(float angle, float speed)
{
	sf::Vector2f direction;

	direction.x = speed * cos(angle * DEGTORAD);
	direction.y = speed * sin(angle * DEGTORAD);
	return direction;
}

sf::Vector2f Bullet::getPosition()
{
	return position;
}

float Bullet::getRotation()
{
	return rotation;
}

sf::Sprite& Bullet::getSprite()
{
	return spriteBullet;
}
