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
                elementaryCA(rows, columns, cw, ch, CA::Rule(99)),
                running(true), drawing(true) {
    //window.setFramerateLimit(60);
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

void CA::App::update(sf::Time elapsed) {
    //for(unsigned int r = 0; r < elementaryCA.getGrid().getRows(); r++)
    //    elementaryCA.getGrid().drawRow(&window, r);
    window.clear(sf::Color::Black);
    unsigned int currentRow = elementaryCA.getNextRow() - 1;
    for(unsigned int r = 0; r < elementaryCA.getGrid().getRows(); r++) {
        for(unsigned int c = 0; c < elementaryCA.getGrid().getColumns(); c++) {
            window.draw(elementaryCA.getGrid().getCell(r, c));
        }
    }
    drawing = elementaryCA.update();
}

void CA::App::display() {
    window.display();
}

void CA::App::run() {

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1 / CA::FPS);
    while(isRunning()) {
        //timeSinceLastUpdate += clock.restart();
        //while(timeSinceLastUpdate > timePerFrame) {
        //    timeSinceLastUpdate -= timePerFrame;
            handleEvents();
            update(timePerFrame);
        //}
        display();
    }
}