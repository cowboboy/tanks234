#include "Object.h"

Object::Object(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject)
{
	imageObject1 = _imageObject1;
	imageObject2 = _imageObject2;
	textureObject1.loadFromImage(imageObject1);
	textureObject2.loadFromImage(imageObject2);
	position = _position;
	nameObject = _nameObject;
	life = true;
	spriteObject.setPosition(position);
}

void Object::reObject()
{
	
}

void Object::Update(float gameTime, std::list<Player*> tanks, std::list<Object*> objects)
{
}

void Object::Draw(sf::RenderWindow& w)
{
	spriteObject.setScale(0.4, 0.4);
	w.draw(spriteObject);
}

Object::~Object()
{

}
