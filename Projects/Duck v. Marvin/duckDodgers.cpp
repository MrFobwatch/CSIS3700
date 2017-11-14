//
// Created by Kevin on 11/7/2017.
//

#include "duckDodgers.h"

void duckDodgers::getInput() {
    std::cin >> startDuck.row >> startDuck.column;
    std::cin >> startMarvin.row >> startMarvin.column;
    std::cin >> startPhos.row >> startPhos.column;
    std::cin >> numLava;
    for (int i = 0; i < numLava; ++i) {
        int row, column;
        std::cin >> row >> column;
        lavaCells.enqueue(Coordinate(row,column));
    }
}

void duckDodgers::genMap() {
    for (int row = 0; row < 20; ++row) { //Set the entire blank map to -1
        for (int col = 0; col < 20; ++col) {
            map[row][col] = -1;
        }
    }
    for (int i = 0; i < lavaCells.size(); ++i) { //Set the values of each lava cell to -2
        Coordinate lavaLocation = lavaCells.dequeue();
        map[lavaLocation.row][lavaLocation.column] = -2;
    }

    map[startDuck.row][startDuck.column] = 0;

    map[startMarvin.row][startMarvin.column] = 0;

    map[startPhos.row][startPhos.column] = 0;
}

void duckDodgers::lookAtNeighbors(Coordinate cell) {
    neighborCells.enqueue(Coordinate(((cell.column)), (cell.row - 1))); //north
    if (cell.column % 2) { //Odd columns have north east and north west
        neighborCells.enqueue(Coordinate(((cell.column) + 1), (cell.row - 1))); //north east
        neighborCells.enqueue(Coordinate(((cell.column) - 1), (cell.row - 1))); //north west
    }
    else {
        neighborCells.enqueue(Coordinate(((cell.column) + 1), (cell.row + 1))); //south east
        neighborCells.enqueue(Coordinate(((cell.column) - 1), (cell.row + 1))); //south west
    }
    neighborCells.enqueue(Coordinate(((cell.column)+1), (cell.row))); //east
    neighborCells.enqueue(Coordinate(((cell.column)-1), (cell.row))); //west
    neighborCells.enqueue(Coordinate(((cell.column)), (cell.row+1))); //south
}

void duckDodgers::genPaths() {

}

void duckDodgers::assignValue() {

}

void duckDodgers::placeGandalf() {

}

void duckDodgers::outputResults() {

}
