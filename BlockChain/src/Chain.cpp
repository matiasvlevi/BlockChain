
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Block.h"
#include "Chain.h"
#include "timeStamp.h"

using namespace std;

Chain::Chain() 
{
	string tstr = getTimeStamp();
	Block gen;
	gen.init("Genosis", tstr,"0",0);
	list.push_back(gen);
}

void Chain::add(string data) 
{
	string tstr = getTimeStamp();
	Block b;
	b.init(data, tstr, list[list.size() - 1].hash, list.size());
	list.push_back(b);
}

void Chain::log()
{
	cout << "Chain (len: " << list.size() << ")" << endl;
	cout << "[" << endl;
	for (int i = 0; i < list.size(); i++) {
		list[i].log();
		if (i != list.size() - 1) {
			cout << "," << endl;
		} else {
			cout << "" << endl;
		}
	}
	cout << "]" << endl;
}