# Cellular Automata Collection

Collection of cellular automata simulations.
![Elementary cellular automaton with rule 90](https://github.com/BojanSof/CellularAutomata/blob/main/images/elementary.gif) | ![Langton's ant](https://github.com/BojanSof/CellularAutomata/blob/main/images/langton.gif)
:-------------------------:|:-------------------------:
![Conway's Game of Life](https://github.com/BojanSof/CellularAutomata/blob/main/images/conway.gif) | ![Brian's Brain](https://github.com/BojanSof/CellularAutomata/blob/main/images/brian.gif)


# Getting Started

The interface allows to implement other cellular automata, based on square grid easily.
To implement new cellular automata, inherit from the abstract class ```CA::CellularAutomaton```
and override the ```update()``` and ```reset()``` function accordingly.
Also, to get the new state of the cell, based on its neighbors, you can inherit from
the ```CA::Rule``` class and override the methods ```getNewState()```.
As an example, refer to the header and source files for any of the implemented automata,
listed below.

List of implemented cellular automata:
- [Elementary](https://en.wikipedia.org/wiki/Elementary_cellular_automaton)
- [Langton's ant](https://en.wikipedia.org/wiki/Langton%27s_ant)
- [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
- [Brian's Brain](https://en.wikipedia.org/wiki/Brian%27s_Brain)

## Prerequisites

- SFML 2.5.1

## Building

Clone the repository
```
git clone
```
Run make command
```
make
```

# Running the program

Run the binary ```app``` inside ```bin```.