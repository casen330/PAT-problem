#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
	int data;
	Node *pNext;
};

//单项循环链表
class CircularLinkList{
public:
	CircularLinkList(){
		head = new Node;
		head->data = 0;
		head->pNext = NULL;
	}
	~CircularLinkList(){
		delete head;
	}
	void CreateLinkList(int n);
	void InsertNode(int position, int d);
	void TraverseLinkList();
	bool IsEmpty();
	int  GetLength();
	void DeleteNode(int position);
	void DeleteLinkList();
private:
	Node *head;
};

void CircularLinkList::CreateLinkList(int n)
{
	if (n < 0)
	{
		cout << "Link length error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp=head;
		int i = n;
		while (n-->0)
		{
			cout << "请输入第： " << i - n << "个节点的值: ";
			pnew = new Node;
			cin >> pnew->data;
			pnew->pNext = head;
			ptemp->pNext = pnew;
			ptemp = pnew;
		}
	}
}
void CircularLinkList::InsertNode(int position, int d)
{
	if (position<0 || position>GetLength() + 1)
	{
		cout << "Position error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp = head;
		pnew = new Node;
		pnew->data = d;
		while (position-->1)
		{
			ptemp = ptemp->pNext;
		}
		pnew->pNext = ptemp->pNext;
		ptemp->pNext = pnew;
	}
}
void CircularLinkList::TraverseLinkList()
{
	Node *ptemp = head->pNext;
	while (ptemp!=head)
	{
		cout << ptemp->data << " ";
		ptemp = ptemp->pNext;
	}
	cout << endl;
}
bool CircularLinkList::IsEmpty()
{
	if (head->pNext==head)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int  CircularLinkList::GetLength()
{
	int length = 0;
	Node *ptemp = head->pNext;
	while (ptemp!=head)
	{
		length++;
		ptemp = ptemp->pNext;
	}
	return length;
}
void CircularLinkList::DeleteNode(int position)
{
	if (position<0 ||position>GetLength())
	{
		cout << "position error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pdelete, *ptemp = head;
		while (position-->1)
		{
			ptemp = ptemp->pNext;
		}
		pdelete = ptemp->pNext;
		ptemp->pNext = pdelete->pNext;
		delete pdelete;
		pdelete = NULL;
	}
}
void CircularLinkList::DeleteLinkList()
{
	Node *ptemp, *pdelete = head->pNext;
	while (pdelete!=head)
	{
		ptemp = pdelete->pNext;
		head->pNext = ptemp;
		delete pdelete;
		pdelete = ptemp;
	}
}

int main(){
	CircularLinkList cl;
	int position = 0, value = 0, n = 0;
	bool flag = false;

	cout << "请输入需要创建单向循环链表的结点个数：";
	cin >> n;
	cl.CreateLinkList(n);

	cout << "打印链表值如下：";
	cl.TraverseLinkList();

	cout << "请输入插入结点的位置和值：";
	cin >> position >> value;
	cl.InsertNode(position, value);

	cout << "打印链表值如下：";
	cl.TraverseLinkList();

	cout << "请输入要删除结点的位置：";
	cin >> position;
	cl.DeleteNode(position);

	cout << "打印链表值如下：";
	cl.TraverseLinkList();

	cl.DeleteLinkList();
	flag = cl.IsEmpty();
	if (flag)
		cout << "删除链表成功！" << endl;
	else
		cout << "删除链表失败！" << endl;
	system("pause");
	return 0;
}