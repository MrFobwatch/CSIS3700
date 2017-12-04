//
// Created by Kevin on 11/14/2017.
//

#include "duckDodgers.h"
using namespace std;

void output2dArray(int array[][20], int limit){
    for(int i=0; i<limit; i++) {
        for(int j=0; j<limit; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    duckDodgers duckDodgers;
    duckDodgers.getInput();
    duckDodgers.genMap();
    duckDodgers.fillMap(duckDodgers.startPhos);
    output2dArray(duckDodgers.map, 20);
    duckDodgers.fillPath(duckDodgers.startMarvin, duckDodgers.pathMarvin);
    duckDodgers.fillPath(duckDodgers.startDuck, duckDodgers.pathDuck);
    duckDodgers.outputResults();
    int val;
    cin >> val;
    return 0;
}