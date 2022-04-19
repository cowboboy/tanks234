#include "Box.h"

void Box::reObject()
{
	life = false;
}

void Box::Draw(sf::RenderWindow& w)
{
	w.draw(spriteObject);
}
