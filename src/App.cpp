#include <App.hpp>
#include <Common.hpp>
#include <iostream>

CA::App::App() :    width(1000), height(100), title("CellularAutomata"),
                    window(sf::VideoMode(width, height), title), 
                    grid(width/cellWidth, height/cellHeight), 
                    running(true) {
    rectCells = new sf::RectangleShape*[height/cellHeight];
    for(int i = 0; i < height/cellHeight; i++) {
        rectCells[i] = new sf::RectangleShape[width/cellWidth];
        for(int j = 0; j < width/cellWidth; j++) {
            rectCells[i][j].setSize(sf::Vector2f(cellWidth, cellHeight));
            rectCells[i][j].setPosition(j * cellWidth, i * cellHeight);
        }
    }
    grid.setCellState(0, 3, true);
    window.setFramerateLimit(60);
}

CA::App::App(int w, int h) :
                    width(w), height(h), title("CellularAutomata"),
                    window(sf::VideoMode(width, height), title),
                    grid(width/cellWidth, height/cellHeight),
                    running(true) {
    rectCells = new sf::RectangleShape*[height/cellHeight];
    for(int i = 0; i < height/cellHeight; i++) {
        rectCells[i] = new sf::RectangleShape[width/cellWidth];
        for(int j = 0; j < width/cellWidth; j++) {
            rectCells[i][j].setSize(sf::Vector2f(cellWidth, cellHeight));
            rectCells[i][j].setPosition(j * cellWidth, i * cellHeight);
        }
    }
    window.setFramerateLimit(60);
}

CA::App::~App() {
    for(int i = 0; i < height/cellHeight; i++) {
        delete[] rectCells[i];
        rectCells[i] = nullptr;
    }
    delete[] rectCells;
    rectCells = nullptr;
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
    window.clear();
    for(int i = 0; i < grid.getHeight(); i++) {
        for(int j = 0; j < grid.getWidth(); j++) {
                std::cout << "cell(" << rectCells[i][j].getPosition().x << "," << rectCells[i][j].getPosition().y << ") state = " << (grid.getCell(i, j).getState()) << std::endl;
                rectCells[i][j].setFillColor((grid.getCell(i, j).getState()) ? sf::Color::White : sf::Color::Black);
                window.draw(rectCells[i][j]);
        }
    }
}

void CA::App::display() {
    window.display();
}