//Melissa Castillo <mcast052@ucr.edu>
//SID: 861157259
//May 18, 2015
#include "selectionsort.h"
#include <iostream> 
#include <vector> 
#include <list>
#include <deque>
#include <utility>
using namespace std; 

int main()
{
	//TEST 1
	vector<int> v; 
	v.push_back(2); 
	v.push_back(4); 
	v.push_back(5); 
	v.push_back(1); 
	v.push_back(8); 
	v.push_back(9); 
	selectionsort(v); 
	
	
	
	//TEST 2
	list<int> v2; 
	selectionsort(v2); 
	
	
	//TEST 3
	vector< std::pair<int, int> > v3(8); 
	v3 = 
	{
		{1, 2}, 
		{3, -1},
		{-1, 3},
		{0, 0},
		{2, 3},
		{1, 2},
		{1, -2}, 
		{8, 10},
	};
	
	selectionsort(v3);
	
	//TEST #4
	vector< std::pair<int, int> > v4(11); 
	v4 = 
	{
		{10, 2}, 
		{-3, 1}, 
		{-8, 0}, 
		{1, 1}, 
		{1, 1}, 
		{0, 0}, 
		{10, 2},
		{5, 5}, 
		{5, -5},
		{0, 0}, 
		{10, 2}
	};
	selectionsort(v4); 

	//TEST #5
	vector< std::pair<int, int> > v5 {
		{-1, 3},
		{0, 0},
		{1, -2},
		{1, 2},
		{1, 2},
		{2, 3},
		{3, -1},
		{8, 10}
	};
	selectionsort(v5);
	
	//TEST FOR STABLE SORT
	list<int> l; 
	l.push_back(2); 
	l.push_back(2); 
	//Should have 0 copies and 0 moves
	selectionsort(l); 
	
	vector< pair<int, int> > l2
	{
		{-2, 3},
		{1, 1},
		{1, 1}
	};
	selectionsort(l2); 
	return 0; 
}