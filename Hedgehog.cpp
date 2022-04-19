#include "Hedgehog.h"

Hedgehog::Hedgehog(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject) :
	Object(_imageObject1, _imageObject2, _position, _nameObject)
{
	spriteObject.setTexture(textureObject1);

	widthSprite = spriteObject.getLocalBounds().width;
	heightSprite = spriteObject.getLocalBounds().height;

	shape.SetAsBox(widthSprite / (SCALE * 2), heightSprite / (SCALE * 2));
	bdef.type = b2_staticBody;
	bdef.position.Set(position.x / SCALE, position.y / SCALE);
	body = World.CreateBody(&bdef);
	body->CreateFixture(&shape, 100);
}

void Hedgehog::Draw(sf::RenderWindow& w)
{
	spriteObject.setPosition(position);
	spriteObject.setOrigin(spriteObject.getLocalBounds().width / 2, spriteObject.getLocalBounds().height / 2);
	w.draw(spriteObject);
}

Hedgehog::~Hedgehog()
{
	body->GetWorld()->DestroyBody(body);
}
