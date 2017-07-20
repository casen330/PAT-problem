#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int val;
	Node *pNext;
};

//单向链表类
class LinkList{
public:
	LinkList(){
		head = new Node;
		head->val = 0;
		head->pNext = NULL;
	}
	~LinkList(){ delete head; }

	void CreateLinkList(int n); //创建链表
	void InsertNode(int position, int d); //在指定位置插入节点
	void TraverseLinkList(); //遍历
	bool IsEmpty(); //判断是否为空
	int GetLength(); //链表长度
	void DeleteNode(int position); //删除节点
	void DeleteLinkList(); //删除链表

private:
	Node *head;
};

void LinkList::CreateLinkList(int n)
{
	if (n < 0)
	{
		cout << "Error node count." << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp;
		ptemp = head;
		int i = n;
		while (n-->0)
		{
			pnew = new Node;
			cout << "输入第 " << i - n << " 个节点的值: ";
			cin >> pnew->val;
			pnew->pNext = NULL;
			ptemp->pNext = pnew;
			ptemp = pnew;
		}
	}
}

void LinkList::InsertNode(int position, int d)
{
	if (position<0 || position>GetLength() + 1)
	{
		cout << "Location error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew, *ptemp;
		ptemp = head;
		pnew = new Node;
		pnew->pNext = NULL;
		pnew->val = d;

		while (position-->1)
		{
			ptemp = ptemp->pNext;
		}
		pnew->pNext = ptemp->pNext;
		ptemp->pNext = pnew;
	}
}

void LinkList::TraverseLinkList()
{
	Node *ptemp = head->pNext;
	while (ptemp != NULL)
	{
		cout << ptemp->val << "	";
		ptemp = ptemp->pNext;
	}
	cout << endl;
}

bool LinkList::IsEmpty()
{
	if (head->pNext == NULL)
		return true;
	else
		return false;
}

int LinkList::GetLength()
{
	int length = 0;
	Node *ptemp = head;
	while (ptemp->pNext != NULL)
	{
		length++;
		ptemp = ptemp->pNext;
	}
	return length;
}

void LinkList::DeleteNode(int position)
{
	if (position<0 || position>GetLength())
	{
		cout << "Location error" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *ptemp, *pdelete;
		ptemp = head;
		while (position-- > 1)
			ptemp = ptemp->pNext;
		pdelete = ptemp->pNext;
		ptemp->pNext = pdelete->pNext;
		delete pdelete;
		pdelete = NULL;
	}
}

void LinkList::DeleteLinkList()
{
	Node *pdelete=head->pNext, *ptemp;
	while (pdelete!=NULL)
	{
		ptemp = pdelete->pNext;
		head->pNext = ptemp;
		delete pdelete;
		pdelete = ptemp;
	}
}


int main(){
	LinkList mylist;
	int position = 0, value = 0, n = 0;
	bool flag = false;

	cout << "输入需要创建单向链表的节点数：";
	cin >> n;
	mylist.CreateLinkList(n);

	cout << "打印链表：";
	mylist.TraverseLinkList();

	cout << "输入插入节点的位置和值：";
	cin >> position >> value;
	mylist.InsertNode(position, value);

	cout << "打印链表：";
	mylist.TraverseLinkList();

	cout << "输入要删除节点的位置：";
	cin >> position;
	mylist.DeleteNode(position);

	cout << "打印链表：";
	mylist.TraverseLinkList();

	mylist.DeleteLinkList();
	flag = mylist.IsEmpty();
	if (flag)
		cout << "删除成功" << endl;
	else
		cout << "删除失败" << endl;
	return 0;
}