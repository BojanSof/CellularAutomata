#include <App.hpp>

int main(int argc, char **argv) {
    CA::App app(1000, 200, 1, 10, 100, 100);
    while(app.isRunning()) {
        app.handleEvents();
        app.update();
        app.display();
    }
    return 0;
}