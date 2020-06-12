/*
2983 - 개구리 공주 (링크드 리스트)

문제
트럭을 타고 이동하던 중에 상근이는 휴식을 취하기 위해서 호수에 잠시 들렸다. 
호수에는 개구리가 살고 있고, 개구리는 호수 위에 떠있는 식물 N개를 점프하면서 다닌다. 
오래된 전설에 따르면 개구리에게 키스를 하면 개구리는 아름다운 공주로 변한다고 한다. 
일단 개구리를 잡아야 전설이 사실인지 아닌지 확인할 수 있다. 개구리를 잡아보자.

호수는 2차원 평면으로 생각할 수 있고, 식물은 그 평면 위의 점으로 나타낼 수 있다.
(x, y)위에 있는 개구리는 아래 네 가지 방향 중 한 방향으로 점프할 수 있다.

임의의 양의 정수 P에 대해서, (x+P, y+P)로 점프할 수 있다. 이 방향을 A라고 한다.
임의의 양의 정수 P에 대해서, (x+P, y-P)로 점프할 수 있다. 이 방향을 B라고 한다.
임의의 양의 정수 P에 대해서, (x-P, y+P)로 점프할 수 있다. 이 방향을 C라고 한다.
임의의 양의 정수 P에 대해서, (x-P, y-P)로 점프할 수 있다. 이 방향을 D라고 한다.
개구리는 네 방향 중 한 방향을 고른다. 

그 다음 그 방향에 있는 가장 가까운 식물로 점프를 한다. 
만약, 고른 방향에 식물이 없다면, 개구리는 그 위치에 그대로 있는다. 
개구리가 점프를 하고 난 이후에, 원래 있던 식물은 호수로 가라앉게되고 사라진다.

상근이는 식물의 위치와 개구리가 고른 방향을 모두 알고 있다. 
상근이는 개구리의 점프가 끝나는 꽃의 좌표를 알아낸 다음, 거기서 개구리를 잡으려고 한다.

개구리의 점프가 끝나는 식물의 위치는 어디일까?


입력
첫째 줄에 식물의 수 N과 점프의 수 K가 주어진다. (1 ≤ N, K ≤ 100,000)

둘째 줄에는 개구리가 고른 방향 K개가 주어진다. 이 방향은 'A','B','C','D'로만 이루어져 있다.

셋째 줄부터 N개 줄에는 식물의 좌표가 X, Y가 주어진다. (0 ≤ X, Y ≤ 1,000,000,000) 처음으로 주어지는 식물에 개구리가 있다.


출력
개구리의 점프가 끝나는 식물의 좌표를 출력한다.
*/


#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct POINT
{
	int x;
	int y;

	POINT(int _x = -1, int _y = -1) :x(_x), y(_y) {};

	bool operator== (const POINT& other) const
	{
		return (x == other.x) && (y == other.y);
	} 
};
 

// 식물의 위치
list<POINT> plantPosition;

// 개구리가 이미 점프한 위치정보들
list<POINT> jumpPosition;

bool FindCorrect(POINT curr, POINT& next, char c)
{
	switch (c)
	{
	case 'A':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px > 0 && Py > 0 && Px == Py)
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;

	case 'B':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px > 0 && Py < 0 && Px == abs(Py))
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;

	case 'C':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px < 0 && Py > 0 && abs(Px) == Py)
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;

	case 'D':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px < 0 && Py < 0 && Px == Py)
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;
	default:
		break;
	}

	return false;
}
int main()
{
	int N = 0;
	int K = 0;
	cin >> N >> K; // 식물 n개 수와 개구리가 고른 방향 k개
	
	// 개구리 점프 방향 구하기
	vector<char> frogJump;
	frogJump.reserve(K);
	
	string s;
	cin >> s;
	for (int i = 0; i < K; ++i)
	{
		frogJump.push_back(s[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		plantPosition.emplace_back(x, y);
	} 

	// 현재 위치
	POINT currPos = plantPosition.front();
	for (int i = 0; i < K; ++i)
	{
		// 해당 점프에 해당되는 위치를 찾는다.
		POINT next;
		char jump = frogJump[i];
		cout << currPos.x << "," << currPos.y << endl;
		bool isJump = FindCorrect(currPos, next, jump);
		if (!isJump)
		{ 
			break;
		} 

		// 현재 위치 정보 추가.
		jumpPosition.emplace_back(currPos.x, currPos.y);

		// 이동한 현재 위치 삭제.
		plantPosition.remove(currPos);

		currPos = next;
	}

	cout << currPos.x << " " << currPos.y << endl;
}
