#pragma once
#include <string>
#include <vector>
#include <numeric>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }
    answer /= arr.size();
    return answer;
}

double solution1(vector<int> arr) 
{
    double answer = accumulate(arr.begin(), arr.end(), 0);// ������ �μ��� �ʱⰪ����(answer�� Ÿ���� ���󰣴� longlong���̸� �������μ� 0LL)

    return answer / arr.size();
}
//<numeric> 