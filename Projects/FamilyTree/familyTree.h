//
// Created by Kevin on 12/8/2017.
//

#ifndef FAMILYTREE_FAMILYTREE_H
#define FAMILYTREE_FAMILYTREE_H

#include <iostream>
#include <string>
#include "queue.h"

using std::string;

class familyTree {
    public:
    familyTree();

    void getInput();
    void queryLoop();
    void performQuery();
    void determineDescendance(string p, string q);
    int nameSearch(string name);
    int nameSearchAdd(string name);   //returns the index of the individual with this name

    string names[500];  //Array that stores the names of everyone in the tree
    int father[500];    //Array that stores the indices of fathers in names
    int mother[500];    //Array that stores the indices of mothers in names
    int familyInfo[500][2]; //[Descendant][Ancestor]
    Queue<int> queue;
    int counter;
    int queryCount;

};


#endif //FAMILYTREE_FAMILYTREE_H
