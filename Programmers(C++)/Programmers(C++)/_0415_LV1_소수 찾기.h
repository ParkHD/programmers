#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    bool value = true;
    vector<int> vec;

    vector<int> vec2;
    int size = vec.size();
    for (int i = 2; i <= n; i++)
    {
        value = true;
        for (int x = 0; x < size; x++)
        {
            if (i % vec[x] == 0)
            {
                value = false;
                break;
            }

        }
        if (value)
        {
            int count = 1;
            for (int j = 2; j <= i/2; j++)
            {
                if (i % j == 0)
                    count++;
                if (count > 1)
                    break;
            }
            if (count == 1)
            {
                vec.push_back(i);
                size++;
                answer++;
            }
        }
        
    }
    return answer;
}
int solution1(int n) 
{
    int answer = 0;
    vector<int> vec;
    vec.assign(n+1, 0);

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; i*j <= n; j++)
        {
            vec[i * j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (vec[i] == 0)
        {
            answer++;
        }
    }
    return answer;
}