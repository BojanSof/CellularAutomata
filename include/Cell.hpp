#ifndef CELL_HPP
#define CELL_HPP

#include <State.hpp>
#include <SFML/Graphics.hpp>

namespace CA {

class Cell : public sf::Drawable {
public:
    Cell();
    Cell(const CA::State &s);
    Cell(float w, float h);
    Cell(const CA::State &s, float w, float h);
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const CA::State &getState() const;
    float getWidth() const;
    float getHeight() const;
    const sf::Vector2f &getPosition() const;
    const sf::Vector2f &getSize() const;

    void setState(const CA::State &s);
    void setWidth(float w);
    void setHeight(float h);
    void setPosition(float x, float y);
    void setSize(float w, float h);
    void setColor(const sf::Color &color);
    void setOutlineColor(const sf::Color &color);
    void setOutlineThickness(float t);
    void setStateColor(const CA::State &s, const sf::Color &c);

private:
    CA::State state;
    sf::RectangleShape rect;
};

}

#endif //CELL_HPP