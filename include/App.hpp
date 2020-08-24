#ifndef APP_HPP
#define APP_HPP

#include <Grid.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace CA {

class App {
public:
    App();
    App(int w, int h);
    ~App();

    bool isRunning() const;
    void reset();
    void handleEvents();
    void update();
    void display();

private:
    int width, height;
    std::string title;
    sf::RenderWindow window;
    Grid grid;
    sf::RectangleShape **rectCells;
    bool running;
};

}

#endif //APP_HPP