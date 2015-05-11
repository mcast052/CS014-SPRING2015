//Melissa Castillo <mcast052@ucr.edu>
//SID: 861157259
//May 4, 2015
// Approach: I implemented helper functions for minCover that recursively solves the
// problem, and I added a private data member to the Node class, called selected, 
// which is true when the node is selected as a part of the cover. 
// For the display, I implemented a helper function which counts the 
// number of nodes in the vertex cover and another function which helps display the
// nodes and the size of the cover. For the second problem, I implemented a helper
// function which takes in a the written parameters and a count variable, which 
// keeps track of how many nodes are in a path. For the last problem, I made another
// helper function that recursively solves the problem using the given parameters and
// then I called that function inside vertSum, where I passed in only a map. That function
// called my helper function and then displayed the the sums. 

#ifndef BST_H
#define BST_H
#define TEST

#include <cassert> 
#include <iostream> 
#include <fstream> 
#include <cstdlib>
#include <string> 
#include <sstream> 
#include <map> 
#include <list> 
#include <math.h>
#include <vector>

using namespace std;
#define nil 0

// #define Value int // restore for testing
template<typename Value> 
class BST {
	
	class Node { // binary tree node
	public: 
	  Node* left; 
	  Node* right; 
	  Value value; 
	  bool selected; 
	  bool visited; 
	  Node(const Value v = Value())
	    : left(nil), right(nil), value(v), selected(false), visited(false)
	  {}
	  Value& content() { return value; }
	  bool isInternal() { return left != nil && right != nil; }
	  bool isExternal() { return left != nil || right != nil; }
	  bool isLeaf() { return left == nil && right == nil; }
	  int height() {
	  	//returns the height of the subtree rooted at this node 
	  	//leaves are at level 0 and thus have no children
	  	if(isLeaf()) return 0; 
	  	//otherwise, the node has at least one child
	  	return 1; 
	  }
	  int size() {
	  	//returns the size of the subtree rooted at this node,
	  	
	  	//begins at size of 1 to count the rooted node
	  	int size = 1; 
	  	//counts number of children on left
	  	if(left != nil) size++; 
	  	//counts number of children on right
	  	if(right != nil) size++; 
	  	return size; 
	  }
	}; //Node
	
	//const Node* nil; //later nil will point to a sentinel node
	Node* root;
	int count; 
	
	int size(Node* n)
	{
		//If the tree is empty or the node it reaches is nil, return 0
	  	if(n == nil) return 0; 
	  	//Traverses through the right subtree of node
	  	size(n->right); 
	  	//Traverses through the left subtree of node
	  	size(n->left); 
	  	//Sums up the number of nodes, incrementing by 1
	  	return size(n->left) + size(n->right) + 1; 
	}
	bool search(Node* n, Value x)
	{
		//Base case for when the value is found
	  	if(n->value == x) return true; 
	  	//Searches the right subtree if value is bigger than curr value
	  	else if(x > n->value && n->right != nil) return search(n->right, x);
	  	//Searches left subtree if value is smaller than curr value
	  	else if(x < n->value && n->left != nil) return search(n->left, x);
	  	
	  	//Return false if not found
	  	return false; 
	}
	void preorder(Node* n) const
	{
		//Base case
	  	if(n == nil) 
	  	{
	  		return;
	  	}
	  	//Output rooted node of subtree
	  	cout << n->content() << endl; 
	  	//Traverses left subtree
	  	preorder(n->left); 
	  	//Traverses right subtree
	  	preorder(n->right); 
	}
	void postorder(Node* n) const
	{
		//Base case
	  	if(n == nil)
	  	{
	  		return; 
	  	}
	  	//Traverses left subtree
	  	postorder(n->left); 
	  	//Traverses right subtree
	  	postorder(n->right); 
	  	//Outputs content of rooted node
	  	cout << n->content() << endl; 
	}
	void inorder(Node* n) const
	{
		//Base case
	  	if(n == nil)
	  	{
	  		return; 
	  	}
	  	//Traverses left subtree
	  	inorder(n->left); 
	  	//Outputs content of rooted node
	  	cout << n->content() << endl; 
	  	//Traverses right subtree
	  	inorder(n->right); 
	}
	void operatorHelper(vector<Value> &v, Node* curr)
	{
		//Pushes elements of tree into vector up to index n
		if(curr == nil) return;
		//Traverses left subtree
		operatorHelper(v, curr->left);
		//Pushes elements into vector
		v.push_back(curr->content());
		//Traverses right subtree
		operatorHelper(v, curr->right); 
	}
	
    public: 
	int size() {
	  	//size of the overall tree
	  	//implements helper function size(Node* n)
	  	return size(root);
	}
	  
	bool empty() { return size() == 0; }
	void print_node(const Node* n) {
	  	//Print the node's value
	  	cout << n->content();
	  	return;
	}
	bool search(Value x) {
	  	//Search for a Value in the BST and return true iff it was found
	  	//Implements helper function search(Node* n, Value x)
	  	return search(root, x); 
	}
	  
	void preorder() const {
	  	//Traverse and print the tree one Value per line in preorder.
	  	//Implements the helper function preorder(Node* n)
	  	preorder(root); 
	}
	void postorder() const {
	  	//Traverse and print the tree one Value per line in postorder
	  	//Implements the helper function postorder(Node* n)
	  	postorder(root); 
	}
	void inorder() const {
	  	//Traverse and print the tree one Value per line in inorder
	  	//Implements helper function inorder(Node* n)
	  	inorder(root); 
	}
	Value& operator[] (int n) {
	  	//returns reference to the value field of the n-th Node
	  	if(n >= size())
	  	{
	  		cout << "Out of bounds" << endl; 
	  		exit(-1); 
	  	}
	  	else if(n == 0)
	  	{
	  		return root->content(); 
	  	}
	  	vector<Value> v; 
	  	//Pushes elements into vector
	  	operatorHelper(v, root);
	  	//Last element in vector is the element wanted
	  	return v.at(n);
	}
	  
	BST() : root(nil), count(0) { }
	  
	void insert(Value X) { root = insert(X, root); }
	Node* insert(Value X, Node* T) {
	  	//The normal binary-tree insertion procedure
	  	if(T == nil) {
	  		T = new Node(X); //the only place that T gets updated. 
	  	} else if(X < T->value) {
	  		T->left = insert(X, T->left);
	  	} else if(X > T->value) {
	  		T->right = insert(X, T->right);
	  	} else {
	  		T->value = X; 
	  	}
	  	
	  	//later, rebalancing code will be installed here
	  	
	  	return T; 
	}
	  
	void remove(Value X) { root = remove(X, root); }
	Node* remove(Value X, Node*& T) {
	  	//The normal binary-tree removal procedure
	  	//Weiss's code is faster but way more intricate
	  	if(T != nil) {
	  		if(X > T->value) {
	  			T->right = remove(X, T->right); 
	  		} else if(X < T->value) {
	  			T->left = remove(X, T->left); 
	  		} else { 					//X == T->value
	  			if(T->right != nil) {
	  				Node* x = T->right; 
	  				while(x->left != nil) x = x->left; 
	  				T->value = x->value; //successor's value
	  				T->right = remove(T->value, T->right); 
	  			} else if(T->left != nil) {
	  				Node* x = T->left; 
	  				while(x->right != nil) x = x->right; 
	  				T->value = x->value; //predecessor's value
	  				T->left = remove(T->value, T->left); 
	  			} else {
	  				delete T; 
	  				T = nil; //The only updating of T
	  			}
	  		}
	  	}
	  	//later, rebalancing code will be installed here
	  	return T; 
	}
	  
	void okay( ) { okay(root); }
	void okay(Node* T) {
	  	//disgnostic code can be installed here
	  	return; 
	}
	
	//Helper function for minCover that recursively traverses through tree
	void minCover(Node* n)
	{
		//Leaves are never part of the vertex cover
		if(n->isLeaf())
		{
			return; 
		}
		//Internal nodes are part of the cover if one of their children 
		//is not in the cover
		else if(n->isInternal())
		{
			//Traverses left subtree
			minCover(n->left);
			//Traverses right subtree
			minCover(n->right);
			
			//If one of the children is not in the cover, select that node
			if(!n->left->selected || !n->right->selected)
			{
				n->selected = true; 
			}
		}
		//External nodes treated differently (for seg faults)
		else if(n->isExternal())
		{
			//Traverses right subtree if no left subtree
			if(n->left == nil)
			{
				minCover(n->right); 
				if(!n->right->selected)
				{
					n->selected = true; 
				}
			}
			//Traverses left subtree if no right subtree
			else if(n->right == nil)
			{
				minCover(n->left);
				if(!n->left->selected)
				{
					n->selected = true; 
				}
			}
		}
	}
	
	//Original function calls recursive helper function above
	void minCover()
	{
		minCover(root); 
	}
	
	//displayMinCover helper function to output vertex cover inorder
	void display(const Node* n)
	{
		//Base case
		if(n == nil)
		{
			return; 
		}
		//Traverses left subtree
		display(n->left); 
		//Outputs node value only if the node has been selected
		if(n->selected)
		{
			cout << n->value << " "; 
		}
		//Traverses right subtree
		display(n->right); 
	}
	
	//displayMinCover helper function which will count the size of the vertex cover
	int countVertex(Node* n)
	{
		//Leaves are never part of the cover
		if(n->isLeaf())
		{
			return 0; 
		}
		//Checks if current node has been selected as part of cover
		if(n->selected)
		{
			//If node is internal, traverse left and right subtrees and add 1
			if(n->isInternal())
			{
				return countVertex(n->left) + countVertex(n->right) + 1; 
			}
			//If external, check existing subtree and add 1
			else if(n->isExternal())
			{
				if(n->left != nil)
				{
					return countVertex(n->left) + 1;
				}
				if(n->right != nil)
				{
					return countVertex(n->right) + 1; 
				}
			}
		}
		//Otherwise, continue traversing through the tree,
		//but do not increment count 
		return countVertex(n->left) + countVertex(n->right); 
	}
	
	//Original function calls two helper functions above to work 
	//through problem recursively
	void displayMinCover()
	{
		display(root);
		cout << endl << countVertex(root) << endl; 
	}
	
	void findSumPath(Node* n, int sum, int buffer[], int count)
	{
		if(sum == 0 && !n->isLeaf())
		{
			count = 0; 
			return; 
		}
		else if(sum == 0)
		{
			return; 
		}
		if(sum - n->value <= n->value && n->left != nil)
		{
			findSumPath(n->left, sum - n->value, buffer, count);
		}
		buffer[count] = n->value; 
		if(sum - n->value >= n->value && n->right != nil)
		{
			findSumPath(n->right, sum - n->value, buffer, count++);
		}
	}
	
	void findSumPathDisplay(int buffer[], int count)
	{
		if(count ==  0)
		{
			cout << "0" << endl; 
			return; 
		}
		
		for(int i = 0; i < 3; i++)
		{
			cout << buffer[i] << " "; 
		}
		cout << endl; 
	}

	void findSumPath(int sum, int buffer[])
	{
		int count = 0; 
		findSumPath(root, sum, buffer, count);
		findSumPathDisplay(buffer, count); 
	}

	//Helper function for vertSum
	void vertSum(Node* node, int hd, std::map<int, int>& m)
	{
		//Base case
		if(node == nil)
		{
			return; 
		}
		//Traverses left links, decrementing hd by 1
		vertSum(node->left, hd - 1, m); 
		//Sums up the values of the nodes of the same key (same vertical index)
		m[hd] += node->value;
		//Traverses right links, incrementing hd by 1
		vertSum(node->right, hd + 1, m);
	}

	//Calls the helper function above
	void vertSum(std::map<int, int>& m)
	{
		//Calls helper function above, passing in the root node, map, and
		//hd = 0 (because it starts at the root)
		vertSum(root, 0, m);
		//Displays the vertical sums stored in map
		for(map<int, int>::iterator i = m.begin(); i != m.end(); i++)
		{
			cout << i->second << " "; 
		}
		cout << endl; 
	}
	
}; //BST
#endif