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
        lavaList.insert(i, Coordinate(row,column));
    }
}

void duckDodgers::genMap() {

}

void duckDodgers::genPaths() {

}

void duckDodgers::lookAtNeighbors() {

}

void duckDodgers::assignValue() {

}

void duckDodgers::placeGandalf() {

}

void duckDodgers::outputResults() {

}
