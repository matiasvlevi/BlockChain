#include <iostream>
#include <vector>
#include "Block.h"
#include "Chain.h"
#include <string>
using namespace std;
void prompt(Chain chain)
{
	// Ask for Input Data from the user:
	string data;
	cout << " " << endl;
	cout << " Add new block: ";
	getline(cin, data);
	chain.add(data);
	// Clear & log chain
	system("cls");
	chain.log();
	// Call Add again
	prompt(chain);
}
int main() 
{
	//Create Chain instance & log contents
	Chain chain;
	chain.log();
	// Ask for user Input
	prompt(chain);
}

