#pragma once
#include<fstream>
#include"List.h"
using namespace std;
void InputDataFromFile(ifstream& file, List* list) {

	while (!file.eof()) {
		char str[25];
		file >> str;
		if(str[0]!='\0')
		list->push_back(str);
	}
	if (list->Head == NULL)
		throw exception("File is empty!");
}
