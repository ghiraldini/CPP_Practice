#include <iostream>
#include "BST.h"

int main()
{
    /*        12
          9       15
        3  11  14    18
    */
    BST *myTree = new BST;

    myTree->add_leaf(12);
    myTree->add_leaf(15);
    myTree->add_leaf(9);
    myTree->add_leaf(11);
    myTree->add_leaf(3);
    myTree->add_leaf(18);
    myTree->add_leaf(14);

    myTree->print();

    return 0;
}
