#pragma once
#include <SFML/Graphics.hpp>

class Particle
{
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;
	sf::Vector2f velocity;

	float angle;
	float angleVel;

	float size;
	float sizeVel;

	sf::Color color;
	sf::Color colorVel;

	float lifeTime;
public:
	Particle(sf::Image& _image, sf::Vector2f _position, sf::Vector2f _velocity, float _angle, float _angleVel,
		float _size, float _sizeVel, sf::Color _color, sf::Color _colorVel, float _lifeTime);
	void Update(float time);
	void Draw(sf::RenderWindow& w);
	bool Dissapear();
};
