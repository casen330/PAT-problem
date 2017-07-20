#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
	int data;
	Node *pPre, *pNext;
};

class DoubleLinkList{
public:
	DoubleLinkList(){
		head = new Node;
		head->data = 0;
		head->pNext = NULL;
		head->pPre = NULL;
	}
	~DoubleLinkList(){ delete head; }
	void CreateLinkList(int n);
	void InsertNode(int position, int d);
	void TraverseLinkList();
	bool IsEmpty();
	int GetLength();
	void DeleteNode(int position);
	void DeleteLinkList();
private:
	Node *head;
};

void DoubleLinkList::CreateLinkList(int n)
{
	if (n<0)
	{
		cout << "lenght error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp = head;
		int i = n;
		while (n-->0)
		{
			cout << "input the " << i - n << "th number ";
			pnew = new Node;
			cin >> pnew->data;
			pnew->pNext = NULL;
			pnew->pPre = ptemp;
			ptemp->pNext = pnew;
			ptemp = pnew;
		}
	}
}
void DoubleLinkList::InsertNode(int position, int d)
{
	if (position<0 || position>GetLength()+1)
	{
		cout << "position error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp = head;
		while (position-->1)
		{
			ptemp = ptemp->pNext;
		}
		pnew = new Node;
		pnew->data = d;
		pnew->pNext = ptemp->pNext;
		ptemp->pNext = pnew;
		pnew->pPre = ptemp;
		if (ptemp->pNext!=NULL)
			ptemp->pNext->pPre = pnew;
	}
}
void DoubleLinkList::TraverseLinkList()
{
	Node *ptemp = head->pNext;
	while (ptemp!=NULL)
	{
		cout << ptemp->data << " ";
		ptemp = ptemp->pNext;
	}
	cout << endl;
}
bool DoubleLinkList::IsEmpty()
{
	if (head->pNext==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int  DoubleLinkList::GetLength()
{
	int length = 0;
	Node *ptemp = head->pNext;
	while (ptemp != NULL)
	{
		length++;
		ptemp = ptemp->pNext;
	}
	return length;
}
void DoubleLinkList::DeleteNode(int position)
{
	if (position<0 || position>GetLength())
	{
		cout << "position error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *ptemp=head, *pdelete;
		while (position-->1)
		{
			ptemp = ptemp->pNext;
		}
		pdelete = ptemp->pNext;
		ptemp->pNext = pdelete->pNext;
		if (pdelete->pNext!=NULL)
		{
			pdelete->pNext->pPre = ptemp;
		}
		delete pdelete;
		pdelete = NULL;
	}
}
void DoubleLinkList::DeleteLinkList()
{
	Node *pdelete = head->pNext, *ptemp;
	while (pdelete != NULL)
	{
		ptemp = pdelete->pNext;
		head->pNext = ptemp;
		if (ptemp!=NULL)
		{
			ptemp->pPre = head;
		}
		delete pdelete;
		pdelete = ptemp; 
	}
}

int main(){

	DoubleLinkList dl;
	int position = 0, value = 0, n = 0;
	bool flag = false;

	cout << "请输入需要创建双向链表的结点个数：";
	cin >> n;
	dl.CreateLinkList(n);

	cout << "打印链表值如下：";
	dl.TraverseLinkList();

	cout << "请输入插入结点的位置和值：";
	cin >> position >> value;
	dl.InsertNode(position, value);

	cout << "打印链表值如下：";
	dl.TraverseLinkList();

	cout << "请输入要删除结点的位置：";
	cin >> position;
	dl.DeleteNode(position);

	cout << "打印链表值如下：";
	dl.TraverseLinkList();

	dl.DeleteLinkList();
	flag = dl.IsEmpty();
	if (flag)
		cout << "删除链表成功！" << endl;
	else
		cout << "删除链表失败！" << endl;

	system("pause");
	return 0;
}