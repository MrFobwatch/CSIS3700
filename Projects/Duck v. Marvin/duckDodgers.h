//
// Created by Kevin on 11/7/2017.
//

#ifndef DUCK_V_MARVIN_DUCKDODGERS_H
#define DUCK_V_MARVIN_DUCKDODGERS_H

#include "queue.h"
#include "list.h"

class duckDodgers {
public:
    void getInput();
    void genMap();
    void genPaths();
    void lookAtNeighbors();
    void assignValue();
    void placeGandalf();
    void outputResults();

private:
    int map[20][20];

};


#endif //DUCK_V_MARVIN_DUCKDODGERS_H
