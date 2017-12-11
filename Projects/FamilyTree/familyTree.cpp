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
        father[counter] = nameSearch(fatherName);
        mother[counter] = nameSearch(fatherName);
        nameSearchAdd(fatherName);
        father[counter] = nameSearch(motherName);
        mother[counter] = nameSearch(motherName);
        nameSearchAdd(motherName);
        for (int m = 1; m <= numChildren; m++) {
            cin >> childName;
            nameSearchAdd(childName);
            father[nameSearch(childName)] = nameSearch(fatherName);
            mother[nameSearch(childName)] = nameSearch(motherName);
        }

    }

}

void familyTree::queryLoop() {

}

void familyTree::performQuery() {

}

void familyTree::determineRelationship(string p, string q) {

}


int familyTree::nameSearch(string name) {
    for (int i = 0; i < 500; i++) {
        if(name == names[i]) {
            return i;
        }
    }
    return -1;
}

int familyTree::nameSearchAdd(string name) {
    int nameIndex = nameSearch(name);
    if (nameIndex == -1) { //not in list then add
        names[counter] = name;
        counter++;
    }
    else
        return nameIndex;


}