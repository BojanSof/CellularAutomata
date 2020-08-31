#include <App.hpp>

int main(int argc, char **argv) {
    CA::App app(1000, 500, 50, 99, 10, 10);
    app.run();
    return 0;
}