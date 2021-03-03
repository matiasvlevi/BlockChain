

#ifndef BLOCK_H
#define BLOCK_H
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Block {
	public:
		int index;
		bool valid;
		string previousHash;
		string time;
		string hash;
		string data;
		Block();
		void init(string d,string t, string pHash, int i);
		void log(void);
};

#endif 