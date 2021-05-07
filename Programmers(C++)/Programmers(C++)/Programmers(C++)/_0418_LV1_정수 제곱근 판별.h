#pragma once
#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) 
{
    int x = pow(n, 0.5);
    for (int i = x; pow(i, 2) <= n; i++)
    {
        if (pow(i,2) == n)
            return pow(i+1,2);
    }
    return -1;
}
long long solution1(long long n)
{
    int x = pow(n, 0.5);
    long long answer = pow(x, 2) == n ? pow(x + 1, 2) : -1;
    return answer;
}