#include "BulletController.h"

BulletController::BulletController(std::string _nameTank)
{
	imageBullet.loadFromFile("images/ammo.png");
	textureBullet.loadFromImage(imageBullet);
	spriteBullet.setTexture(textureBullet);

	imageExplosion.loadFromFile("images/explosion.png");
	textureExplosion.loadFromImage(imageExplosion);
	spriteExplosion.setTexture(textureExplosion);

	nameTank = _nameTank;

	shoot = false;
	recharge = 1000;
	timer = recharge;

	buffer.loadFromFile("music/shoot.ogg");
	shootSound.setBuffer(buffer);
}

void BulletController::Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool _shoot, std::list<Player*> tanks,
	std::list<Object*> objects)
{
	if (timer > 0) {
		timer -= gameTime;
	}

	if (timer <= 0) {
		shoot = _shoot;
	}

	if (shoot && timer <= 0) {
		bullets.push_back(Bullet(spriteBullet, spriteExplosion, nameTank, timeLife));
		timer = recharge;
		shootSound.play();
	}

	for (auto bullet = bullets.begin(); bullet != bullets.end();)
	{
		bullet->Update(gameTime, positionTank, rotationGun, shoot, tanks, objects);
		if (bullet->getDeleteBullet())
		{
			bullet = bullets.erase(bullet);
		}
		else
			++bullet;
	}
}

void BulletController::Draw(sf::RenderWindow& w)
{
	for (auto bullet : bullets) {
		bullet.Draw(w);
	}
}
