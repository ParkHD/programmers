#include "_0409_LV1_두개의 수의 합.h";
//#include "_0409_LV1_크레인인형뽑기.h";
//#include <list>
//#include "_0410_LV1_완주하지 못한 선수.h"
//#include "_0410_LV1_신규아이디 추천.h"
//#include "_0412_LV1_모의고사.h"
//#include "_0412_LV1_K번째.h"
//#include "_0412_LV1_3진법 뒤집기.h"
//#include "_0412_LV1_체육복.h"
//#include "_0413_LV1_문자열 내 마음대로 정렬하기.h"
#include "_0418_LV1_키패드 누르기.h"
#include "_0418_LV1_최대공약수와 최소공배수.h"
void Show(vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}
}	
int i;

bool compare(char a, char b)
{
	return a>b;
}

//vector<string> solution(vector<string> strings, int n) {
//	i = n;
//	sort(strings.begin(), strings.end(), compare);
//	return strings;
//}

int main()
{
#pragma region k번째 예제
	//vector<int> array = { 1,2,3,4,5,7,8 };
	//vector<vector<int>> vec = { {2, 5, 3} ,{4, 4, 1},{2, 5, 3} ,{1, 7, 3} };

	//Show(solution(array, vec));
#pragma endregion
#pragma region 3진법 뒤집기
	//int x = 45;
	//
	//Show(Ternary(x));
	//cout<< solution(x)<<endl;
#pragma endregion
#pragma region 체육복
	//cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;
#pragma endregion
	//vector<int> vec = { 1,1,4,4,4,2,5,5,3 };
	//sort(vec.begin(), vec.end());
	//unique(vec.begin(), vec.end());
	////vec.erase(unique(vec.begin(), vec.end()),vec.end());
	//Show(vec);
	//cout << solution1(20);

	Show(solution(60, 48));

}
