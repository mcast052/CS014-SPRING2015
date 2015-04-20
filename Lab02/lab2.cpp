//Melhissa Castillo <mcast052@ucr.edu> 
//SID: 861157259
//April 13, 2015
#include <iostream> 
#include <list>
#include <forward_list>
#include <iterator>
#include "lab2.h"
using namespace std; 

bool isPrime(int i)
{
    //2 and 1 are not prime numbers
    if(i <= 2) return false;  
    //Checks if i is divisible by any other number 
    //up to sqrt(i) or n*n (repitition of number after)
    for(int n = 2; n * n <= i; ++n)
    {
        //Checks if n is a factor of i
        if(i % n == 0) return false; 
    }
    return true; 
}

int primeCount(forward_list<int> lst)
{
    //int counter = 0;
    if(lst.empty()) return 0; 
    else if(!isPrime(lst.front()))
    {
        lst.pop_front(); 
        return primeCount(lst);
    }

    lst.pop_front(); 
    return primeCount(lst) + 1; 
}

int main()
{
    //Testing printLots
    forward_list<int> a; 
    a.push_front(1); 
    a.push_front(5); 
    a.push_front(2); 
    a.push_front(36); 
    a.push_front(7); 
    a.push_front(15); 
    a.push_front(21); 
    a.push_front(14); 
    a.push_front(88); 
    a.push_front(11);
    a.push_front(13); 
    a.push_front(4); 
    
    //List of list index for testing of printLots
    forward_list<int> b; 
    b.push_front(15); 
    b.push_front(10);
    b.push_front(7); 
    b.push_front(5); 
    b.push_front(4); 
    b.push_front(2); 
    b.push_front(0); 
    
    printLots(a, b); 
    
    //Testing primeCount 
    cout << "There are " << primeCount(a) << " prime numbers in this list." << endl;
    
    //Testing listCopy 
    forward_list<char> c; 
    c.push_front('t'); 
    c.push_front('a'); 
    c.push_front('c'); 
    
    forward_list<char> d; 
    d.push_front('s'); 
    d.push_front('g'); 
    d.push_front('o');
    d.push_front('d'); 
    
    listCopy(d, c); 
    for(auto i = c.begin(); i != c.end(); ++i)
    {
        cout << *i; 
    }
    cout << endl; 
    
    forward_list<int>e; 
    e.push_front(5); 
    e.push_front(4); 
    e.push_front(3); 
    e.push_front(2); 
    e.push_front(1); 
    listCopy(e, b); 
    for(auto i = b.begin(); i != b.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl; 
    
    //Testing elementSwap
    List<int> f; 
    f.push_front(6); 
    f.push_front(5); 
    f.push_front(4); 
    f.push_front(3); 
    f.push_front(2); 
    f.push_front(1); 
    f.push_front(0); 
    
    f.display(); 
    f.elementSwap(5); 
    f.display(); 
    f.elementSwap(0); 
    f.display(); 
    f.elementSwap(3); 
    f.display(); 
    
    return 0; 
}