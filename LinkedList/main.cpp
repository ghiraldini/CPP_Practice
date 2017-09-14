#include <iostream>
#include <string>
#include "Link.h"

int main()
{
    Link *myList = new Link;

    myList->add_link_end("A");
    myList->add_link_end("B");
    myList->add_link_start("A1");
    myList->print_list();

    myList->delete_link("A");
    myList->print_list();

    myList->delete_list();

    delete(myList);
    return 0;
}
