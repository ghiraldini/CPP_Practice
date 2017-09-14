#include "BST.h"
#include <string>
#include <iostream>
#include <iomanip>

BST::BST(){
    root = NULL;
}

void BST::add_leaf(int newData){
    // Empty Tree
    // First Node == Root
    if( root == NULL ) {
        std::cout << "1st element, " << newData << " is now root of tree" << std::endl;
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->data = newData;

    // Find correct branch for leaf
    } else {
        insert(newData, root);
    }
}

void BST::insert(int data, Node *temp){
    bool left=false;
    std::cout << "Adding: " << data << " to tree" << std::endl;
    while( temp != NULL ){
        if ( compare(temp, data) == -1 ){
            if(temp->left != NULL){
                temp = temp->left;
            }else{
                left=true;
                break;
            }
        } else {
            if(temp->right != NULL){
                temp = temp->right;
            }else{
                break;
            }
        }
    }
    Node *n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    if(left){
        std::cout << "Adding to left of " << temp->data << std::endl;
        temp->left = n;
    }else{
        std::cout << "Adding to right of " << temp->data << std::endl;
        temp->right = n;
    }
}

int BST::compare(Node *t, int data){
    std::cout << "-----Comparing " << t->data << " and " << data << std::endl;
    if( data < t->data )
        return -1;
    else
        return 1;
}

void BST::print(){
    Node *r = root;
    std::cout << " " << std::endl;
    std::cout << "\t\t\t" << r->data << std::endl;
    print(r,3);
}

void BST::print(Node *r, int numTabs){
    if(r->left != NULL){
        for(int i=1; i<numTabs; i++)
            std::cout << "\t";
        std::cout << r->left->data;
    }
    if(r->right != NULL){
        std::cout << "\t\t" << r->right->data << std::endl;
    }

    if(r->left != NULL && r->right != NULL){
        print(r->left,2);
        print(r->right,2);
    }
}

BST::~BST()
{
    //dtor
}
