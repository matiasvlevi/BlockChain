#include <iostream>
#include <string>
#include "Block.h"
#include "sha256.h"

using namespace std;

Block::Block(void) 
{
	index = 0;
	valid = 0;
}
void Block::init(string d, string t, string pHash, int i) 
{
	data = d;
	time = t;
	previousHash = pHash;
	index = i;
	valid = 0;
	hash = sha256(data + time + previousHash + to_string(index));
}

void Block::log()
{
	cout << "  Block "<< index <<" {" << endl;

	cout << "    previousHash: " << previousHash << endl;
	cout << "    hash: " << hash << endl;

	cout << "    time: " << time << endl;
	cout << "    isValid: " << valid << endl;
	cout << " " << endl;
	cout << "    Data: " << data << endl;
	cout << "  }";
}