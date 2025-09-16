#pragma once
#include "SFML/Graphics.hpp"

class Segment
{
public:
	Segment(int t_size);

	void setPosition(sf::Vector2f t_newPos);
	sf::Vector2f getPosition();
	void distanceConstraint(sf::Vector2f t_otherPos);
	void draw(sf::RenderWindow &t_window);
private:

	float distanceBetweenSegs(sf::Vector2f t_pos, sf::Vector2f t_otherPos);

	sf::Vector2f m_pos;
	int m_size;
	sf::Vector2f m_otherPos;
	float m_distance;
	sf::CircleShape m_body;
};
