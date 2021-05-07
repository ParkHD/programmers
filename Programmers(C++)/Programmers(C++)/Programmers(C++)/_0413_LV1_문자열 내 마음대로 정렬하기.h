#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) 
{
    
    for (int i = 0; i < strings.size(); i++)
    {
        strings[i] = strings[i][n] + strings[i];
    }
    sort(strings.begin(), strings.end());
    for (int i = 0; i < strings.size(); i++)
    {
        strings[i].erase(strings[i].begin());
    }
    return strings;
}

int i;

bool compare(string a, string b)
{
    return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution1(vector<string> strings, int n)
{
    i = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}