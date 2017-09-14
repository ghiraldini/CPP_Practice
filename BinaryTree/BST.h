#ifndef BST_H
#define BST_H

struct Node{
    int data;
    Node *left;
    Node *right;
};

class BST
{
    public:
        BST();
        virtual ~BST();

        void add_leaf(int);
        void print();

    protected:

    private:
        Node *root;
        void insert(int,Node *);

        int compare(Node *, int);
        void print(Node *,int);

};

#endif // BST_H
