#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *pPre, *pNext;
};

class DoubleCircularLinkList{
public:
	DoubleCircularLinkList(){
		head = new Node;
		head->data = 0;
		head->pNext = NULL;
		head->pPre = NULL;
	}
	~DoubleCircularLinkList(){ delete head; }
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

void DoubleCircularLinkList::CreateLinkList(int n)
{
	if (n<0)
	{
		cout << "length error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp = head;
	
		int i = n;
		while (n-->0)
		{
			pnew = new Node;
			cout << "input " << i - n << "th number: ";
			cin >> pnew->data;
			ptemp->pNext = pnew;
			pnew->pNext = head;
			pnew->pPre = ptemp;
			ptemp = pnew;
		}
	}
}
void DoubleCircularLinkList::InsertNode(int position, int d)
{
	if (position<0 || position>GetLength()+1)
	{
		cout << "position error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp = head;
		pnew = new Node;
		pnew->data = d;
		while (position-->1)
		{
			ptemp=ptemp->pNext;
		}
		pnew->pNext = ptemp->pNext;
		if (ptemp->pNext!=head)
		{
			ptemp->pNext->pPre = pnew;
		}
		ptemp->pNext = pnew;
		pnew->pPre = ptemp;		
	}
}
void DoubleCircularLinkList::TraverseLinkList()
{
	Node *ptemp = head->pNext;
	while (ptemp!=head)
	{
		cout << ptemp->data << " ";
		ptemp = ptemp->pNext;
	}
	cout << endl;
}
bool DoubleCircularLinkList::IsEmpty()
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
int  DoubleCircularLinkList::GetLength()
{
	int length = 0;
	Node *ptemp = head->pNext;
	while (ptemp != head)
	{
		length++;
		ptemp = ptemp->pNext;
	}
	return length;
}
void DoubleCircularLinkList::DeleteNode(int position)
{
	if (position<0 || position>GetLength())
	{
		cout << "position error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pdelete, *temp = head;
		while (position-->1)
		{
			temp = temp->pNext;
		}
		pdelete = temp->pNext;
		temp->pNext = pdelete->pNext;
		if (pdelete->pNext!=head)
		{
			pdelete->pNext->pPre = temp;
		}
		delete pdelete;
		pdelete = NULL;
	}
}
void DoubleCircularLinkList::DeleteLinkList()
{
	Node *ptemp, *pdelete = head->pNext;
	while (pdelete!=head)
	{
		ptemp = pdelete->pNext;
		head->pNext = ptemp;
		ptemp->pPre = head;
		delete pdelete;
		pdelete = ptemp;
	}
}

int main() {
	DoubleCircularLinkList dcl;
	int position = 0, value = 0, n = 0;
	bool flag = false;

	cout << "请输入需要创建双向循环链表的结点个数：";
	cin >> n;
	dcl.CreateLinkList(n);

	cout << "打印链表值如下：";
	dcl.TraverseLinkList();

	cout << "请输入插入结点的位置和值：";
	cin >> position >> value;
	dcl.InsertNode(position, value);

	cout << "打印链表值如下：";
	dcl.TraverseLinkList();

	cout << "请输入要删除结点的位置：";
	cin >> position;
	dcl.DeleteNode(position);

	cout << "打印链表值如下：";
	dcl.TraverseLinkList();

	dcl.DeleteLinkList();
	flag = dcl.IsEmpty();
	if (flag)
		cout << "删除链表成功！" << endl;
	else
		cout << "删除链表失败！" << endl;
	system("pause");
	return 0;
}