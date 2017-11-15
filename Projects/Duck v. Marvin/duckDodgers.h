//
// Created by Kevin on 11/7/2017.
//

#ifndef DUCK_V_MARVIN_DUCKDODGERS_H
#define DUCK_V_MARVIN_DUCKDODGERS_H

#include <iostream>
#include "queue.h"
#include "list.h"

class duckDodgers {
public:
    void getInput(); //gets values of Marvin and Duck location and creates Lava Cell info
    void genMap(); //sets locations of lava and assigns known values
    void lookAtNeighbors(Coordinate cell);  //adds cells to a queue for checking
    void fillMap(Coordinate startCell); //runs BreadthFirstSearch
    void assignValue(Coordinate cell, int value); //parses a queue and sets values. Once empty exit function
    void createPaths(Coordinate cell); //generates a list of the path to goal
    void placeGandalf(); //takes marvin path and runs genPath for each cell in the path
    void outputResults(); //Returns all necessary info

private:
    int map[20][20];
    Coordinate startDuck,
               startMarvin,
               startPhos;

    int numLava;
    Queue<Coordinate> lavaCells;
    Queue<Coordinate> neighborCells;
    Queue<Coordinate> searchPath,
                      pathDuck,
                      pathMarvin;
};

struct Coordinate {
    int row, column;
    Coordinate(int row, int column) : row(row), column(column) {}
    bool operator==(const Coordinate& other) const {
        return other.row == row && other.column == column;
    }

    bool operator!=(const Coordinate& other) const {
        return !(*this == other);
    }
};

#endif //DUCK_V_MARVIN_DUCKDODGERS_H
