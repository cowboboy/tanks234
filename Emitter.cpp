#include "Emitter.h"

Emitter::Emitter()
{
	mainImage.loadFromFile("images/particleSmoke.png");
	smokeImage.loadFromFile("images/particleFire.png");
}

void Emitter::Update(float time)
{
	for (auto particle = particles.begin(); particle != particles.end();)
	{
		if (!(*particle)->Dissapear())
		{
			(*particle)->Update(time);
			++particle;
		}
		else {
			delete (*particle);
			(*particle) = nullptr;
			particle = particles.erase(particle);
		}
	}
}

void Emitter::Draw(sf::RenderWindow& w)
{
	for (auto& particle : particles) {
		particle->Draw(w);
	}
}

sf::Vector2f Emitter::angleToVector2f(float angle, float speed)
{
	sf::Vector2f direction;

	direction.x = speed * cos(angle);
	direction.y = -speed * sin(angle);
	return direction;
}

void Emitter::ParticleGeneration(sf::Image& _image, sf::Vector2f _position, sf::Vector2f _velocity, float _angle,
	float _angleVel, float _size, float _sizeVel, sf::Color _color, sf::Color _colorVel, float _lifeTime)
{
	Particle* particle = new Particle(_image, _position, _velocity, _angle, _angleVel, _size, _sizeVel, _color,
		_colorVel, _lifeTime);
	//Particle particle(_image, _position, _velocity, _angle, _angleVel, _size, _sizeVel, _color,
	//	_colorVel, _lifeTime);

	particles.push_back(particle);
}

void Emitter::EngineSmoke(sf::Vector2f position)
{
	if (particles.size() < 100) {
		position.x += -2 + rand() % 3;
		position.y += -4 + rand() % 10;

		sf::Vector2f velocity = angleToVector2f(1.047 + 1.047 * rand() / (float)RAND_MAX,
			0.005f + 0.05f * rand() / (float)RAND_MAX);

		float angle = 6.28 * rand() / (float)RAND_MAX;
		float angleVel = -0.005f + 0.01f * rand() / (float)RAND_MAX;

		sf::Color color = sf::Color(63, 63, 63, 229);
		sf::Color colorVel = sf::Color(
			255 * (-0.00025f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.00025f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.00025f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.00075f + 0.000015f * rand() / (float)RAND_MAX)
		);

		float size = 0.1f + 1.2f * rand() / (float)RAND_MAX;

		float lifeTime = 2000;

		float sizeVel = 0.00025f;

		ParticleGeneration(mainImage, position, velocity, angle, angleVel, size, sizeVel, color,
			colorVel, lifeTime);

		position.x += rand() % 2;
		position.y += -3 + rand() % 2;

		sf::Vector2f velocity2 = angleToVector2f(1.047 + 1.047 * rand() / (float)RAND_MAX, 0);

		float angle2 = 6.28 * rand() / (float)RAND_MAX;
		float angleVel2 = -0.005f + 0.01f * rand() / (float)RAND_MAX;

		sf::Color color2 = sf::Color(229, 102, 51, 229);
		sf::Color colorVel2 = sf::Color(
			255 * (-0.0009f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.0004f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.0002f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.001f + 0.00025f * rand() / (float)RAND_MAX)
		);

		float size2 = 0.3f + 0.7f * rand() / (float)RAND_MAX;

		float lifeTime2 = 500;

		float sizeVel2 = -0.00005f;

		ParticleGeneration(mainImage, position, velocity2, angle2, angleVel2, size2, sizeVel2, color2,
			colorVel2, lifeTime2);
	}
}
