#ifndef CELL_HPP
#define CELL_HPP

#include <State.hpp>
#include <SFML/Graphics.hpp>

namespace CA {

class Cell : public sf::Drawable {
public:
    Cell();
    Cell(const CA::State &s);
    Cell(unsigned int w, unsigned int h);
    Cell(const CA::State &s, unsigned int w, unsigned int h);
    
    CA::State getState() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    
    void setState(const CA::State &s);
    void setWidth(unsigned int w);
    void setHeight(unsigned int h);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void setColor(const sf::Color &color);

private:
    CA::State state;
    unsigned int width, height;
    sf::RectangleShape rect;
};

}

#endif //CELL_HPP