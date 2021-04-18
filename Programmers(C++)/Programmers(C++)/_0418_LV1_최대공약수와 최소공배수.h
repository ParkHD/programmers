#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int m) 
{
    int x = 1;
    int originN = n;
    int originM = m;
    vector<int> answer;
    if (m % n == 0)
    {
        answer.push_back(n);
        answer.push_back(m);
    }
    else
    {
        vector<int> vec;
        for (int i = 2; i< n; i++)
        {
            if (n % i == 0 && m % i == 0)
            {
                vec.push_back(i);
                n = n / i;
                m = m / i;
                i = 1;
            }
        }
        for (int i = 0; i < vec.size(); i++)
        {
            x *= vec[i];
        }
        answer.push_back(x);
        answer.push_back((originN * originM) / x);
    }
    return answer;
}
vector<int> solution1(int a, int b)
{
    if (a > b) 
    {
        int temp = a;
        a = b;
        b = temp;
    }

    vector<int> answer;

    for (int i = a; i > 0; i--) {
        if (((a % i) == 0) && ((b % i) == 0)) {
            answer.push_back(i);
            answer.push_back((a * b) / i);
            break;
        }
    }
    return answer;
}
int GCD(int a, int b)// a>b (유클리드 호제법)
{
    if (b == 0)
    {
        return a;
    }
    else
        return GCD(b, a % b);
}
vector<int> solution2(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    vector<int> answer;
    answer.push_back(GCD(a, b));
    answer.push_back(a * b / answer[0]);
    return answer;
}