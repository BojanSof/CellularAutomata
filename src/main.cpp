#include <App.hpp>

int main(int argc, char **argv) {
    unsigned int width = 600;
    unsigned int height = 600;
    float cw = 5;
    float ch = 5;
    std::size_t rows = width / cw;
    std::size_t columns = height / ch;
    CA::App app(width, height, rows, columns, cw, ch);
    app.run();
    return 0;
}