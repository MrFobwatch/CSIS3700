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

void duckDodgers::lookAtNeighbors(Coordinate cell) { //Does not respect edges of map
    //conditionals only enqueue if the cell value is -1
    if (map[cell.row - 1][cell.column] == -1) {
        neighborCells.enqueue(Coordinate((cell.row - 1), (cell.column))); //north
    }
    if (cell.column % 2) { //Odd columns have north east and north west
        if (map[cell.row - 1][cell.column + 1] == -1) {
            neighborCells.enqueue(Coordinate((cell.row - 1), ((cell.column) + 1))); //north east
        }
        if (map[cell.row - 1][cell.column -1] == -1) {
            neighborCells.enqueue(Coordinate((cell.row - 1), ((cell.column) - 1))); //north west
        }
    }
    else {
        if (map[cell.row + 1][cell.column + 1] == -1) {
            neighborCells.enqueue(Coordinate((cell.row + 1), ((cell.column) + 1))); //south east
        }
        if (map[cell.row + 1][cell.column - 1] == -1) {
            neighborCells.enqueue(Coordinate((cell.row + 1), ((cell.column) - 1))); //south west
        }
    }
    if (map[cell.row][cell.column + 1] == -1) {
        neighborCells.enqueue(Coordinate((cell.row), ((cell.column)+1))); //east
    }
    if (map[cell.row][cell.column - 1] == -1) {
        neighborCells.enqueue(Coordinate((cell.row), ((cell.column)-1))); //west
    }
    if (map[cell.row + 1][cell.column] == -1) {
        neighborCells.enqueue(Coordinate((cell.row+1), ((cell.column)))); //south
    }
}

void duckDodgers::fillMap(Coordinate startCell) { //Fills in the map starting from initial cell
    //Coordinate currentCell = startCell;
    int cellValue = 1;
    searchPath.enqueue(startCell);
    assignValue(startCell, 0);
    lookAtNeighbors(startCell);
    while (!searchPath.isEmpty()) {
        Coordinate currentCell = searchPath.dequeue();
        int currentCellValue = map[currentCell.row][currentCell.column];

        for (int i = 0; i < neighborCells.size(); ++i) {
            Coordinate neighborCell = neighborCells.dequeue();
            int neighborCellValue = map[neighborCell.row][neighborCell.column];
            if ((neighborCellValue == -1)) {
                assignValue(neighborCell, cellValue); //marks as visited by assign values to neighboring cells. assignValue checks for preexisting value
                searchPath.enqueue(neighborCell);

            }
            neighborCellValue = map[neighborCell.row][neighborCell.column];

            if (((neighborCellValue) == (currentCellValue+1))) { //add neighbor to queue if it is 1 farther from current cell
                searchPath.enqueue(neighborCell);
            }
        }
        cellValue++;
    }

}

void duckDodgers::createPaths(Coordinate cell) {

}

void duckDodgers::assignValue(Coordinate cell, int value) {
    map[cell.row][cell.column] = value;
}

void duckDodgers::placeGandalf() {

}

void duckDodgers::outputResults() {

}
