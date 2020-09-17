#include <Configuration.hpp>

CA::Configuration::Configuration(
                                    unsigned int w, unsigned int h,
                                    std::size_t r, std::size_t c,
                                    float cw, float ch
                            ) : width(w), height(h), rows(r), columns(c),
                                cellWidth(cw), cellHeight(ch) {}

unsigned int CA::Configuration::getWidth() const {
    return width;
}

unsigned int CA::Configuration::getHeight() const {
    return height;
}

std::size_t CA::Configuration::getRows() const {
    return rows;
}

std::size_t CA::Configuration::getColumns() const {
    return columns;
}

float CA::Configuration::getCellWidth() const {
    return cellWidth;
}

float CA::Configuration::getCellHeight() const {
    return cellHeight;
}

void CA::Configuration::setWidth(unsigned int w) {
    width = w;
}

void CA::Configuration::setHeight(unsigned int h) {
    height = h;
}

void CA::Configuration::setRows(std::size_t r) {
    rows = r;
}

void CA::Configuration::setColumns(std::size_t c) {
    columns = c;
}

void CA::Configuration::setCellWidth(float cw) {
    cellWidth = cw;
}

void CA::Configuration::setCellHeight(float ch) {
    cellHeight = ch;
}

void CA::Configuration::set(
                            unsigned int w, unsigned int h,
                            std::size_t r, std::size_t c,
                            float cw, float ch
                        ) {
    width = w;
    height = h;
    rows = r;
    columns = c;
    cellWidth = cw;
    cellHeight = ch;
}