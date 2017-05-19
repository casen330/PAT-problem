//#include<fstream>
//#include<regex>
//#include<string>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	ifstream in("1.txt");
//	string filename;
//	string line;
//
//
//	string pattern("e*");
//	regex r(pattern);
//	smatch results;
//	if (in) // 有该文件
//	{
//		while (getline(in, line)) // line中不包括每行的换行符
//		{
//			if (regex_search(line,results,r))
//			{
//			
//				cout << results.str() <<" "<<endl;
//			}
//		}
//	}
//	else // 没有该文件
//	{
//		cout << "no such file" << endl;
//	}
//
//
//
//
//	return 0;
//}

#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main(){
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;
//	string test_str;
//	while (1)
//	{
//		cout << "Input a string, or q to quit." << endl;
//		cin >> test_str;
//		if (test_str=="q")
//		{
//			break;
//		}
//		if (regex_search(test_str, results, r))
//		{
//			cout << results.str() << endl;
//		}
//		else
//		{
//			cout << "not match" << endl;
//		}
//	}

regex re(pattern, regex::icase);
smatch results;
string line;
while (1)
{
	getline(cin, line);
	for (sregex_iterator it(line.begin(), line.end(), re), end_it; it != end_it; ++it)
	{
		cout << it->str() << endl;
	}
}
	return 0;
}

