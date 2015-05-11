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

#include <iostream> 
#include "lab5.h"
using namespace std; 

int main()
{
	cout << "Testcase 1" << endl; 
	BST<int> a; 
	a.insert(50); 
	a.insert(20); 
	a.insert(60); 
	a.insert(10); 
	a.insert(40); 
	a.insert(35); 
	a.insert(45); 
	a.insert(70); 

	cout << "Part 1" << endl; 
	a.minCover(); 
	a.displayMinCover(); cout << endl; 
	
	cout << "Part 2" << endl; 
	int buffer[1000]; 
	a.findSumPath(80, buffer); 
	
	cout << "Part 2" << endl;
	map<int, int> m; 
	a.vertSum(m);
	
	return 0; 
}