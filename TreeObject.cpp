#include "TreeObject.h"

TreeObject::TreeObject(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject) :
	Object(_imageObject1, _imageObject2, _position, _nameObject)
{
	spriteObject.setTexture(textureObject1);
}

void TreeObject::reObject()
{
	spriteObject.setTexture(textureObject2);
}

void TreeObject::Draw(sf::RenderWindow& w)
{
	w.draw(spriteObject);
}
