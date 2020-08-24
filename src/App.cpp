#include <App.hpp>
#include <Common.hpp>
#include <iostream>

CA::App::App() : App(APP_WIDTH, APP_HEIGHT) {}

CA::App::App(unsigned int w, unsigned int h) : 
            App(w, h, GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::App::App(   unsigned int w, unsigned int h, 
                unsigned int rows, unsigned int columns
            ) : App(w, h, rows, columns, w/columns, h/rows) {}

CA::App::App(   unsigned int w, unsigned int h, 
                unsigned int rows, unsigned int columns, 
                unsigned int cw, unsigned int ch
            ) : width(w), height(h), title("CellularAutomata"),
                window(sf::VideoMode(width, height, 32), title),
                grid(rows, columns, cw, ch),
                running(true) {
    window.setFramerateLimit(60);
    grid.setCellState(0, 4, CA::State::ON);
}

CA::App::~App() {
    window.close();
}

bool CA::App::isRunning() const {
    return running;
}

void CA::App::reset() {

}

void CA::App::handleEvents() {
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                running = false;
            break;
            case sf::Event::KeyPressed:
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        running = false;
                    break;
                    default:
                    break;
                }
            }
            break;
            default:
            break;
        }    
    }
}

void CA::App::update() {
    window.clear(sf::Color::Black);
    for(int i = 0; i < grid.getRows(); i++) {
        for(int j = 0; j < grid.getColumns(); j++) {
            window.draw(grid.getCell(i, j));
        }
    }
}

void CA::App::display() {
    window.display();
}