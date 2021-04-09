#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    vector<int> vec;
    //moves�� ���������Ѵ�
    //���� ���� �ö󰣴� 0�� �ȳ��Ë�����

    for (int j = 0; j < moves.size(); j++)
    {
        int locate = moves[j]-1;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][locate] != 0)
            {
                if (vec.size() >0 && vec.back() == board[i][locate])
                {
                    board[i][locate] = 0;
                    answer = answer + 2;
                    vec.pop_back();
                    break;
                }
                vec.push_back(board[i][locate]);
                board[i][locate] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << i<<" : "<<vec[i] << endl;
    }
    return answer;
}