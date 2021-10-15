#ifndef APP_HPP
#define APP_HPP

#include <Configuration.hpp>
#include <Elementary.hpp>
#include <GameOfLife.hpp>
#include <LangtonAnt.hpp>
#include <BriansBrain.hpp>
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
    int options();
    bool isRunning() const;
    void reset();
    void handleEvents();
    void update(/*sf::Time elapsed*/);
    void display();

    void run();

private:
    //unsigned int width, height;
    //std::size_t rows, columns;
    //float cellWidth, cellHeight;
    CA::Configuration config;
    std::string title;
    sf::RenderWindow window;
    std::shared_ptr<CA::CellularAutomaton> ca;
    //CA::Elementary elementaryCA;
    bool running;
private:
    static const int ELEMENTARY_MENU_ENTRY      = 1;
    static const int GAME_OF_LIFE_MENU_ENTRY    = 2;
    static const int LANGTONS_ANT_MENU_ENTRY    = 3;
    static const int BRIANS_BRAIN_MENU_ENTRY    = 4;
    static const int OPTIONS_MENU_ENTRY         = 5;
    static const int EXIT_MENU_ENTRY            = 6;
};

}

#endif //APP_HPP