//
// Created by Kevin on 11/7/2017.
//

#include "duckDodgers.h"

void duckDodgers::getInput() {
    std::cin >> startDuck.row >> startDuck.column;
    std::cin >> startMarvin.row >> startMarvin.column;
    std::cin >> startPhos.row >> startPhos.column;
    std::cin >> numLava;
    for (int i = 0; i <= numLava - 1; ++i) {
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
    int lavaCellsCount = lavaCells.size();
    for (int i = 0; i < lavaCellsCount; ++i) { //Set the values of each lava cell to -2
        Coordinate lavaLocation = lavaCells.dequeue();
        map[lavaLocation.row][lavaLocation.column] = -2;
    }

    map[startDuck.row][startDuck.column] = 0;

    map[startMarvin.row][startMarvin.column] = 0;

    map[startPhos.row][startPhos.column] = 0;
}

void duckDodgers::enqueueNeighborsCells(Coordinate cell) {
    //conditionals only enqueue if the cell value is -1
    //also assigns values of enqueued cells

    if (map[cell.row - 1][cell.column] == -1) {
        queue.enqueue(Coordinate((cell.row - 1), (cell.column))); //north
        assignValue(Coordinate((cell.row - 1), (cell.column)), map[cell.row][cell.column] + 1);
    }
    if ((cell.column == 1) || (cell.column % 2 == 0)) { //Odd columns have north east and north west
        if (map[cell.row - 1][cell.column + 1] == -1) {
            queue.enqueue(Coordinate((cell.row - 1), ((cell.column) + 1))); //north east
            assignValue(Coordinate((cell.row - 1), ((cell.column) + 1)), map[cell.row][cell.column] + 1);
        }
        if (map[cell.row - 1][cell.column - 1] == -1) {
            queue.enqueue(Coordinate((cell.row - 1), ((cell.column) - 1))); //north west
            assignValue(Coordinate((cell.row - 1), ((cell.column) - 1)), map[cell.row][cell.column] + 1);
        }
    }
    else {
        if (map[cell.row + 1][cell.column + 1] == -1) {
            queue.enqueue(Coordinate((cell.row + 1), ((cell.column) + 1))); //south east
            assignValue(Coordinate((cell.row + 1), ((cell.column) + 1)), map[cell.row][cell.column] + 1);
        }
        if (map[cell.row + 1][cell.column - 1] == -1) {
            queue.enqueue(Coordinate((cell.row + 1), ((cell.column) - 1))); //south west
            assignValue(Coordinate((cell.row + 1), ((cell.column) - 1)), map[cell.row][cell.column] + 1);
        }
    }
    if (map[cell.row][cell.column + 1] == -1) {
        queue.enqueue(Coordinate((cell.row), ((cell.column) + 1))); //east
        assignValue(Coordinate((cell.row), ((cell.column) + 1)), map[cell.row][cell.column] + 1);
    }
    if (map[cell.row][cell.column - 1] == -1) {
        queue.enqueue(Coordinate((cell.row), ((cell.column) - 1))); //west
        assignValue(Coordinate((cell.row), ((cell.column) - 1)), map[cell.row][cell.column] + 1);
    }
    if (map[cell.row + 1][cell.column] == -1) {
        queue.enqueue(Coordinate((cell.row + 1), ((cell.column)))); //south
        assignValue(Coordinate((cell.row + 1), ((cell.column))), map[cell.row][cell.column] + 1);
    }
}

void duckDodgers::fillMap(Coordinate startCell) { //Fills in the map starting from initial cell
    //Coordinate currentCell = startCell;
    int cellValue = 1;
    queue.enqueue(startCell);
    assignValue(startCell, 0);
            if ((neighborCellValue == -1)) {
            }
    enqueueNeighborsCells(startCell);
    while (!queue.isEmpty()) {
        Coordinate currentCell = queue.dequeue();
//        int currentCellValue = map[currentCell.row][currentCell.column];

        for (int i = 0; i < queue.size(); ++i) {
            Coordinate nextCell = queue.dequeue();
            int nextCellValue = map[nextCell.row][nextCell.column];
                assignValue(nextCell, cellValue); //marks as visited by assign values to neighboring cells. assignValue checks for preexisting value
                queue.enqueue(nextCell);
                enqueueNeighborsCells(nextCell);
        }
        cellValue++;
    }

}

void duckDodgers::createPaths(Coordinate cell) {

}

void duckDodgers::assignValue(Coordinate cell, int value) {
    if (map[cell.row][cell.column] == -1) {
        map[cell.row][cell.column] = value;
    }
}

void duckDodgers::placeGandalf() {

}

void duckDodgers::outputResults() {

}
