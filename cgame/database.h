#ifndef DATABASE_H
#define DATABASE_H

#include "file.h"
#include <vector>
#include <string>

using namespace std;

class Database {
	char * name;
	File file;
	public:
		Database(char * databasename);

		Database(const char * databasename);

		string get(string key);

		string get(char * key);

		void set(string key, string value);

		void set(char * key, char * value);
		
};

vector<string> split(string str, string delimeter);

vector<vector<string>> splitlines(string str);

#endif