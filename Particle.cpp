#include "Particle.h"
#include <iostream>

Particle::Particle(sf::Image& _image, sf::Vector2f _position, sf::Vector2f _velocity, float _angle, float _angleVel, float _size, float _sizeVel, sf::Color _color, sf::Color _colorVel, float _lifeTime)
{
	image = _image;
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	position = _position;
	velocity = _velocity;

	angle = _angle;
	angleVel = _angleVel;

	size = _size;
	sizeVel = _sizeVel;

	color = _color;
	colorVel = _colorVel;

	lifeTime = _lifeTime;
}

void Particle::Update(float time)
{
	lifeTime -= time;
	position += velocity * time;
	angle += angleVel * time;
	size += sizeVel * time;
	color.r += colorVel.r * time;
	color.g += colorVel.g * time;
	color.b += colorVel.b * time;
	color.a += colorVel.a * time;
}

void Particle::Draw(sf::RenderWindow& w)
{
	sprite.setColor(color);
	sprite.setPosition(position);
	sprite.setRotation(angle);
	sprite.setScale(size * 0.08, size * 0.08);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	w.draw(sprite);
}

bool Particle::Dissapear()
{
	return (lifeTime <= 0 || size <= 0);
}
