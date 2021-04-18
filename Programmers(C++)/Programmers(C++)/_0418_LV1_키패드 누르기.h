#pragma once
#include <string>
#include <vector>
#include <cmath>
using namespace std;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int keyPad[4][3] =
    {   {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-1} };
    vector<int> lastLeftPos = { 3,0 };
    vector<int> lastRightPos = { 3,2 };
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (numbers[i] == keyPad[j][k])
                {
                    if (k == 0)
                    {
                        answer.push_back('L');
                        lastLeftPos[0] = j;
                        lastLeftPos[1] = k;
                        break;
                    }
                    if (k == 1)
                    {
                        if (abs(j - lastLeftPos[0]) + abs(k - lastLeftPos[1]) > abs(j - lastRightPos[0]) + abs(k - lastRightPos[1]))
                        {
                            answer.push_back('R');
                            lastRightPos[0] = j;
                            lastRightPos[1] = k;

                            break;
                        }
                        else if (abs(j - lastLeftPos[0]) + abs(k - lastLeftPos[1]) == abs(j - lastRightPos[0]) + abs(k - lastRightPos[1]))
                        {
                            if (hand == "right")
                            {
                                answer.push_back('R');
                                lastRightPos[0] = j;
                                lastRightPos[1] = k;
                                break;
                            }
                            else
                            {
                                answer.push_back('L');
                                lastLeftPos[0] = j;
                                lastLeftPos[1] = k;
                                break;
                            }
                        }
                        else
                        {
                            answer.push_back('L');
                            lastLeftPos[0] = j;
                            lastLeftPos[1] = k;
                            break;
                        }
                    }
                    if (k == 2)
                    {
                        answer.push_back('R');
                        lastRightPos[0] = j;
                        lastRightPos[1] = k;
                        break;
                    }
                }
            }
        }
    }
    return answer;
}
string solution1(vector<int> numbers, string hand) 
{
    string answer = "";
    vector<int> lastLeftPos = { 3,0 };
    vector<int> lastRightPos = { 3,2 };
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 3 == 1)
        {
            answer.push_back('L');
            lastLeftPos[0] = numbers[i] / 3;
            lastLeftPos[1] = 0;
        }
        else if (numbers[i] % 3 == 0 && numbers[i] != 0)
        {
            answer.push_back('R');
            lastRightPos[0] = numbers[i] / 3 - 1;
            lastRightPos[1] = 2;
        }
        else
        {
            int x = numbers[i] / 3;
            if (numbers[i] == 0)
                x = 3;
            int lDistance = abs(x - lastLeftPos[0]) + abs(1 - lastLeftPos[1]);
            int rDistance = abs(x - lastRightPos[0]) + abs(1 - lastRightPos[1]);
            
            if (rDistance > lDistance)
            {
                answer.push_back('L');
                lastLeftPos[0] = x;
                lastLeftPos[1] = 1;
            }
            else if(rDistance < lDistance)
            {
                answer.push_back('R');
                lastRightPos[0] = x;
                lastRightPos[1] = 1;
            }
            else
            {
                if (hand == "right")
                {
                    answer.push_back('R');
                    lastRightPos[0] = x;
                    lastRightPos[1] = 1;
                }
                else
                {
                    answer.push_back('L');
                    lastLeftPos[0] = x;
                    lastLeftPos[1] = 1;
                }
            }
        }
    }
    return answer;
}