#include <App.hpp>

int main(int argc, char **argv) {
    CA::App app;
    while(app.isRunning()) {
        app.handleEvents();
        app.update();
        app.display();
    }
    return 0;
}