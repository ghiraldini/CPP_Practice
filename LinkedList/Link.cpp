#include "Link.h"
#include <iostream>


Link::Link()
{
    std::cout << "Creating new-empty LL" << std::endl;
}

void Link::add_link_end(std::string newStr){
    std::cout << "Adding new string: " << newStr << std::endl;

    Node *n = new Node;
    n->myStr = newStr;
    n->next = NULL;

    if(!head){
        head = n;
        return;
    } else {
        Node *last = head;
        while(last->next){
            last = last->next;
        }
        last->next = n;
    }
}

void Link::add_link_start(std::string newStr){
    std::cout << "Adding new string: " << newStr << std::endl;
    Node *n = new Node;
    n->myStr = newStr;
    n->next = head;
    head = n;
}

void Link::delete_link(std::string delMe){
    std::cout << "Deleting string: " << delMe << std::endl;
    Node *pre = new Node;
    Node *temp = head;
    while(temp->myStr != delMe){
        pre = temp;
        temp = temp->next;
    }
    pre->next = temp->next;
    delete(temp);
}


void Link::delete_list(){
    Node *cur = head;
    Node *next;

    while(cur != NULL){
        next = cur->next;
        delete(cur);
        cur = next;
    }
    head = NULL;
}


void Link::print_list(){
    Node *temp = new Node;
    temp = head;

    std::cout << "Nodes: ";
    while(temp != NULL){
        std::cout << temp->myStr << ", ";
        temp = temp->next;
    }
    std::cout <<""<< std::endl;
}

Link::~Link()
{

}
