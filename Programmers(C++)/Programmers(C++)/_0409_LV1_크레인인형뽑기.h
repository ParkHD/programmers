#pragma once
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    vector<int> vec;                        
    // ũ�������� �̾Ƽ� ���� �ٱ���

    for (int j = 0; j < moves.size(); j++)
    {
        int locate = moves[j]-1;    // ũ���� ��ġ
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][locate] != 0)  // ũ������ ������ ���� ������ ��������
            {
                if (vec.size() >0 && vec.back() == board[i][locate]) // �ٱ��Ͽ� ���� �ϳ��̻� ������ ���� ������ �ٱ��Ͽ� �ִ� ���� ���ٸ�
                {
                    board[i][locate] = 0;
                    answer = answer + 2;
                    vec.pop_back();
                    break;
                }
                vec.push_back(board[i][locate]);                    // �ٱ��Ͽ� ������ �ִ´�
                board[i][locate] = 0;
                break;
            }
        }
    }
    return answer;
}