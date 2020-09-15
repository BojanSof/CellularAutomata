#ifndef APP_HPP
#define APP_HPP

#include <Grid.hpp>
#include <Elementary.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

namespace CA {

class App {
public:
    App();
    
    App(unsigned int w, unsigned int h);

    App(unsigned int w, unsigned int h, 
        std::size_t r, std::size_t c);

    App(unsigned int w, unsigned int h, 
        std::size_t r, std::size_t c, 
        float cw, float ch);
    ~App();

    int menu();
    bool isRunning() const;
    void reset();
    void handleEvents();
    void update(/*sf::Time elapsed*/);
    void display();

    void run();

private:
    unsigned int width, height;
    std::size_t rows, columns;
    float cellWidth, cellHeight;
    std::string title;
    sf::RenderWindow window;
    std::shared_ptr<CA::CellularAutomaton> ca;
    //CA::Elementary elementaryCA;
    bool running;
};

}

#endif //APP_HPP