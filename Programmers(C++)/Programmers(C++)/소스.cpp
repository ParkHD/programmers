#include "_0409_LV1_두개의 수의 합.h";
#include "_0409_LV1_크레인인형뽑기.h";

void Show(vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}
}
int main()
{
	vector<vector<int>> vec = 
	{   {0,0,0,0,0,1},
		{0,0,1,0,3,2},
		{0,2,5,0,1,3},
		{4,2,4,4,2,4},
		{3,5,1,3,1,5} 
	};
	vector<int> moves = { 1,5,3,6,1,2,6,4 };
	

	cout<< solution(vec, moves)<<endl;

}