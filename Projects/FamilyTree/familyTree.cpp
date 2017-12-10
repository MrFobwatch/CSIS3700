//
// Created by Kevin on 12/8/2017.
//

#include "familyTree.h"
using std::cin;
using std::cout;

familyTree::familyTree() {
    counter = 0;
    for (int i = 0; i < 500; i++) {
        mother[i] = 0;
        father[i] = 0;
    }
}

void familyTree::getInput() {
    int numOfFamilies;  //f
    int numOfQueries;   //q
    cin >> numOfFamilies >> numOfQueries;
    queryCount = numOfQueries;
    for (int f = 0; f < numOfFamilies; f++) {
        int numChildren;
        string fatherName, motherName, childName;
        cin >> numChildren; //m
        cin >> fatherName >> motherName;
        nameSearchAdd(fatherName);
        father[counter] = nameSearchAdd(fatherName);
        mother[counter] = nameSearchAdd(fatherName);
        nameSearchAdd(motherName);
        father[counter] = nameSearchAdd(motherName);
        mother[counter] = nameSearchAdd(motherName);
        for (int m = 1; m <= numChildren; m++) {
            cin >> childName;
            father[counter] = nameSearchAdd(fatherName);
            mother[counter] = nameSearchAdd(motherName);
        }

    }

}

void familyTree::queryLoop() {

}

void familyTree::performQuery() {

}

void familyTree::determineRelationship(string p, string q) {

}

int familyTree::nameSearchAdd(string name) {
    bool found = false;
    for (int i = 0; i < 500; i++) {
        if(name == names[i]) {
            found = true;
            return i;
        }
    }
    if (!found) {
        names[counter] = name;
        counter++;
        return -1;
    }

}

