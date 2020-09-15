#include <App.hpp>
#include <Common.hpp>
#include <iostream>

CA::App::App() : App(APP_WIDTH, APP_HEIGHT) {}

CA::App::App(unsigned int w, unsigned int h) : 
            App(w, h, GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::App::App(   unsigned int w, unsigned int h, 
                std::size_t r, std::size_t c
            ) : App(w, h, rows, columns, w/columns, h/rows) {}

CA::App::App(   unsigned int w, unsigned int h, 
                std::size_t r, std::size_t c, 
                float cw, float ch
            ) : width(w), height(h), rows(r), columns(c),
                cellWidth(cw), cellHeight(ch),                
                title("Cellular Automata"),
                running(false) {
    std::cout << "Welcome to Cellular Automation collection!!!\n";
    std::cout << "Please choose one of the following cellular automaton(CA):\n";
    //window.setFramerateLimit(60);
}

CA::App::~App() {
    window.close();
}

int CA::App::menu() {
    std::cout << "1. Elementary CA\n";
    std::cout << "2. Options\n";
    std::cout << "3. Exit\n";
    std::cout << "Your choice: " << std::flush;
    int input;
    std::cin >> input;
    if(input < 1 && input > 3) {
        std::cout << "Incorrect option. Please choose a valid entry" << std::endl;
        return -1;
    } else return input;
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
                    case sf::Keyboard::R:
                        ca->reset();
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

void CA::App::update(/*sf::Time elapsed*/) {
    window.clear(sf::Color::Black);
    for(unsigned int r = 0; r < ca->getGrid().getRows(); r++) {
        for(unsigned int c = 0; c < ca->getGrid().getColumns(); c++) {
            window.draw(ca->getGrid().getCell(r, c));
        }
    }
    ca->update();
}

void CA::App::display() {
    window.display();
}

void CA::App::run() {
    int choice;
    do {
        choice = menu();
    } while(choice == -1);
    switch(choice) {
        case 1: //Elementary CA
            ca = std::make_shared<CA::Elementary>(CA::Elementary(rows, columns, cellWidth, cellHeight, CA::ElementaryRule(99)));
            running = true;
        break;
        case 2: //options (empty for now)
            return;
        break;
        case 3:
            return;
        break;
    }
    //sf::Clock clock;
    //sf::Time timeSinceLastUpdate = sf::Time::Zero;
    //sf::Time timePerFrame = sf::seconds(1 / CA::FPS);
    ca->reset();
    window.create(sf::VideoMode(width, height, 32), title);
    while(isRunning()) {
        //timeSinceLastUpdate += clock.restart();
        //while(timeSinceLastUpdate > timePerFrame) {
        //    timeSinceLastUpdate -= timePerFrame;
        handleEvents();
        update(/*timePerFrame*/);
        //}
        display();
    }
}