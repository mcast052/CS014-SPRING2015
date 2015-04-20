//Melissa Castillo <mcast052@ucr.edu>
//SID: 861157259
//April 13, 2015

// 1. Write a recursive function int primeCount( forward_list<int> lst ) to count the number of
// prime numbers in a numerical singly linked list and implement a helper function bool
// isPrime( int i ) to judge whether an integer is a prime or not.
// 2. Implement a singly linked list class List and write a member function List<Type>
// elementSwap( List<Type> lst, int pos ) to swap two adjacent elements pos and pos+1 of a
// singly linked list by adjusting only the links (and not the data).
// 3. Write a function forward_list <Type> listCopy( forward_list <Type> L, forward_list <Type>
// P ) to copy a singly linked list L into a second singly linked list P in reverse order by only
// traversing L once.
// 4. You are given a singly linked list L of a type, and another singly linked list P containing integers
// sorted in ascending order. Write a function void printLots (forward_list <Type> L,
// forward_list <int> P) to print the elements in L that are in positions specified by P. For instance,
// if P=1,3,4,6, the elements in positions 1,3,4, and 6 in L are printed.
#ifndef __LAB2_H__
#define __LAB2_H__
#include <iostream> 
#include <list> 
#include <forward_list>
using namespace std; 

template<typename Type>
struct Node
{
    Type data; 
    Node<Type> * next; 
    Node(Type data) : data(data), next(0) { }; 
};

template<typename Type>
class List
{
  private:
    Node<Type> * head; 
    
  public: 
    List() : head(0) { }; 
    ~List()
    {
        for(Node<Type> * curr = head; curr != 0; curr = curr->next)
        {
            delete curr; 
        }
    }
    void elementSwap(int pos)
    {
        //Special case for swapping at the head
        if(pos == 0)
        {
            Node<Type> * right = head->next; 
            head->next = right->next; 
            right->next = head;
            head = right; 
            return; 
        }

        Node<Type> * prev = head; //Points to node before (pos - 1) 
        Node<Type> * curr = head->next; //Points to current node (pos)
        //Iterates through list up to position wanted
        for(int i = 1; i < pos; i++)
        {
            curr = curr->next;
            prev = prev->next; 
        }
        
        //Points to the node after (pos + 1)
        Node<Type> * right = curr->next; 
        prev->next = right; 
        curr->next = right->next; 
        right->next = curr; 
    }
    void push_front(Type val)
    {
        Node<Type> * tmp = new Node<Type>(val);
        tmp->next = head; 
        head = tmp; 
    }
    void display()
    {
        for(Node<Type> * curr = head; curr != 0; curr = curr->next)
        {
            cout << curr->data << " "; 
        }
        cout << endl; 
    }
};


template<typename Type>
void listCopy(forward_list<Type> L, forward_list<Type>& P)
{
    forward_list<Type> temp; 
    
    for(auto l = L.begin(); l != L.end(); ++l)
    {
        //pushes elements of L in backwards into temp list
        temp.push_front(*l);
    }
    
    temp.splice_after(temp.before_begin(), P);
    P = temp; 
}

template<typename Type>
void printLots (forward_list <Type> L, forward_list <int> &P)
{
    auto l_itr = L.begin();
    int index = 0; 
    //Traverses list P
    for(auto p_itr = P.begin(); p_itr != P.end(); ++p_itr)
    {
        //Traverses list L up to the index indicated by P
        while(index < *p_itr)
        {
          //Bounds checking
          if(l_itr == L.end())
          {
            cout << "Error: Out of bounds" << endl;
            return; 
          }
          l_itr++; 
          index++; 
        }
        cout << *l_itr << " "; 
    }
}

#endif