#include <App.hpp>
#include <Common.hpp>
#include <iostream>
#include <iomanip>

CA::App::App() : App(APP_WIDTH, APP_HEIGHT) {}

CA::App::App(unsigned int w, unsigned int h) : 
            App(w, h, GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::App::App(   unsigned int w, unsigned int h, 
                std::size_t r, std::size_t c
            ) : App(w, h, r, c, w/c, h/r) {}

CA::App::App(   unsigned int w, unsigned int h, 
                std::size_t r, std::size_t c, 
                float cw, float ch
            ) : config(w, h, r, c, cw, ch)
                /*width(w), height(h), rows(r), columns(c),
                cellWidth(cw), cellHeight(ch)*/,                
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
    std::cout << "2. Conway's Game of Life\n";
    std::cout << "3. Langton's Ant\n";
    std::cout << "4. Brians's Brain\n";
    std::cout << "5. Options\n";
    std::cout << "6. Exit\n";
    std::cout << "Your choice: " << std::flush;
    int input;
    std::cin >> input;
    if(input < 1 && input > 6) {
        std::cout << "Incorrect option. Please choose a valid entry" << std::endl;
        return -1;
    } else return input;
}

int CA::App::options() {
    std::cout << std::setw(4) << std::fixed << std::setprecision(1);
    std::cout << "1. Change App Width               (current width:       " << config.getWidth() << ")\n";
    std::cout << "2. Change App Height              (current height:      " << config.getHeight() << ")\n";
    std::cout << "3. Change number of grid's rows   (current rows:        " << config.getRows() << ")\n";
    std::cout << "4. Change number of grid's columns(current columns:     " << config.getColumns() << ")\n";
    std::cout << "5. Change cell width              (current cell width:  " << config.getCellWidth() << ")\n";
    std::cout << "6. Change cell height             (current cell height: " << config.getCellHeight() << ")\n";
    std::cout << "7. Back\n";
    std::cout << "Your choice: " << std::flush;
    int input;
    std::cin >> input;
    if(input < 1 && input > 7) {
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
        if(choice == CA::App::OPTIONS_MENU_ENTRY) {
            int optionsChoice;
            do {
                do {
                    optionsChoice = options();
                } while(optionsChoice == -1);
                switch(optionsChoice) {
                case 1: {
                    unsigned int w;
                    std::cout << "Enter the new width: ";
                    std::cin >> w;
                    config.setWidth(w);
                } break;
                case 2: {
                    unsigned int h;
                    std::cout << "Enter the new height: ";
                    std::cin >> h;
                    config.setHeight(h);
                } break;
                case 3: {
                    std::size_t r;
                    std::cout << "Enter the new number of rows: ";
                    std::cin >> r;
                    config.setRows(r);
                } break;
                case 4: {
                    std::size_t c;
                    std::cout << "Enter the new number of columns: ";
                    std::cin >> c;
                    config.setColumns(c);
                } break;
                case 5: {
                    float cw;
                    std::cout << "Enter the new cells' width: ";
                    std::cin >> cw;
                    config.setCellWidth(cw);
                } break;
                case 6: {
                    float ch;
                    std::cout << "Enter the new cells' height: ";
                    std::cin >> ch;
                    config.setCellHeight(ch);
                } break;
                case 7:
                    optionsChoice = -1;
                break;
                default:
                break;
            }
            } while(optionsChoice != -1);
        }
    } while(choice == -1 || choice == OPTIONS_MENU_ENTRY);
    switch(choice) {
        case CA::App::ELEMENTARY_MENU_ENTRY: { //Elementary CA
            int numberRule, c;
            std::cout << "Enter the number representing the rule: ";
            std::cin >> numberRule;
            std::cout << "Enter the first row initial states configuration: ";
            std::cin >> c;
            ca = std::make_shared<CA::Elementary>(CA::Elementary(config.getRows(), config.getColumns(), config.getCellWidth(), config.getCellHeight(), CA::ElementaryRule(numberRule), c));
            running = true;
        } break;
        case CA::App::GAME_OF_LIFE_MENU_ENTRY: { //Conway's Game of Life
            ca = std::make_shared<CA::GameOfLife>(CA::GameOfLife(config.getRows(), config.getColumns(), config.getCellWidth(), config.getCellHeight()));
            running = true;
        } break;
        case CA::App::LANGTONS_ANT_MENU_ENTRY: { //Langton's Ant
            ca = std::make_shared<CA::LangtonAnt>(CA::LangtonAnt(config.getRows(), config.getColumns(), config.getCellWidth(), config.getCellHeight()));
            running = true;
        } break;
        case CA::App::BRIANS_BRAIN_MENU_ENTRY: { //Conway's Game of Life
            ca = std::make_shared<CA::BriansBrain>(CA::BriansBrain(config.getRows(), config.getColumns(), config.getCellWidth(), config.getCellHeight()));
            running = true;
        } break;
        case CA::App::EXIT_MENU_ENTRY:
            return;
        break;
    }
    //sf::Clock clock;
    //sf::Time timeSinceLastUpdate = sf::Time::Zero;
    //sf::Time timePerFrame = sf::seconds(1 / CA::FPS);
    ca->reset();
    window.create(sf::VideoMode(config.getWidth(), config.getHeight(), 32), title);
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