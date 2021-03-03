#ifndef CHAIN_H
#define CHAIN_H

#pragma once
#pragma warning(disable : 4200)
#include <iostream>
#include <vector>
#include <string>
#include "Block.h"

using std::vector;
class Chain
{
	public:
		vector<Block> list;
		Chain();
		void add(string data);
		void log();
};

#endif