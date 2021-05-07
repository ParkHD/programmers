#pragma once
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    vector<int> vec;                        
    // 크레인으로 뽑아서 넣을 바구니

    for (int j = 0; j < moves.size(); j++)
    {
        int locate = moves[j]-1;    // 크레인 위치
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][locate] != 0)  // 크레인은 인형이 있을 때까지 내려간다
            {
                if (vec.size() >0 && vec.back() == board[i][locate]) // 바구니에 값이 하나이상 있을때 뽑은 인형이 바구니에 있던 값과 같다면
                {
                    board[i][locate] = 0;
                    answer = answer + 2;
                    vec.pop_back();
                    break;
                }
                vec.push_back(board[i][locate]);                    // 바구니에 인형을 넣는다
                board[i][locate] = 0;
                break;
            }
        }
    }
    return answer;
}