#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
5397 - 키로거 (링크드 리스트)

창영이는 강산이의 비밀번호를 훔치기 위해서 강산이가 사용하는 컴퓨터에 키로거를 설치했다.
며칠을 기다린 끝에 창영이는 강산이가 비밀번호 창에 입력하는 글자를 얻어냈다.

키로거는 사용자가 키보드를 누른 명령을 모두 기록한다.
따라서, 강산이가 비밀번호를 입력할 때, 화살표나 백스페이스를 입력해도 정확한 비밀번호를 알아낼 수 있다.

강산이가 비밀번호 창에서 입력한 키가 주어졌을 때, 강산이의 비밀번호를 알아내는 프로그램을 작성하시오.


입력
첫째 줄에 테스트 케이스의 개수가 주어진다.
각 테스트 케이스는 한줄로 이루어져 있고, 강산이가 입력한 순서대로 길이가 L인 문자열이 주어진다.
(1 ≤ L의 길이 ≤ 1,000,000) 

강산이가 백스페이스를 입력했다면, '-'가 주어진다. 
이때 커서의 바로 앞에 글자가 존재한다면, 그 글자를 지운다. 
화살표의 입력은 '<'와 '>'로 주어진다. 이때는 커서의 위치를 움직일 수 있다면, 왼쪽 또는 오른쪽으로 1만큼 움직인다.
나머지 문자는 비밀번호의 일부이다. 물론, 나중에 백스페이스를 통해서 지울 수는 있다.
만약 커서의 위치가 줄의 마지막이 아니라면, 그 문자를 입력하고, 커서는 오른쪽으로 한 칸 이동한다.

*/

int main()
{
	int count = 0;
	cin >> count;

	list<string> password_list;
	for (int i = 0; i < count; ++i)
	{
		string s;
		cin >> s;

		list<char> password;

		auto iter = password.begin();
		for (int idx = 0; idx < s.size(); ++idx)
		{     
		//	if (s[idx] == '-')
		//	{
		//		if (iter != password.end())
		//		{
		//			iter = password.erase(iter); 
		//		}
		//	}
		//	else if (s[idx] == '<')
		//	{
		//		if (iter != password.end())
		//		{
		//			++iter;
		//		}
		//	}
		//	else if (s[idx] == '>')
		//	{
		//		if (iter != password.begin())
		//		{
		//			--iter;
		//		}
		//	}
		//	else
		//	{ 
		//		iter = password.insert(iter, s[idx]); 
		//	}
		//}
			if (s[idx] == '-')
			{
				if (iter != password.begin())
				{
					--iter;
					iter = password.erase(iter); 
				}
			}
			else if (s[idx] == '<')
			{
				if (iter != password.begin())
				{
					--iter;
				}
			}
			else if (s[idx] == '>')
			{
				if (iter != password.end())
				{
					++iter;
				}
			}
			else
			{ 
				iter = password.insert(iter, s[idx]); 
				++iter;
			}
		}

		string data;
		for (auto iter = password.begin(); iter != password.end(); ++iter)
		{
			data += *iter;
		}
		password_list.push_back(data);
	}

	for (auto  password : password_list)
	{
		cout << password << endl;
	} 
}