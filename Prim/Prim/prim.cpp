#include <iomanip> 
#include <iostream> 
#include <vector> 
using namespace std;

class MatrixUDG {
#define MAX    100 
#define INF    (~(0x1<<31))        // ����� 
private:
	char mVexs[MAX];    // ���㼯�� 
	int mVexNum;             // ������ 
	int mEdgNum;             // ���� 
	int mMatrix[MAX][MAX];   // �ڽӾ��� 

public:
	// ����ͼ(�Լ���������) 
	MatrixUDG();
	// ����ͼ(�����ṩ�ľ���) 
	//MatrixUDG(char vexs[], int vlen, char edges[][2], int elen); 
	MatrixUDG(char vexs[], int vlen, int matrix[][9]);
	~MatrixUDG();

	// ���������������ͼ 
	void DFS();
	// ����������������������Ĳ�α����� 
	void BFS();
	// prim��С������(��start��ʼ������С������) 
	void prim(int start);
	// ��ӡ�������ͼ 
	void print();

private:
	// ��ȡһ�������ַ� 
	char readChar();
	// ����ch��mMatrix�����е�λ�� 
	int getPosition(char ch);
	// ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1 
	int firstVertex(int v);
	// ���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1 
	int nextVertex(int v, int w);
	// ���������������ͼ�ĵݹ�ʵ�� 
	void DFS(int i, int *visited);

};

/*
* ����ͼ(�Լ���������)
*/
MatrixUDG::MatrixUDG()
{
	char c1, c2;
	int i, j, weight, p1, p2;

	// ����"������"��"����" 
	cout << "input vertex number: ";
	cin >> mVexNum;
	cout << "input edge number: ";
	cin >> mEdgNum;
	if (mVexNum < 1 || mEdgNum < 1 || (mEdgNum >(mVexNum * (mVexNum - 1))))
	{
		cout << "input error: invalid parameters!" << endl;
		return;
	}

	// ��ʼ��"����" 
	for (i = 0; i < mVexNum; i++)
	{
		cout << "vertex(" << i << "): ";
		mVexs[i] = readChar();
	}

	// 1. ��ʼ��"��"��Ȩֵ 
	for (i = 0; i < mVexNum; i++)
	{
		for (j = 0; j < mVexNum; j++)
		{
			if (i == j)
				mMatrix[i][j] = 0;
			else
				mMatrix[i][j] = INF;
		}
	}
	// 2. ��ʼ��"��"��Ȩֵ: �����û���������г�ʼ�� 
	for (i = 0; i < mEdgNum; i++)
	{
		// ��ȡ�ߵ���ʼ���㣬�������㣬Ȩֵ 
		cout << "edge(" << i << "): ";
		c1 = readChar();
		c2 = readChar();
		cin >> weight;

		p1 = getPosition(c1);
		p2 = getPosition(c2);
		if (p1 == -1 || p2 == -1)
		{
			cout << "input error: invalid edge!" << endl;
			return;
		}

		mMatrix[p1][p2] = weight;
		mMatrix[p2][p1] = weight;
	}
}

/*
* ����ͼ(�����ṩ�ľ���)
*
* ����˵����
*     vexs  -- ��������
*     vlen  -- ��������ĳ���
*     matrix-- ����(����)
*/
MatrixUDG::MatrixUDG(char vexs[], int vlen, int matrix[][9])
{
	int i, j;

	// ��ʼ��"������"��"����" 
	mVexNum = vlen;
	// ��ʼ��"����" 
	for (i = 0; i < mVexNum; i++)
		mVexs[i] = vexs[i];

	// ��ʼ��"��" 
	for (i = 0; i < mVexNum; i++)
	for (j = 0; j < mVexNum; j++)
		mMatrix[i][j] = matrix[i][j];

	// ͳ�Ʊߵ���Ŀ 
	for (i = 0; i < mVexNum; i++)
	for (j = 0; j < mVexNum; j++)
	if (i != j && mMatrix[i][j] != INF)
		mEdgNum++;
	mEdgNum /= 2;
}

/*
* ��������
*/
MatrixUDG::~MatrixUDG()
{
}

/*
* ����ch��mMatrix�����е�λ��
*/
int MatrixUDG::getPosition(char ch)
{
	int i;
	for (i = 0; i<mVexNum; i++)
	if (mVexs[i] == ch)
		return i;
	return -1;
}

/*
* ��ȡһ�������ַ�
*/
char MatrixUDG::readChar()
{
	char ch;

	do {
		cin >> ch;
	} while (!((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')));

	return ch;
}


/*
* ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
*/
int MatrixUDG::firstVertex(int v)
{
	int i;

	if (v<0 || v>(mVexNum - 1))
		return -1;

	for (i = 0; i < mVexNum; i++)
	if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
		return i;

	return -1;
}

/*
* ���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
*/
int MatrixUDG::nextVertex(int v, int w)
{
	int i;

	if (v<0 || v>(mVexNum - 1) || w<0 || w>(mVexNum - 1))
		return -1;

	for (i = w + 1; i < mVexNum; i++)
	if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
		return i;

	return -1;
}

/*
* ���������������ͼ�ĵݹ�ʵ��
*/
void MatrixUDG::DFS(int i, int *visited)
{
	int w;

	visited[i] = 1;
	cout << mVexs[i] << " ";
	// �����ö���������ڽӶ��㡣����û�з��ʹ�����ô���������� 
	for (w = firstVertex(i); w >= 0; w = nextVertex(i, w))
	{
		if (!visited[w])
			DFS(w, visited);
	}

}

/*
* ���������������ͼ
*/
void MatrixUDG::DFS()
{
	int i;
	int visited[MAX];       // ������ʱ�� 

	// ��ʼ�����ж��㶼û�б����� 
	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;

	cout << "DFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		//printf("\n== LOOP(%d)\n", i); 
		if (!visited[i])
			DFS(i, visited);
	}
	cout << endl;
}

/*
* ����������������������Ĳ�α�����
*/
void MatrixUDG::BFS()
{
	int head = 0;
	int rear = 0;
	int queue[MAX];     // ������� 
	int visited[MAX];   // ������ʱ�� 
	int i, j, k;

	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;

	cout << "BFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << mVexs[i] << " ";
			queue[rear++] = i;  // ����� 
		}
		while (head != rear)
		{
			j = queue[head++];  // ������ 
			for (k = firstVertex(j); k >= 0; k = nextVertex(j, k)) //k��Ϊ���ʵ��ڽӶ��� 
			{
				if (!visited[k])
				{
					visited[k] = 1;
					cout << mVexs[k] << " ";
					queue[rear++] = k;
				}
			}
		}
	}
	cout << endl;
}

/*
* ��ӡ�������ͼ
*/
void MatrixUDG::print()
{
	int i, j;

	cout << "Martix Graph:" << endl;
	for (i = 0; i < mVexNum; i++)
	{
		for (j = 0; j < mVexNum; j++)
			cout << setw(10) << mMatrix[i][j] << " ";
		cout << endl;
	}
}

/*
* prim��С������
*
* ����˵����
*   start -- ��ͼ�еĵ�start��Ԫ�ؿ�ʼ��������С��
*/
void MatrixUDG::prim(int start)
{
	int min, i, j, k, m, n, sum;
	int index = 0;         // prim��С������������prims��������� 
	char prims[MAX];     // prim��С���Ľ������ 
	int weights[MAX];    // �����ߵ�Ȩֵ 

	// prim��С�������е�һ������"ͼ�е�start������"����Ϊ�Ǵ�start��ʼ�ġ� 
	prims[index++] = mVexs[start];

	// ��ʼ��"�����Ȩֵ����"�� 
	// ��ÿ�������Ȩֵ��ʼ��Ϊ"��start������"��"�ö���"��Ȩֵ�� 
	for (i = 0; i < mVexNum; i++)
		weights[i] = mMatrix[start][i];
	// ����start�������Ȩֵ��ʼ��Ϊ0�� 
	// �������Ϊ"��start�����㵽������ľ���Ϊ0"�� 
	weights[start] = 0;

	for (i = 0; i < mVexNum; i++)
	{
		// ���ڴ�start��ʼ�ģ���˲���Ҫ�ٶԵ�start��������д��� 
		if (start == i)
			continue;

		j = 0;
		k = 0;
		min = INF;
		// ��δ�����뵽��С�������Ķ����У��ҳ�Ȩֵ��С�Ķ��㡣 
		while (j < mVexNum)
		{
			// ��weights[j]=0����ζ��"��j���ڵ��Ѿ��������"(����˵�Ѿ���������С��������)�� 
			if (weights[j] != 0 && weights[j] < min)
			{
				min = weights[j];
				k = j;
			}
			j++;
		}

		// ��������Ĵ������δ�����뵽��С�������Ķ����У�Ȩֵ��С�Ķ����ǵ�k�����㡣 
		// ����k��������뵽��С�������Ľ�������� 
		prims[index++] = mVexs[k];
		// ��"��k�������Ȩֵ"���Ϊ0����ζ�ŵ�k�������Ѿ��������(����˵�Ѿ���������С�������)�� 
		weights[k] = 0;
		// ����k�����㱻���뵽��С�������Ľ��������֮�󣬸������������Ȩֵ�� 
		for (j = 0; j < mVexNum; j++)
		{
			// ����j���ڵ�û�б�����������Ҫ����ʱ�ű����¡� 
			if (weights[j] != 0 && mMatrix[k][j] < weights[j])
				weights[j] = mMatrix[k][j];
		}
	}

	// ������С��������Ȩֵ 
	sum = 0;
	for (i = 1; i < index; i++)
	{
		min = INF;
		// ��ȡprims[i]��mMatrix�е�λ�� 
		n = getPosition(prims[i]);
		// ��vexs[0...i]�У��ҳ���j��Ȩֵ��С�Ķ��㡣 
		for (j = 0; j < i; j++)
		{
			m = getPosition(prims[j]);
			if (mMatrix[m][n]<min)
				min = mMatrix[m][n];
		}
		sum += min;
	}
	// ��ӡ��С������ 
	cout << "PRIM(" << mVexs[start] << ")=" << sum << ": ";
	for (i = 0; i < index; i++)
		cout << prims[i] << " ";
	cout << endl;
}

int main()
{
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int matrix[][9] = {
		/*A*//*B*//*C*//*D*//*E*//*F*//*G*/
		/*A*/{ 0, 12, INF, INF, INF, 16, 14 },
		/*B*/{ 12, 0, 10, INF, INF, 7, INF },
		/*C*/{ INF, 10, 0, 3, 5, 6, INF },
		/*D*/{ INF, INF, 3, 0, 4, INF, INF },
		/*E*/{ INF, INF, 5, 4, 0, 2, 8 },
		/*F*/{ 16, 7, 6, INF, 2, 0, 9 },
		/*G*/{ 14, INF, INF, INF, 8, 9, 0 } };
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	MatrixUDG* pG;

	// �Զ���"ͼ"(����������) 
	//pG = new MatrixUDG(); 
	// �������е�"ͼ" 
	pG = new MatrixUDG(vexs, vlen, matrix);

	//pG->print();   // ��ӡͼ 
	//pG->DFS();     // ������ȱ��� 
	//pG->BFS();     // ������ȱ��� 
	pG->prim(0);     // prim�㷨������С������ 

	return 0;
}
