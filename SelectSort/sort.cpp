#include<iostream>
using namespace std;

void selectSort(int n, int *a){
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i; j < n; j++)
		{
			if (a[j]<a[k])
			{
				k = j;
			}
		}
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}

int main(){
	int a[5] = { 1, 4, 6, 3, 4 };
	selectSort(5, a);
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}