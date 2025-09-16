#include "Segment.h"

Segment::Segment(int t_size) : m_size(t_size)
{
    m_pos = { 400.0f, 300.0f };

    m_body.setRadius(m_size);
    m_body.setFillColor(sf::Color::Green);
    m_body.setPosition(m_pos);
    m_body.setOrigin(m_size, m_size);

    m_distance = 40.0f; // distance between segments
}

void Segment::distanceConstraint(sf::Vector2f t_otherPos)
{

    sf::Vector2f dir = t_otherPos - m_pos; // get vector from the segment to the target segment
    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y); // gets the distance
    if (length == 0.f) return; // checks to avoid dividing by 0
    sf::Vector2f newPos = t_otherPos - (dir / length) * m_distance; // calculates new position at exactly m_distance 

    setPosition(newPos);
}

void Segment::draw(sf::RenderWindow& t_window)
{
    t_window.draw(m_body);
}

float Segment::distanceBetweenSegs(sf::Vector2f t_pos, sf::Vector2f t_otherPos)
{
    float dx = t_otherPos.x - t_pos.x;
    float dy = t_otherPos.y - t_pos.y;
    return std::sqrt(dx * dx + dy * dy);
}

void Segment::setPosition(sf::Vector2f t_newPosition)
{
    m_pos = t_newPosition;
    m_body.setPosition(m_pos);
}

sf::Vector2f Segment::getPosition()
{
    return m_pos;
}
