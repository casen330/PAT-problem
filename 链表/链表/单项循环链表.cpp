#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
	int data;
	Node *pNext;
};

//����ѭ������
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
			cout << "������ڣ� " << i - n << "���ڵ��ֵ: ";
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

	cout << "��������Ҫ��������ѭ������Ľ�������";
	cin >> n;
	cl.CreateLinkList(n);

	cout << "��ӡ����ֵ���£�";
	cl.TraverseLinkList();

	cout << "������������λ�ú�ֵ��";
	cin >> position >> value;
	cl.InsertNode(position, value);

	cout << "��ӡ����ֵ���£�";
	cl.TraverseLinkList();

	cout << "������Ҫɾ������λ�ã�";
	cin >> position;
	cl.DeleteNode(position);

	cout << "��ӡ����ֵ���£�";
	cl.TraverseLinkList();

	cl.DeleteLinkList();
	flag = cl.IsEmpty();
	if (flag)
		cout << "ɾ������ɹ���" << endl;
	else
		cout << "ɾ������ʧ�ܣ�" << endl;
	system("pause");
	return 0;
}