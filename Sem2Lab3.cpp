#include <iostream>
#include<fstream>
#include"List.h"
#include"Used_function.h"
#include"Input.h"
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	List* list = new List;
	char temp;
	in >> temp;
	if (in.eof()) {
		cout << "Файл пуст" << endl;
		return -1;
	}
	InputDataFromFile(in, list);

		out << "Первоначальный список:\n";
		list->print(out);
		int k = 0;
		list->process(k);
		if (k>0)
			out << "Есть два повторяющихся элемента";
		else
			out << "Нет двух повторяющихся элемента";
		cout << "Работа программы завершена" << endl;
	
}
