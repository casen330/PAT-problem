#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){
	signed int a, b;
	cin >> a >> b;
	signed int sum;
	sum = a + b;
	stringstream output;
	output << sum; 
	string s_result = output.str();
	vector<char> str;
	for (int i = 0; i < s_result.length(); i++)
	{		
		str.push_back(s_result[i]);
	}	
	for (vector<char>::iterator iter = str.end()-3; iter <=str.begin()+3 ; iter=iter-3)
	{
		str.insert(iter,',');
	}
	for (vector<char>::iterator iter = str.begin(); iter <= str.end(); iter++)
	{
		cout << *iter;
	}
	system("pause");
	return 0;
}