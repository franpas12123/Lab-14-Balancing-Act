#include <iostream>
#include <cmath>

template <class T>
class bstnode{
public:
	T item;
	bstnode<T>* left, parent,right;
	int what_child; // 1 = left; 1 = right;
	int height;
	int height_diff;
	int leaning; // -1 = left; 1 = right;

	bstnode();
	bstnode(T);
	~bstnode();
};

template <class T>
bstnode<T>::bstnode(){
	T = left = right = parent = NULL;
	height = what_child = height_diff = 0;
}

template <class T>
bstnode<T>::bstnode(T item){
	this.item = item;
	left = right = parent = NULL;
	height = what_child = height_diff = 0;
}


//tree
template <class T>
class balance_Tree{
	bstnode<T>* root;
public:
	balance_Tree();
	~balance_Tree();
	
	void insert(T);
	void updateHeight(bstnode*);
};

template <class T>
balance_Tree<T>::balance_Tree(){
	root = NULL;
}

template <class T>
void balance_Tree<T>::insert(T item){
	bstnode *new_node = new bstnode(item);

	if (root == NULL) {
		root = new_node;
	} else {
		bstnode *traverse = root;

		while(true){
			if (item > traverse->item){
				if (traverse->right != NULL){
					traverse = traverse->right;
				} else {
					traverse->right = new_node;
					new_node->what_child = 1;
					break;
				}
			} else {
				if (traverse->left != NULL){
					traverse = traverse-> left;
				} else{
					traverse->left = new_node;
					new_node->what_child = -1;
					break;
				}
			}
			new_node->parent = traverse;
		}
	}
	// update height every insert
	updateHeight(new_node);
}

template <class T>
void balance_Tree<T>::updateHeight(bstnode* node){
	int ctr = 0;
	while (node->parent != NULL){
		node->parent->height_diff = abs(node->parent->height - (++ctr));

		if (node->parent->height_diff > 1) { // if imbalance
			
		} else if (node->parent->height_diff == 1) {
			node->parent->leaning = node->what_child; // leaning depends on child position (left or right)
		}

		node->parent->height = max(node->parent->height, ctr);
		node = node->parent;
	}
}