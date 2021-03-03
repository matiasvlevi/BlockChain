
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
	add("Genosis");
}

void Chain::add(string data) 
{
	string tstr = getTimeStamp();
	Block b;
	
	int index = list.size();
	string pHash = "0";
	if (index != 0) {
		pHash = list[list.size() - 1].hash;
	}
	b.init(data, tstr, pHash, index);

	bool valid = isValid(b);
	b.valid = valid;
	if (b.valid) {
		list.push_back(b);
	} else {
		cout << "Block is not valid" << endl;
	}
	
}
bool Chain::isValid(Block block)
{
	if (list.size() != 0) {
		Block currentBlock = list[list.size() - 1];
		if (currentBlock.index + 1 != block.index) {
			return false;
		}
		else if (currentBlock.hash != block.previousHash) {
			return false;
		}
		else {
			return true;
		}
	} else {
		return true;
	}

}
void Chain::log()
{
	cout << "Chain (len: " << list.size() << ")" << endl;
	cout << "[" << endl;
	for (unsigned int i = 0; i < list.size(); i++) {
		list[i].log();
		if (i != list.size() - 1) {
			cout << "," << endl;
		} else {
			cout << "" << endl;
		}
	}
	cout << "]" << endl;
}