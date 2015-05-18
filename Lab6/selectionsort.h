//Melissa Castillo <mcast052@ucr.edu> 
//SID: 861157259
//May 12, 2015

#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__
#include <iostream> 
#include <utility> 
#include <vector>
#include <list>
using namespace std; 


void display(vector< pair<int, int> >& l)
{
 	auto it = l.begin(); 
	for( ; it != l.end(); it++)
	{
		cout << "(" << get<0>(*it) << ", " << get<1>(*it) << ") ";
	}
	cout << endl;
}

template<typename L> 
void display(L& l)
{
	auto it = l.begin(); 
	for( ; it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<typename L> 
void selectionsort(L& l)
{
	int count = 0; 
	int copies = 0; 
	if(l.size() <= 1) return; 
	
	cout << "pre: ";
	display(l); 
	
	for(auto check = l.begin(); check != l.end(); check++)
	{
		auto smallest = check;
		smallest++; 
		if(smallest != l.end())
		{
			for(auto curr = smallest; curr != l.end(); curr++)
			{
				if(*curr < *smallest)
				{
					smallest = curr; 
				}
			}
			if(*smallest < *check)
			{
				swap(*check, *smallest); 
				count += 3; 
			}
		}
	}
	
	cout << "post: ";
	display(l); 
	cout << copies << " copies and " << count << " number of moves." << endl; 
}

#endif