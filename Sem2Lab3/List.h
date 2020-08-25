#pragma once
#include<fstream>
#include"List.h"
#include"Used_function.h"
using namespace std;
struct List {
	char str[25];
	List* Next;
	List* Head;
	List* Tail;

	void push_back(char s[25]) {
		if (Head != NULL) {
			Tail->Next = new List;
			for (int i = 0; i < 25; ++i)
				Tail->Next->str[i] = s[i];
			Tail = Tail->Next;
			Tail->Next = NULL;
		}
		else {
			Head = new List;
			Tail = Head;
			Tail->Next = NULL;
			for (int i = 0; i < 25; ++i)
				Head->str[i] = s[i];
		}
	}
	void print(ofstream&out) {
		List* cur = Head;
		while (cur != NULL) {
			out << '|' << cur->str << '|' << "->" << endl;
			cur=cur->Next;
			if (cur->Next == NULL)
			{
				out << "X" << endl;
				break;
			}

		}

	}
	int process(int k) {
		List* cur = Head;
		List* cur1 = cur->Next;
		while (cur != NULL) {
			
			while (cur1 != NULL) {
				if (strcmp(cur->str, cur1->str)) {
				}
				cur1 = cur1->Next;
			}
			cur = cur->Next;
		}
		return k;
	}
};