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
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstdlib>
using namespace std;

typedef pair<int,int> Entry;
class priority_queue 
{
  private: 
  	vector<Entry> entries;
  public:
    //Returns the size of the priority_queue
  	int size() { return entries.size(); }
  	//Returns the front of the queue (last value of the vector)
  	Entry& front() { return entries.back(); }
  	//Removes the front of the queue (last value of the vector)
  	void pop() { entries.pop_back(); }
  	//Pushes entries into queue 
  	void push(Entry e) 
	{ 
		//pushes entries into vector
		entries.push_back( e );
		//Then sorts the entries in order by comparing the components of 
		//the pairs and their sums
	    for( int i = entries.size()-1; i != 0; --i ) 
	    {
	    	//Checks if the sum of the top entry is less than the one below
	    	if(entries[i].first + entries[i].second < 
	    	entries[i-1].first + entries[i-1].second) break; 
	    	//If the sums are equal, then it breaks the tie by comparing
	    	//the first and second components of the pair
	    	else if(entries[i].first + entries[i].second == 
	    	entries[i-1].first + entries[i-1].second) 
	    	{
	    		if(entries[i] < entries[i-1]) break;
	    	}
	    	//Else, it swaps the entries
	      	swap(entries[i], entries[i-1]);
	    }
	}
};

void preOrder(int m, int n, int k)
{
	//Base case
	if(m + n > k)
	{
		return; 
	}
	//Prints the pair 
	else if(m + n < k) 
	{
		cout << m << " " << n << endl; 
	}
	//Generates the first child
	preOrder(2 * m - n, m, k); 
	//Generates the second child
	preOrder(2 * m + n, m, k); 
	//Generates the third child
	preOrder(m + 2 * n, n, k); 
}

void preOrder(int k)
{
	//Goes through left subtree
	preOrder(2, 1, k); 
	//Goes through right subtree
	preOrder(3, 1, k); 
}

void postOrder(int m, int n, int k)
{
	//Base case
	if(m + n > k)
	{
		return; 
	}
	//Generates the first child
	postOrder(2 * m - n, m, k); 
	//Generates the second child
	postOrder(2 * m + n, m, k); 
	//Generates the third child
	postOrder( m + 2 * n, n, k);
	//Prints the pair
	if(m + n < k)
	{
		cout << m << " " << n << endl; 
	}
	
}

void postOrder(int k)
{
	//Goes through the left subtree
	postOrder(2, 1, k); 
	//Goes through the right subtree
	postOrder(3, 1, k); 
}

//This helper function will insert pairs into a priority_queue and sort them
void insert(int m, int n, int k, priority_queue &a)
{
	//Base case
	if(m + n > k)
	{
		return; 
	}
	//Pushes pairs into priority_queue vector
	else if(m + n < k)
	{
		pair<int, int> entry(m, n);
		a.push(entry); 
	}
	//Generates the first child
	insert(2 * m - n, m, k, a); 
	//Generates the second child
	insert(2 * m + n, m, k, a); 
	//Generates the third child
	insert(m + 2 * n, n, k, a); 
}

//This helper function will print out the sorted pairs
void sorted(priority_queue &a)
{ 
	//Base case
	if(a.size() == 0)
	{
		return; 
	}
	//Prints the top pair
	cout << a.front().first << " " << a.front().second << endl; 
	//Pops the top pair off
	a.pop(); 
	//Recursive step
	sorted(a); 
}

void sorted(int k)
{
	//Creates priority_queue that will store pairs in sorted order
	priority_queue tmp; 
	//Pushes pairs into tmp
	insert(2, 1, k, tmp); 
	insert(3, 1, k, tmp);
	//Prints out the pairs in sorted order
	sorted(tmp); 
}


