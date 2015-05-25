//Melissa Castillo <mcast052@ucr.edu> 
//SID: 861157259	
//May 22, 2015
// Approach: 

#include <iostream> 
#include <vector> 
#include <fstream> 
#include <cstdlib> 
#include <unordered_set> 
#include <set>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono; 

//Gets the time the program takes to run insert for a given container
template<typename T>
duration<double, milli> run_insert(T& t, vector<string>& v, int num)
{
	//starting point for clock
	high_resolution_clock::time_point start = high_resolution_clock::now(); 
	
	//inserts n number of words into given container
	for(unsigned i = 0; i < num; i++)
	{
		t.insert(v.at(i));
	}
	
	//ending point for clock
	high_resolution_clock::time_point end = high_resolution_clock::now();
	
	//gets timespan in milliseconds and returns that value
	duration<double, milli> timespan = 
	duration_cast<duration<double, milli>>(end - start);
	return timespan;
}

//Gets the time the program takes to run find for a given container
template<typename T> 
duration<double, milli> run_find(T& t, vector<string>& v, int num)
{
	//starting point for clock
	high_resolution_clock::time_point start = high_resolution_clock::now(); 
	
	//looks for each word in the vector inside the given container
	for(unsigned i = 0; i < num; i++)
	{
		t.find(v.at(i)); 
	}
	
	//end point for clock
	high_resolution_clock::time_point end = high_resolution_clock::now(); 
	
	//gets the timespan in milliseconds and returns it
	duration<double, milli> timespan = 
	duration_cast<duration<double, milli>>(end - start); 
	
	return timespan;
}

//Randomly shuffles every single word in the vector
void shuffle(vector<string>& v)
{
	for(unsigned i = 0; i < v.size(); i++)
	{
		swap(v.at(i), v.at(rand() % v.size())); 
	}
}

//finds the average time for a given operation over 10 runs
duration<double, milli> findAvg(vector<duration<double, milli>>& v, double num)
{
	duration<double, milli> sum; //variable to keep track of total 
	for(unsigned i = 0; i < v.size(); i++)
	{
		sum += v.at(i); 
	}
	//total divided by num (n * 10 runs)
	return sum / num; 
}

int main(int argc, char **argv)
{
	srand(time(0));
	
	//Checks to see if there are valid number of command line 
	//arguments
	if(argc != 3)
	{
		cout << "ERROR: Too few arguments" << endl; 
		exit(-1); 
	}
	
	//Inputs words from txt file into a vector of strings
	string input_file = argv[1]; 
	ifstream fin(input_file.c_str()); 
	if(!fin.is_open())
	{
		cout << "ERROR: Unable to open file" << endl; 
		exit(-1); 
	}
	
	string input; 
	vector<string> words;
	while(fin >> input)
	{
		words.push_back(input); 
	}
	fin.close(); 
	
	//Opens output data file to print out the resulting times
	string output = argv[2];
	ofstream fout(output.c_str()); 
	if(!fout.is_open())
	{
		cout << "ERROR: Unable to open output file" << endl; 
		exit(-1); 
	}

	//Containers: tree (set), unordered_set (hash)
	set<string> test; 
	unordered_set<string> test2;
 
 	//Does the following runs of insert and find on the tree and hash
 	//Increasing the size of n by 5000 after each 10 tests of n
 	vector<duration<double, milli>> tInsert; //holds times for tree insert
 	vector<duration<double, milli>> hInsert; //holds times for hash insert
 	vector<duration<double, milli>> tFind; //holds times for tree find
 	vector<duration<double, milli>> hFind; //holds times for hash find
	for(int n = 5000; n <= 50000; n += 5000)
	{
		//Does insertion and find 10 times per n
		int i =  0;
		for( ; i < 10; i++)
		{
			tInsert.push_back(run_insert(test, words, n)); 
			hInsert.push_back( run_insert(test2, words, n) ); 
			tFind.push_back( run_find(test, words, n) ); 
			hFind.push_back( run_find(test2, words, n) ); 
			shuffle(words);
		}
		
		// <n> <tree-insert-time> <hash-insert-time> <tree-query-time> <hash-query-time>
		//Divided by i (number tests per n) * n (number of words) to find the average time 
		fout << n << " "
		<< duration_cast<duration<double, milli>>(findAvg(tInsert, i * n)).count() << " " 
		<< duration_cast<duration<double, milli>>(findAvg(hInsert, i * n)).count() << " "
		<< duration_cast<duration<double, milli>>(findAvg(tFind, i * n)).count() << " "
		<< duration_cast<duration<double, milli>>(findAvg(hFind, i * n)).count() << " "
		<< endl; 
	}
	
	fout.close();
	return 0; 
}


