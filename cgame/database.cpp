#include "pch.h"
#include "database.h"

#include <vector>

using namespace std;

typedef vector<vector<string>> multi;

Database::Database(char * databasename):file(databasename) {
	log("init database without const");
	name = databasename;
	file = File(databasename);
}

Database::Database(const char * databasename) : file(databasename) {
	log("init database with const");
	name = (char *)databasename;
	file = File(databasename);
}

string Database::get(string key) {
	log("database get key, string key", key);
	string content = file.read();
	vector<vector<string>> splits = splitlines(content);
	if (splits.size() <= 0) {
		log("databse get key, list list empty", key);
		return "INVALID_KEY";
	} else {
		for (vector<string> i : splits) {
			if (i.size() <= 0) {
				log("database get key, list empty", key);
			} else {
				if (i.at(0) == key) {
					log("database get key, string key found", key);
					return i[1];
				}
			}
		}
	}
	log("database get key, no key exists", key);
	return "INVALID_KEY";
}

string Database::get(char * key) {
	log("database get key, char * key", key);
	return this->get(string(key));
}

void Database::set(string key, string value) {
	log("database set key, string key", key);
	char * _key = &key[0];
	char * _value = &value[0];
	return this->set(_key, _value);

}

void Database::set(char * key, char * value) {
	log("database set key, char * key", key);
	if (this->get(key) == "INVALID_KEY") {
		log("database set key noexist key");
		string content = file.read();
		string new_str = (string)key + " " + (string)value+ "\n";
		string new_content = content + new_str;
		file.write(new_content);
		log("database set key end success", key);
	}
	else {
		log("database set key end already exists");
	}
}


vector<string> split(string str, string delimeter) {
	log("split string", str);
	vector<string> list;
	string token;
	int current = 0, last = 0;
	while ((current = str.find(delimeter, last)) != string::npos) {
		token = str.substr(last, current - last);
		list.push_back(token);
		last = current + 1;
	}
	if (last < str.length()) {
		list.push_back(str.substr(last));
	}
	log("split string end", str);
	return list;
}

vector<vector<string>> splitlines(string str) {
	log("splitlines string", str);
	vector<vector<string>> list;
	string delim = "\n";
	vector<string> diced = split(str, delim);
	for (string i: diced) {
		vector<string> cut = split(i, " ");
		list.push_back(cut);
	}
	log("splitlines string", str);
	return list;
}