#include <fstream>
#include <iostream>
#include "func.h"
#include "ElemL1.h"

using namespace std;

int out(ElemL1* L, int key)
{
    ofstream out("out.txt", ios::app);
    if (out.is_open() == 0)
    {
        cout << "Ошибка при работе с файлом out.txt"<<endl;
        return 0;
    }
    out << "Результат:"<<endl;
    int t = 1;
    int i;
    ElemL1* Cur;
    if (key == 0)
        Cur = &L[0];
    else
        Cur = &L[1];
    while (t != 0)
    {
        out << "|";
        for (i = 0;Cur->M.A[i] != Cur->M.M;i++)
        {
            if (Cur->M.A[i] == Cur->M.M)
                break;
            out << Cur->M.A[i];
        }
        out << "|\n->";
        if (Cur->next == NULL)
        {
            out << "X"<<endl;
            t--;
            break;
        }
        Cur = Cur->next;
    }
    out.close();
    return 0;
}

bool issame(ElemL1* L1, ElemL1* L2)
{
    int t = 0;
    for (int i = 0;t!=1;i++)
    {
        if (L1->M.A[i] == L1->M.M)
            t++;
        if (L1->M.A[i] != L2->M.A[i])
            return false;
    }
    return true;
}

int process(ElemL1* L1, ElemL1* L2)
{
    ElemL1* key = &L2[0];
    ElemL1* include = &L2[1];
    ElemL1* head = &L1[0];
    int k = 0;
    ElemL1* prev = NULL;
    ElemL1* cur = &L1[0];
    while (cur != NULL)
    {
        if (issame(cur, key))
        {
            if (prev != NULL)
            {
                prev->next = include;
                include->next = cur->next;
            }
            else
            {
                k++;
                head = include;
                include->next = cur->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    return k;
}

int control_out(ElemL1* L)
{
    ofstream out("out.txt");
    if (out.is_open() == 0)
    {
        cout << "Ошибка при работе с файлом out.txt"<<endl;
        return -1;
    }
    out << "Для текста:"<<endl;
    int t = 1;
    int i;
    ElemL1* Cur = &L[0];
    while (t != 0)
    {
        out << "|";
        for (i = 0;Cur->M.A[i] != Cur->M.M;i++)
        {
            if (Cur->M.A[i] == Cur->M.M)
                break;
            out << Cur->M.A[i];
        }
        out << "|\n->";
        if (Cur->next == NULL)
        {
            out << "X"<<endl;
            t--;
            break;
        }
        Cur = Cur->next;
    }
    out.close();
    return 0;
}

int strings_del(ElemL1* L, int i)
{
    if (i == 0)
        return 0;
    int j;
    for (j = 0;j < i;j++)
    {
        delete[]L[j].M.A;
    }
    return 0;
}

int input_text(ElemL1* L, int N, int key)
{
    int i, code, j;
    Strm* Cur;
    for (i = 0;i < N;i++)
    {
        Cur = &L[i].M;
        j = i + 1;
        code = string_working(Cur, j, key);
        if (code < 0)
        {
            int del_code;
            if (code == -2)
                del_code = i + 1;
            else
                del_code = i;
            strings_del(L, del_code);
            return -1;
        }
        if (i == N - 1)
            L[i].next = NULL;
        else
            L[i].next = &L[i + 1];
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
	cout << "Автор: Корягин Е.А. гр.9309" << endl;
	cout << "Программа ищет первый по порядку подходящий элемент списка и заменяет его" << endl;
    int N = str_count1();
    if (N <= 0)
        return -1;
    ElemL1* L1 = new ElemL1[N];
    int N2 = str_count2();
    if (N2 != 2)
    {
		cout << "Некорректные данные в файле input2.txt" << endl;;
        return -1;
    }
    ElemL1* L2 = new ElemL1[N2];
    if (input_text(L1, N, 1) != 0)
        return -1;
    if (input_text(L2, N2, 2) != 0)
        return -1;
    if (control_out(L1) != 0)
        return -1;
    int k = process(L1, L2);
    if (k == 0)
        out(L1, k);
    else
        out(L2, k);
    strings_del(L1, N);
    strings_del(L2, N2);
    delete[] L1;
    delete[] L2;
	cout << "Работа программы завершена" << endl;
}
