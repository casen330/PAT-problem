//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<sstream>
//using namespace std;
//
//string intTostring(int n){
//	istringstream a(n);
//	string b;
//	a >> b;
//	return b;
//}
//string Trans(int n, int m){
//	string str;
//	while (n)
//	{
//		str += n%m + 48;
//		n = n / m;
//	}
//	return str;
//}
//
//int main(){
//	int n;
//	string str;
//	cin >> n >> str;
//	string subStr;
//	int temp;
//	for (int i = 2; i < 17; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			subStr += Trans(j, i);
//		}
//		size_t position;
//		position = subStr.find(str);
//		if (position!=string::npos)
//		{
//			cout << "yes" << endl;
//		}
//		else
//		{
//			cout << "no" << endl;
//		}
//	}
//	return 0;
//}