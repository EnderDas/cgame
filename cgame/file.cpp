#include "pch.h"
#include "file.h"

using namespace std;

constexpr bool LOG = false;

File::File(char * filename) {
	log("init file without const");
	name = filename;
}

File::File(const char * filename) {
	log("init file with const");
	name = (char *)filename;
}

void File::write(string content) {
	log("writing to file", content);
	ofstream file;
	file.open(name);
	file << content;
	file.close();
}

string File::read() {
	log("reading file");
	ifstream file;
	file.open(name);
	string line;
	string content;
	//file >> content;
	while (getline(file, line)) {
		content = content + line + "\n";
	}
	file.close();
	return content;
}

void log(const char * str, string ext) {
	if (LOG == true) {
		cout << str << "with obj:" << ext << endl;
	}
}

void log(const char * str) {
	if (LOG == true) {
		cout << str << endl;
	}
}