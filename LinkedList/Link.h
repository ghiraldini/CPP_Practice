#ifndef LINK_H
#define LINK_H
#include <string>


struct Node{
    std::string myStr;
    Node *next;
};

class Link
{
    public:
        Link();
        virtual ~Link();

        void add_link_end(std::string);
        void add_link_start(std::string);
        void print_list();
        void delete_link(std::string);
        void delete_list();

    protected:

    private:
        Node *head;

};

#endif // LINK_H
