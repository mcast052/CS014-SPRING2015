//Melissa Castillo <mcast052@ucr.edu>
//SID: 861157259	
//April 26, 2015
#include "lab3.h"
#include <iostream> 
#include <stack>
using namespace std; 

int main()
{
	TwoStackFixed<int> a(5, 2); 
	a.pushStack1(1); 
	a.pushStack2(2); 
	a.pushStack1(3); 
	a.pushStack2(4); //Stack 2 Full
	a.pushStack1(5); //Stack 1 Full
	a.pushStack2(6); 
	
	a.popStack2(); 
	a.popStack1();
	a.popStack1(); 
	a.popStack1(); 
	a.popStack1(); //Stack 1 Empty
	a.popStack2(); 
	
	TwoStackFixed<char> b(8, 5);
	b.pushStack1('a'); 
	b.pushStack1('b'); 
	b.pushStack1('c');
	b.pushStack1('d'); 
	b.pushStack1('e'); 
	b.pushStack2('f'); 
	b.pushStack2('g'); // Stack 2 Full
	b.pushStack1('h'); //Stack 1 Full
	b.pushStack1('i');
	b.pushStack2('j'); 
	
	b.popStack1(); 
	b.popStack1(); 
	b.popStack1(); 
	b.popStack1(); 
	b.popStack1(); //Stack 1 is Empty
	b.popStack2(); 
	b.popStack2(); //Stack 2 is Empty
	b.popStack2(); 
	b.popStack2(); 
	
	TwoStackOptimal<int> c(6); 
	c.pushFlexStack1(20); 
	c.pushFlexStack1(30); 
	c.pushFlexStack1(40); 
	c.pushFlexStack1(50); 
	c.pushFlexStack2(5); 
	c.pushFlexStack2(15); //Stack is full
	c.pushFlexStack2(60); 
	c.pushFlexStack2(25); 
	
	c.popFlexStack1(); 
	c.popFlexStack1(); 
	c.popFlexStack1(); 
	c.popFlexStack1();
	c.popFlexStack1(); //Stack 1 is empty
	c.popFlexStack2(); 
	c.popFlexStack2(); 
	c.popFlexStack2(); //Stack 2 is empty
	c.popFlexStack1(); 
	c.popFlexStack2();
	
	stack<int> source;
	source.push(4); 
	source.push(3);
	source.push(2); 
	source.push(1); 
	
	stack<int> aux; 
	stack<int> dest; 
	
	showTowerStates(4, source, aux, dest); 
	
	return 0; 
}