//
// Created by Kevin on 12/8/2017.
//

#ifndef FAMILYTREE_FAMILYTREE_H
#define FAMILYTREE_FAMILYTREE_H

#include <iostream>
#include

class familyTree {
    public:
        void getInput();

    private:
        string names[500];  //Array that stores the names of everyone in the tree
        int father[500];    //Array that stores the indices of fathers
        int mother[500];    //Array that stores the indices of mothers

};


#endif //FAMILYTREE_FAMILYTREE_H
