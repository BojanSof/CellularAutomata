#include <App.hpp>

int main(int argc, char **argv) {
    CA::App app(1200, 700, 700/5, 1200/5, 5, 5);
    app.run();
    return 0;
}