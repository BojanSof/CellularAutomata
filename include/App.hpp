#ifndef APP_HPP
#define APP_HPP

#include <Grid.hpp>
#include <Elementary.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace CA {

class App {
public:
    App();
    
    App(unsigned int w, unsigned int h);

    App(unsigned int w, unsigned int h, 
        unsigned int rows, unsigned int columns);

    App(unsigned int w, unsigned int h, 
        unsigned int rows, unsigned int columns, 
        unsigned int cw, unsigned int ch);
    ~App();


    bool isRunning() const;
    void reset();
    void handleEvents();
    void update(sf::Time elapsed);
    void display();

    void run();

private:
    unsigned int width, height;
    std::string title;
    sf::RenderWindow window;
    CA::Elementary elementaryCA;
    bool running, drawing;
};

}

#endif //APP_HPP