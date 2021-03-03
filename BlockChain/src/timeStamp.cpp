#include <iostream>
#include "timeStamp.h" 
#include <sstream>
#include <string>
#include <ctime>

using namespace std;
string getTimeStamp(void)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	stringstream date;
	date << ltm->tm_mday
		<< "/"
		<< 1 + ltm->tm_mon
		<< "/"
		<< 1900 + ltm->tm_year
		<< " "
		<< 1 + ltm->tm_hour
		<< ":"
		<< 1 + ltm->tm_min
		<< ":"
		<< 1 + ltm->tm_sec;
	return date.str();
}