#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int val;
	Node *pNext;
};

//����������
class LinkList{
public:
	LinkList(){
		head = new Node;
		head->val = 0;
		head->pNext = NULL;
	}
	~LinkList(){ delete head; }

	void CreateLinkList(int n); //��������
	void InsertNode(int position, int d); //��ָ��λ�ò���ڵ�
	void TraverseLinkList(); //����
	bool IsEmpty(); //�ж��Ƿ�Ϊ��
	int GetLength(); //������
	void DeleteNode(int position); //ɾ���ڵ�
	void DeleteLinkList(); //ɾ������

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
			cout << "����� " << i - n << " ���ڵ��ֵ: ";
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

	cout << "������Ҫ������������Ľڵ�����";
	cin >> n;
	mylist.CreateLinkList(n);

	cout << "��ӡ����";
	mylist.TraverseLinkList();

	cout << "�������ڵ��λ�ú�ֵ��";
	cin >> position >> value;
	mylist.InsertNode(position, value);

	cout << "��ӡ����";
	mylist.TraverseLinkList();

	cout << "����Ҫɾ���ڵ��λ�ã�";
	cin >> position;
	mylist.DeleteNode(position);

	cout << "��ӡ����";
	mylist.TraverseLinkList();

	mylist.DeleteLinkList();
	flag = mylist.IsEmpty();
	if (flag)
		cout << "ɾ���ɹ�" << endl;
	else
		cout << "ɾ��ʧ��" << endl;
	return 0;
}