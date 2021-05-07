#pragma once
#include <iostream>

using namespace std;

void solution(int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void solution1(int a, int b)
{
    string s;
    for (int i = 0; i < a; i++)
    {
        s += "*";
    }
    for (int i = 0; i < b; i++)
    {
        cout << s << endl;
    }
}