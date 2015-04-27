//Melissa Castillo <mcast052@ucr.edu>
//SID: 861157259
//April 20, 2015
#include <iostream> 
#include <assert.h>
using namespace std; 

template<typename T>
class TwoStackFixed
{
  private: 
    int size; 
    int maxtop;
    int stackSize1;
    int stackSize2; 
    T* arr;
  
  public: 
    TwoStackFixed(int size, int maxtop)
      : size(size), maxtop(maxtop), stackSize1(0), stackSize2(0)
    {
        arr = new T[size];
    }
    void pushStack1(T value)
    {
        if(isFullStack1())
        {
            cout << "Stack 1 is full" << endl; 
            return; 
        }
        arr[stackSize1] = value; 
        stackSize1++; 
        display(); 
    }
    void pushStack2(T value)
    {
        if(isFullStack2()) 
        {
            cout << "Stack 2 is full" << endl; 
            return; 
        }
        arr[size - stackSize2 - 1] = value; 
        stackSize2++; 
        display(); 
    }
    T popStack1()
    {
        if(isEmptyStack1())
        {
            cout << "Stack 1 is empty. Cannot pop on empty stack." << endl; 
            return -1; 
        }
        T tmp = arr[stackSize1 - 1]; 
        stackSize1--;
        display(); 
        return tmp; 
    }
    T popStack2()
    {
        if(isEmptyStack2())
        {
            cout << "Stack 2 is empty. Cannot pop on empty stack." << endl; 
            return -1; 
        }
        T tmp = arr[size - stackSize2 - 1]; 
        stackSize2--;
        display(); 
        return tmp; 
    }
  
	bool isFullStack1()
	{
	    if(stackSize1 == maxtop + 1) return true; 
	    return false; 
	}
	bool isFullStack2()
	{   
	    if(stackSize2 == (size - 1) - maxtop) return true; 
	    return false; 
	}
	bool isEmptyStack1()
	{
	    if(stackSize1 == 0) return true; 
	    return false; 
	}
	bool isEmptyStack2()
	{
	    if(stackSize2 == 0) return true; 
	    return false; 
	}
	
	void display()
	{
	    unsigned i = 0; 
	    for(i = 0; i < stackSize1; i++)
	    {
	        cout << arr[i] << ' '; 
	    }
	    if(!isFullStack1())
	    {
    	    for( ; i < size - maxtop; i++)
    	    {
    	        cout << " " << ' '; 
    	    }
	    }
	    if(!isFullStack2())
	    {
    	    for( ; i < size - stackSize2; i++)
    	    {
    	        cout << " " << ' '; 
    	    }
	    }
	    for( ; i < size; i++)
	    {
	        cout << arr[i] << ' '; 
	    }
	    cout << endl; 
	}
};

template<typename T> 
class TwoStackOptimal
{
  private: 
    int size; 
    int stackSize1; 
    int stackSize2; 
    T* arr; 
 
  public: 
    TwoStackOptimal(int size)
      : size(size), stackSize1(0), stackSize2(0)
    {
        arr = new T[size]; 
    }
    void pushFlexStack1(T value)
    {
        if(isFullStack1()) 
        {
            cout << "Stack 1 is full" << endl; 
            return; 
        }
        arr[stackSize1] = value; 
        stackSize1++; 
        display(); 
    }
    void pushFlexStack2(T value)
    {
        if(isFullStack2())
        {
            cout << "Stack 2 is full" << endl; 
            return; 
        }
        arr[size - stackSize2 - 1] = value; 
        stackSize2++; 
        display(); 
    }
    T popFlexStack1()
    {
        if(isEmptyStack1())
        {
            cout << "Stack 1 is empty. Cannot pop on an empty stack." << endl; 
            return -1; 
        }
        T tmp = arr[stackSize1 - 1]; 
        stackSize1--; 
        display(); 
        return tmp; 
    }
    T popFlexStack2()
    {
        if(isEmptyStack2())
        {
            cout << "Stack 2 is empty. Cannot pop on an empty stack." << endl; 
            return -1;
        }
        T tmp = arr[size - stackSize2 - 1]; 
        stackSize2--; 
        display(); 
        return tmp; 
    }
    
  private: 
    bool isFullStack1()
    {
        if(stackSize1 == size) return true; 
        else if(stackSize1 + stackSize2 == size) return true; 
        return false; 
    }
    bool isFullStack2()
    {
        if(stackSize2 == size) return true; 
        else if(stackSize1 + stackSize2 == size) return true; 
        return false; 
    }
    bool isEmptyStack1()
    {
        if(stackSize1 == 0) return true; 
        return false; 
    }
    bool isEmptyStack2()
    {
        if(stackSize2 == 0) return true; 
        return false; 
    }
    void display()
	{
	    unsigned i = 0; 
	    for(i = 0; i < stackSize1; i++)
	    {
	        cout << arr[i] << ' '; 
	    }
	    if(!isFullStack1())
	    {
    	    for( ; i < size - stackSize2 - stackSize1; i++)
    	    {
    	        cout << ' ' << ' '; 
    	    }
	    }
	    if(!isFullStack2())
	    {
    	    for( ; i < size - stackSize2; i++)
    	    {
    	        cout << ' ' << ' '; 
    	    }
	    }
	    for( ; i < size; i++)
	    {
	        cout << arr[i] << ' '; 
	    }
	    cout << endl; 
	}
};