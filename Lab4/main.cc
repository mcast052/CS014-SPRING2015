//Melissa Castillo <mcast052@ucr.edu>
//SID: 861157259
//May 3, 2015
// Approach: For the first two problems, I implemented respective preorder and 
// postorder helper functions, which each generated the three children nodes 
// (by passing in the first and second component of the parent node and the
// integer, k, the sum must be less than) and then checked their sums 
// and outputted the pairs in their respective order. For the third problem, 
// I created a priority_queue class, which had a vector of integer pairs
// as the private data member. The push member function pushed the pairs
// into the vector and then sorted them by their sums and components. 
// To solve the actual problem, I created two recursive helper functions, 
// insert(int, int, int, priority_queue) and sorted(priority_queue), which 
// respectively pushed pairs that were less than k into the queue and printed
// the pairs out. I then called these two functions in my original sorted(int)
// function. 

#include <iostream>
#include <cstdlib>
#include "lab4.h"
using namespace std; 

int main(int argc, char* argv[])
{
	//Checks if user passed in enough commang line arguments
	if(argc != 2)
	{
		cout << "Error: Too few arguments" << endl; 
		exit(-1); 
	}
	//Tests
	cout << "Pre order: " << endl; 
	preOrder(atoi(argv[1])); 
	cout << "Post order: " << endl; 
	postOrder(atoi(argv[1]));
	cout << "Sorted: " << endl; 
	sorted(atoi(argv[1])); 
	
	return 0; 
}