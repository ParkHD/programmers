#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    vector<int> vec;
    for (int i = 0; i < arr1.size(); i++)
    {
        vec.push_back(arr1[i] | arr2[i]);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        int x = vec[i];
        string s = "";
        for (int j = 0; j < n; j++)
        {
            //s = x % 2 == 0 ? " " : "#" + s;
            s.push_back(x % 2 == 0 ? ' ' : '#');
            x /= 2;
        }
        reverse(s.begin(), s.end()); //역순으로 재정렬
        answer.push_back(s);
    }
    return answer;
}
vector<string> solution1(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    vector<int> vec;
    for (int i = 0; i < arr1.size(); i++)
    {
        vec.push_back(arr1[i] | arr2[i]);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        int x = vec[i];
        string s = "";
        for (int j = 0; j < n; j++)
        {
            s = (x % 2 == 0 ? " " : "#") + s;
            x /= 2;
        }
        answer.push_back(s);
    }
    return answer;
}