#pragma once
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <fstream>

class File { 
	char * name;
	public:

		File(char * filename);

		File(const char * filename);

		void write(std::string content);

		std::string read();
};

void log(const char * str, std::string ext);

void log(const char * str);

#endif