#pragma once
#include <SFML/Graphics.hpp>

static const float NORMAL_TOLERANCE = 0.0001f;
using RectVertexArray = std::array<sf::Vector2f, 4>;

bool testCollision(const sf::RectangleShape& obb1, const sf::RectangleShape& obb2, sf::Vector2f& mtv);
float getLength(const sf::Vector2f& v);
sf::Vector2f getNormalized(const sf::Vector2f& v);
float dotProduct(const sf::Vector2f& a, const sf::Vector2f& b);
sf::Vector2f getNormal(const sf::Vector2f& v);
sf::Vector2f projectOnAxis(const RectVertexArray& vertices, const sf::Vector2f& axis);
bool areOverlapping(const sf::Vector2f& a, const sf::Vector2f& b);
float getOverlapLength(const sf::Vector2f& a, const sf::Vector2f& b);
sf::Vector2f getCenter(const sf::RectangleShape& shape);
RectVertexArray getVertices(const sf::RectangleShape& shape);
sf::Vector2f getPerpendicularAxis(const RectVertexArray& vertices, std::size_t index);
std::array<sf::Vector2f, 4> getPerpendicularAxes(const RectVertexArray& vertices1, const RectVertexArray& vertices2);
sf::RectangleShape spriteToRecShape(sf::Sprite sprite, sf::Vector2f position, float rotation);
