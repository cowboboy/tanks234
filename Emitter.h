#pragma once
#include <list>
#include <iostream>
#include "Particle.h"

class Emitter
{
protected:
	std::list<Particle*> particles;

	sf::Image mainImage;
	sf::Image smokeImage;
public:
	Emitter();
	void Update(float time);
	void Draw(sf::RenderWindow& w);
	sf::Vector2f angleToVector2f(float angle, float speed);
	void ParticleGeneration(sf::Image& _image, sf::Vector2f _position, sf::Vector2f _velocity, float _angle,
		float _angleVel, float _size, float _sizeVel, sf::Color _color, sf::Color _colorVel, float _lifeTime);
	virtual void EngineSmoke(sf::Vector2f _position);
};

