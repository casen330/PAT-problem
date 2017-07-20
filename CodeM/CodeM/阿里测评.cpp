#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<math.h>
#include<set>
using namespace std;
// 请完成下面这个函数，实现题目要求的功能
// 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^
int result(vector <int>& inputs) {
	set<int> A, B, D;

	for (vector<int>::iterator iter1 = inputs.begin(); iter1 != inputs.end(); iter1++)
	{
		for (vector<int>::iterator iter2 = inputs.begin(); iter2 != inputs.end(); iter2++)
		{
			if (iter1 == iter2)
			{
				continue;
			}
			A.insert((*iter1) + (*iter2));
			B.insert(abs((*iter1) - (*iter2)));
		}
	}

	set<int>::iterator iterA1 = A.begin();
	set<int>::iterator iterB1 = B.begin();
	int d1 = abs((*iterA1) - (*iterB1));
	int d2 = abs((*iterA1) - (*iterB1));
	int s = 0;
	for (set<int>::iterator iterA = A.begin(); iterA != A.end(); iterA++)
	{
		for (set<int>::iterator iterB = B.begin(); iterB != B.end(); iterB++)
		{
			{
				D.insert(abs((*iterA) - (*iterB)));
				if ((abs((*iterA) - (*iterB))) < d1)
					d1 = (abs((*iterA) - (*iterB)));
				if ((abs((*iterA) - (*iterB)))>d2)
					d2 = (abs((*iterA) - (*iterB)));
			}
		}
	}
	s = D.size();
	return d1 + d2 + s;
}

int main() {
	int size = 0;
	cin >> size;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	vector<int> points;
	for (size_t i = 0; i<size; ++i) {
		int item;
		cin >> item;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		points.push_back(item);
	}
	int res = result(points);
	cout << res << endl;
	return 0;
}