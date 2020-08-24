#ifndef CELL_HPP
#define CELL_HPP

namespace CA {

class Cell {
public:
    Cell();
    Cell(bool s);

    bool getState() const;

    void setState(bool s);

private:
    bool state;
};

}

#endif //CELL_HPP