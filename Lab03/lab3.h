//Melissa Castillo <mcast052@ucr.edu>
//SID: 861157259
//April 20, 2015
//Approach: I implemented two classes, TwoStackFixed and TwoStackOptimal.
//The former class had the private data members size (size of the stack), 
//maxtop (the index of the partition), stackSize1 (keeps track of the size
//of stack 1), stackSize2 (keeps track of the size of stack 2), and
// arr (a pointer to my dynamically allocated array which stores the two
//stacks). For the latter class, I used the same private data members except
//for maxtop. For the tower of hanoi problem, I implemented two helper functions:
//print, which helped print out the movements of the values in the stacks, 
//and move, which actually moved the values between the three stacks, and 
//showTowerStates used those two functions to solve the whole problem. 
#include <iostream> 
#include <assert.h>
#include <stack>
using namespace std; 

template<typename T>
class TwoStackFixed
{
  private: 
    int size; //size of whole stack
    int maxtop; //index of partition
    int stackSize1; //size of Stack 1
    int stackSize2; //size of Stack 2
    T* arr; //pointer to array storing stacks
  
  public: 
    TwoStackFixed(int size, int maxtop)
      : size(size), maxtop(maxtop), stackSize1(0), stackSize2(0)
    {
        arr = new T[size]; //dynamically allocates new stack
    }
    void pushStack1(T value)
    {
        //Checks if the stack is full
        if(isFullStack1())
        {
            cout << "Stack 1 is full" << endl; 
            return; 
        }
        //Inserts value into array/stack
        arr[stackSize1] = value; 
        //Increments the size of stack 1
        stackSize1++; 
        display(); 
    }
    void pushStack2(T value)
    {
        //Checks if the stack is full
        if(isFullStack2()) 
        {
            cout << "Stack 2 is full" << endl; 
            return; 
        }
        //Inserts value into array/stack
        arr[size - stackSize2 - 1] = value; 
        //Increments the size of stack 2
        stackSize2++; 
        display(); 
    }
    T popStack1()
    {
        //Checks if popping on empty stack
        if(isEmptyStack1())
        {
            cout << "Stack 1 is empty. Cannot pop on empty stack." << endl; 
            return -1; 
        }
        T tmp = arr[stackSize1 - 1]; 
        //Decrements size of stack
        stackSize1--;
        display(); 
        //Returns value of element popped off
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
	    //Checks if the size of stack one is equal to maxtop + 1 
	    // maxtop gives index of last element in stack 1
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
        //Checks if stack 1 dominated the stack
        if(stackSize1 == size) return true; 
        //Checks size of stack 1 against size of stack 2, if there are any
        //free spaces open in array
        else if(stackSize1 + stackSize2 == size) return true; 
        return false; 
    }
    bool isFullStack2()
    {
        //Checks if stack 2 dominated the stack
        if(stackSize2 == size) return true; 
        //If stack 1 fills up the rest of the free spaces, stack 2 is also full
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

//Tower of Hanoi 
//Helper function helps print out the movements
void print(int n, char a, char b, char c)
{
	if(n == 1)
	{
		cout << "Moved " << n << " from peg " << a << " to peg " << b << endl; 
		return; 
	}
	else
	{
		print(n - 1, a, c, b); 
		cout << "Moved " << n << " from peg " << a << " to peg " << b << endl; 
		print(n - 1, c, b, a); 
	}
}

//Helper function actually moves the values between the stacks
template<typename T>
void move(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
	if(n == 1)
	{
	    //Pushes top of A into C
		C.push(A.top()); 
		//Pops element off of A
		A.pop(); 
		return; 
	}
	move(n - 1, A, C, B); 
	//Pushes top of A into C
	C.push(A.top()); 
	//Pops element off of A
	A.pop();
	move(n - 1, C, B, A); 
}

//Solves the problem
template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
	print(n, 'A', 'B', 'C'); 
	move(n, A, B, C); 
}