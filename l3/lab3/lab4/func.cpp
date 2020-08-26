#include <iostream>
#include <fstream>
#include "func.h"

using namespace std;



int massive_filling2(Strm* M)
{
	ifstream input("input2.txt");
	if (input.is_open() == 0)
	{
		cout << "Îרטבךא ןנט נאבמעו ס פאיכמל input2.txt"<<endl;
		return -1;
	}
	input.unsetf(ios::skipws);
	input.seekg(M->P);
	for (int i = 0; i < M->N; i++)
	{
		input >> M->A[i];
		if ((M->A[i] == '\n') || (input.eof() == 1))
		{
			M->A[i] = M->M;
			break;
		}
	}
	input.close();
	return 0;
}

int file_reading2(Strm* M, int i)
{
	ifstream input("input2.txt");
	if (input.is_open() == 0)
	{
		cout << "Îרטבךא ןנט נאבמעו ס פאיכמל input2.txt"<<endl;
		return -1;
	}
	input.unsetf(ios::skipws);
	char temp;
	M->N = 0;
	int k = 1;
	int j;
	if (i == 1)
		M->P = 0;
	else
	{
		for (j = 0; input.eof() != 1; j++)
		{
			input >> temp;
			if (temp == '\n')
				k++;
			if (k == i)
			{
				M->P = input.tellg();
				break;
			}
		}
	}
	for (j = 0;input.eof() != 1; j++)
	{
		input >> temp;
		M->N++;
		if (input.eof() == 1)
			break;
		if (temp == '\n')
			break;
	}
	input.close();
	return 0;
}

int massive_filling1(Strm* M)
{
	ifstream input("input1.txt");
	if (input.is_open() == 0)
	{
		cout << "Îרטבךא ןנט נאבמעו ס פאיכמל input1.txt"<<endl;
		return -1;
	}
	input.unsetf(ios::skipws);
	input.seekg(M->P);
	for (int i = 0; i < M->N; i++)
	{
		input >> M->A[i];
		if ((M->A[i] == '\n') || (input.eof() == 1))
		{
			M->A[i] = M->M;
			break;
		}
	}
	input.close();
	return 0;
}

int file_reading1(Strm* M, int i)
{
	ifstream input("input1.txt");
	if (input.is_open() == 0)
	{
		cout << "Îרטבךא ןנט נאבמעו ס פאיכמל input1.txt"<<endl;
		return -1;
	}
	input.unsetf(ios::skipws);
	char temp;
	M->N = 0;
	int k = 1;
	int j;
	if (i == 1)
		M->P = 0;
	else
	{
		for (j = 0; input.eof() != 1; j++)
		{
			input >> temp;
			if (temp == '\n')
				k++;
			if (k == i)
			{
				M->P = input.tellg();
				break;
			}
		}
	}
	for (j = 0;input.eof() != 1; j++)
	{
		input >> temp;
		M->N++;
		if (input.eof() == 1)
			break;
		if (temp == '\n')
			break;
	}
	input.close();
	return 0;
}

int string_working(Strm* M, int i, int key)
{
	if (key == 1)
	{
		if (file_reading1(M, i) == -1)
			return -1;
		M->A = new char[M->N];
		if (massive_filling1(M) == -1)
			return -2;
	}
	else
	{
		if (file_reading2(M, i) == -1)
			return -1;
		M->A = new char[M->N];
		if (massive_filling2(M) == -1)
			return -2;
	}
	return 0;
}

int str_count2()
{
	ifstream input("input2.txt");
	if (input.is_open() == 0)
	{
		cout << "Îרטבךא ןנט נאבמעו ס פאיכמל input2.txt"<<endl;
		return -1;
	}
	input.unsetf(ios::skipws);
	char temp;
	int count = 1;
	for (int i = 0;input.eof() != 1; i++)
	{
		input >> temp;
		if (input.eof() == 1)
		{
			if (i == 0)
			{
				cout << "Ôאיכ input1.txt ןףסע"<<endl;
				return -1;
			}
			break;
		}
		if (temp == '\n')
			count++;
	}
	input.close();
	return count;
}

int str_count1()
{
    ifstream input("input1.txt");
    if (input.is_open() == 0)
    {
        cout << "Îרטבךא ןנט נאבמעו ס פאיכמל input.txt"<<endl;
        return -1;
    }
    input.unsetf(ios::skipws);
    char temp;
    int count = 1;
    for (int i = 0;input.eof() != 1; i++)
    {
        input >> temp;
        if (input.eof() == 1)
        {
            if (i == 0)
            {
                cout << "Ôאיכ input1.txt ןףסע"<<endl;
                return -1;
            }
            break;
        }
        if (temp == '\n')
            count++;
    }
    input.close();
    return count;
}