#include <iostream>
#include <string>
#include <vector>
#include <climits>

struct Node{
	int data;
	Node* left;
	Node* right;
};

bool checkBST(Node*);
void insert_node(Node*, int);
void traverse(Node*, std::vector<int> &);
bool is_bst(Node*, int, int);



int main(int argc, char* argv[]){

	// Create valid BS Tree
	//		4	
	//	2		6
	//   1     3	     5      7
	
	Node* root = new Node;
	root->data = 4;
	root->left = NULL;
	root->right = NULL;

	insert_node(root, 2);
	insert_node(root, 6);
	insert_node(root, 1);
	insert_node(root, 3);
	insert_node(root, 5);
	insert_node(root, 7);

	if( checkBST(root) )
		std::cout << "True" << std::endl;
	else
		std::cout << "Nope" << std::endl;		
	

	return 0;
}


bool checkBST(Node* root){
	return is_bst(root, INT_MIN, INT_MAX);
}

bool is_bst(Node* node, int min, int max){
	if(node == NULL) return true;
	if(node->data < min || node->data > max)
		return false;
	return is_bst(node->left, min, node->data-1) && is_bst(node->right, node->data+1, max);
}

// Pre-Order Traversal [Node, Left, Right]
void traverse(Node* root, std::vector<int> &vals){
	if(root == NULL) return;
	std::cout << root->data << std::endl;
	vals.push_back(root->data);
	traverse(root->left, vals);
	traverse(root->right, vals);
}



void insert_node(Node* temp, int data){
	bool left=false;

	while( temp != NULL ){
		if ( data < temp->data ){
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
		std::cout << "Adding " << data << " to left of " << temp->data << std::endl;
		temp->left = n;
	}else{
		std::cout << "Adding " << data << " to right of " << temp->data << std::endl;
		temp->right = n;
	}
}
