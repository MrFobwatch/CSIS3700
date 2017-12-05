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

//    map[startDuck.row][startDuck.column] = 0;

//    map[startMarvin.row][startMarvin.column] = 0;

    map[startPhos.row][startPhos.column] = 0;
}

void duckDodgers::enqueueNeighborsCells(Coordinate cell, bool assignVal) {
    //conditionals only enqueue if the cell value is -1
    //also assigns values of enqueued cells
	//assignVal determines if values are assigned

    if (map[cell.row - 1][cell.column] == -1 || !assignVal) {
        queue.enqueue(Coordinate((cell.row - 1), (cell.column))); //north
        if (assignVal)
        	assignValue(Coordinate((cell.row - 1), (cell.column)), map[cell.row][cell.column] + 1);
    }
    if ((cell.column == 1) || (cell.column % 2 == 0)) { //Odd columns have north east and north west
        if (map[cell.row - 1][cell.column + 1] == -1 || !assignVal) {
            queue.enqueue(Coordinate((cell.row - 1), ((cell.column) + 1))); //north east
            if (assignVal)
            	assignValue(Coordinate((cell.row - 1), ((cell.column) + 1)), map[cell.row][cell.column] + 1);
        }
        if (map[cell.row - 1][cell.column - 1] == -1 || !assignVal) {
            queue.enqueue(Coordinate((cell.row - 1), ((cell.column) - 1))); //north west
            if (assignVal)
            	assignValue(Coordinate((cell.row - 1), ((cell.column) - 1)), map[cell.row][cell.column] + 1);
        }
    }
    else {
        if (map[cell.row + 1][cell.column + 1] == -1 || !assignVal) {
            queue.enqueue(Coordinate((cell.row + 1), ((cell.column) + 1))); //south east
            if (assignVal)
            	assignValue(Coordinate((cell.row + 1), ((cell.column) + 1)), map[cell.row][cell.column] + 1);
        }
        if (map[cell.row + 1][cell.column - 1] == -1 || !assignVal) {
            queue.enqueue(Coordinate((cell.row + 1), ((cell.column) - 1))); //south west
            if (assignVal)
            	assignValue(Coordinate((cell.row + 1), ((cell.column) - 1)), map[cell.row][cell.column] + 1);
        }
    }
    if (map[cell.row][cell.column + 1] == -1 || !assignVal) {
        queue.enqueue(Coordinate((cell.row), ((cell.column) + 1))); //east
        if (assignVal)
        	assignValue(Coordinate((cell.row), ((cell.column) + 1)), map[cell.row][cell.column] + 1);
    }
    if (map[cell.row][cell.column - 1] == -1 || !assignVal) {
        queue.enqueue(Coordinate((cell.row), ((cell.column) - 1))); //west
        if (assignVal)
        	assignValue(Coordinate((cell.row), ((cell.column) - 1)), map[cell.row][cell.column] + 1);
    }
    if (map[cell.row + 1][cell.column] == -1 || !assignVal) {
        queue.enqueue(Coordinate((cell.row + 1), ((cell.column)))); //south
        if (assignVal)
        	assignValue(Coordinate((cell.row + 1), ((cell.column))), map[cell.row][cell.column] + 1);
    }
}

void duckDodgers::fillMap(Coordinate startCell) { //Fills in the map starting from initial cell
    //Coordinate currentCell = startCell;
    int cellValue = 1;
    queue.enqueue(startCell);
    assignValue(startCell, 0);
    enqueueNeighborsCells(startCell, true);
    while (!queue.isEmpty()) {
        Coordinate currentCell = queue.dequeue();
//        int currentCellValue = map[currentCell.row][currentCell.column];
        int queueSize = queue.size();
        for (int i = 0; i < queueSize; ++i) {
            Coordinate nextCell = queue.dequeue();
            int nextCellValue = map[nextCell.row][nextCell.column];
//            if ((nextCellValue == -1 || nextCellValue > cellValue)) {
                assignValue(nextCell, cellValue); //marks as visited by assign values to neighboring cells. assignValue checks for preexisting value
                queue.enqueue(nextCell);
                enqueueNeighborsCells(nextCell, true);
//            }
        }
        cellValue++;
    }

}

void duckDodgers::fillPath(Coordinate start, LinearList<Coordinate>& path) {
	path.insert(0, start);
    int index = 1;
	int currentCellValue = map[start.row][start.column];
	//Look at neighbor
	enqueueNeighborsCells(start, false);
	//find one less
	while (!queue.isEmpty()) {
		Coordinate nextCell = queue.dequeue();
		int nextCellValue = map[nextCell.row][nextCell.column];
		if (nextCellValue == (currentCellValue - 1)) {
			//add to list
			path.insert(index, nextCell);
			index++;
            queue.clear();
			currentCellValue = nextCellValue;
			//look at neighbors of newly added cell
			enqueueNeighborsCells(nextCell, false);
		}
		//repeat until newly added cell == 0 (goal)
		if (currentCellValue == 0) {
			queue.clear();
		}

		//if no neighbor is 1 less or (something I can't recall) no path
	}

}

void duckDodgers::assignValue(Coordinate cell, int value) {
    if (cell.row < 20 && cell.column < 20) {
        if (map[cell.row][cell.column] == -1) {
            map[cell.row][cell.column] = value;
        }
    }
}

void duckDodgers::placeGandalf() {
    LinearList<Coordinate> pathMarvinOld = pathMarvin; //Fix assignment to be a deep copy instead of a shallow copy
    for (int i = 0; i < pathMarvinOld.size(); ++i) {
        //Try gandalf in each space on Marvins' Path
        Coordinate gandalfCell = pathMarvinOld[i];
        genMap();
        map[gandalfCell.row][gandalfCell.column] = -2;
        //Recalculate Paths
        fillMap(startPhos);
        pathMarvin.clear();
        fillPath(startMarvin, pathMarvin);
        pathDuck.clear();
        fillPath(startDuck, pathDuck);
        //check to see if Duck wins
        if (pathDuck.size() < pathMarvin.size()) {
            std::cout << "Duck Dodgers summons Gandalf the Grey to cell " << gandalfCell.row << "," << gandalfCell.column;
            std::cout << "Duck Dodgers' new path:" << std::endl;
            for (int i = 0; i < pathDuck.size(); ++i) {
                std::cout << pathDuck[i].row << "," << pathDuck[i].column << " - ";
            }
            std::cout << "Marvin the Martian's new path:" << std::endl;
            for (int i = 0; i < pathMarvin.size(); ++i) {
                std::cout << pathMarvin[i].row << "," << pathMarvin[i].column << " - ";
            }
            break;
        }
        //remove gandalf from current position
        map[gandalfCell.row][gandalfCell.column] = -1;
    }
    std::cout << "Gandalf cannot help" << std::endl;
}

void duckDodgers::outputResults() {
    std::string winner;
    if (pathDuck.size() != pathMarvin.size()) {
        winner = pathDuck.size() > pathMarvin.size() ? "Marvin the Martian" : "Duck Dodgers";
    }
    else {
        winner = "Marvin the Martian";
    }
    std::cout << winner << " reaches the Illudium Phosdex first." << std::endl;
    std::cout << "Duck Dodgers' path:" << std::endl;
    for (int i = 0; i < pathDuck.size(); ++i) {
        std::cout << pathDuck[i].row << "," << pathDuck[i].column << " - ";
    }
    std::cout << std::endl;
    std::cout << "Marvin the Martian's path:" << std::endl;
    for (int i = 0; i < pathMarvin.size(); ++i) {
        std::cout << pathMarvin[i].row << "," << pathMarvin[i].column << " - ";
    }
    //attempt to place Gandalf
    if (winner == "Marvin the Martian") {
        placeGandalf();
    }



}
