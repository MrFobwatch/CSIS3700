//
// Created by Kevin on 11/7/2017.
//

#ifndef DUCK_V_MARVIN_DUCKDODGERS_H
#define DUCK_V_MARVIN_DUCKDODGERS_H

#include <iostream>
#include <string>
#include "queue.h"
#include "list.h"

struct Coordinate {
    int row, column;
    Coordinate(int row, int column) : row(row), column(column) {}
    Coordinate() {row = 0; column = 0;}

    bool operator==(const Coordinate& other) const {
        return other.row == row && other.column == column;
    }

    bool operator!=(const Coordinate& other) const {
        return !(*this == other);
    }
};

class duckDodgers {
public:
    void getInput(); //gets values of Marvin and Duck location and creates Lava Cell info
    void genMap(); //sets locations of lava and assigns known values
    void enqueueNeighborsCells(Coordinate cell, bool assignVal);  //adds neighboring cells to the queue and conditionally marks as visited
    void fillMap(Coordinate startCell); //runs BreadthFirstSearch
    void assignValue(Coordinate cell, int value); //simply applies a value to a given cell if it has no value
    void fillPath(Coordinate cell, LinearList<Coordinate>& path); //generates a list of the path from given cell to goal
    void placeGandalf(); //takes marvin path and runs fill map for each cell in the path with gandalf in it
    void outputResults(); //Returns all necessary info

    int map[20][20];
    Coordinate
            startDuck,
            startMarvin,
            startPhos;
    LinearList<Coordinate>
            pathDuck,
            pathMarvin;
private:
    int numLava;
    Queue<Coordinate>
            lavaCells,
            queue;
};

#endif //DUCK_V_MARVIN_DUCKDODGERS_H
