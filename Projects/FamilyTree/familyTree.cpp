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
    for (int j = 0; j < 500; ++j) {
        familyInfo[j][0] = 0;
        familyInfo[j][1] = 0;
    }
    queue.clear();
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
    for (int i = 0; i < queryCount; i++) {
        performQuery();
    }

}

void familyTree::performQuery() {
    string personA, personB;
    cin >> personA >> personB;
    determineDescendance(personA, personB);
}

void familyTree::determineDescendance(string p, string q) { //Incorrect Code
//    int index = 0;
//    queue.enqueue(index);
//    string qfather = names[father[nameSearch(q)]];
//    string qmother = names[mother[nameSearch(q)]];
//    string pfather = names[father[nameSearch(p)]];
//    string pmother = names[mother[nameSearch(p)]];
    if(nameSearch(p) >= 0 && nameSearch(q) >= 0) {
        cout << "Related" << std::endl;
    }
    else if (nameSearch(p) == -1 || nameSearch(q) == -1){
        cout << "No relation" << std::endl;
    }


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