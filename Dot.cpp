#include "Dot.h"

Dot::Dot(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject) : 
	bombing("dot"), Object(_imageObject1, _imageObject2, _position, _nameObject)
{
	spriteObject.setTexture(textureObject1);

	rotation = 0;
	speedRotate = 15.f;

	widthSprite = spriteObject.getLocalBounds().width;
	heightSprite = spriteObject.getLocalBounds().height;

	shape.SetAsBox(widthSprite / (SCALE * 2), heightSprite / (SCALE * 2));
	bdef.type = b2_staticBody;
	bdef.position.Set(position.x / SCALE, position.y / SCALE);
	body = World.CreateBody(&bdef);
	body->CreateFixture(&shape, 100);
}

void Dot::Update(float gameTime, std::list<Player*> tanks, std::list<Object*> objects)
{
	rotation += speedRotate * gameTime * 0.001f;
	bombing.recharge = 1000;
	bombing.Update(gameTime, position, rotation, true, tanks, objects);
	bombing.timeLife = rand() % 1000 + 1000;
}

void Dot::Draw(sf::RenderWindow& w)
{
	spriteObject.setPosition(position);
	spriteObject.setOrigin(spriteObject.getLocalBounds().width / 2, spriteObject.getLocalBounds().height / 2);
	bombing.Draw(w);
	w.draw(spriteObject);
}
