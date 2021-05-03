#pragma once
#include<algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(string expression)
{
    vector<long long> toNum;
    vector<long long> numbers;
    vector<char> operate;
    vector<long long> answers;
    vector<string> sequence =
    {
        "+-*","+*-","-+*","*+-","-*+","*-+",
    };
    for (int i = 0; i < expression.size(); i++)
    {
        bool isal = isdigit(expression[i]);
        if (isal)
        {
            toNum.push_back(expression[i] - '0');
            if (i == expression.size() - 1)
            {
                long long number = 0;
                for (int j = 0; j < toNum.size(); j++)
                {
                    number += toNum[j] * pow(10, toNum.size() - j - 1);
                }
                numbers.push_back(number);
                toNum.clear();
            }
        }
        else
        {
            long long number = 0;
            for (int j = 0; j < toNum.size(); j++)
            {
                number += toNum[j] * pow(10, toNum.size() - j - 1);
            }
            numbers.push_back(number);
            toNum.clear();

            operate.push_back(expression[i]);
        }
    }
    for (int i = 0; i < sequence.size(); i++)               // i = 경우의수 
    {
        vector<long long> vNumbers = numbers;
        vector<char> vOperate = operate;
        for (int j = 0; j < sequence[i].size(); j++)        // j = 연산자 우선순위
        {
            for (int k = 0; k < vOperate.size(); k++)        // k = 입력받은 연산자들 개수
            {
                if ((sequence[i])[j] == vOperate[k])
                {
                    long long number;
                    switch (vOperate[k])
                    {
                    case '+':
                        number = vNumbers[k] + vNumbers[k + 1];
                        break;
                    case'*':
                        number = vNumbers[k] * vNumbers[k + 1];
                        break;
                    case '-':
                        number = vNumbers[k] - vNumbers[k + 1];
                        break;
                    }
                    vNumbers.erase(vNumbers.begin() + k, vNumbers.begin() + k + 2);
                    vNumbers.insert(vNumbers.begin() + k, number);

                    vOperate.erase(vOperate.begin() + k);
                    k = -1;
                    if (vNumbers.size() == 1)
                    {
                        answers.push_back(abs(number));
                        break;
                    }
                }
            }
        }
    }
    long long answer = *max_element(answers.begin(), answers.end());;
    return answer;
}