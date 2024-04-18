#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int M, k, x;
char op[2];

int head, e[N], ne[N], idx;

void init()
{
	head = -1, idx = 0;
}

void add_head(int x)
{
	e[idx] = x, ne[idx] = head, head = idx++;
}

void add_k(int k, int x)
{
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void delete_head()
{
	head = ne[head];
}

void delete_k(int k)
{
	ne[k] = ne[ne[k]];
}

int main()
{
	init();
	
	cin >> M;
	
	while (M--)
	{
		cin >> op;
		
		if (op[0] == 'H')
		{
			scanf("%d", &x);
			
			add_head(x);
		}
		else if (op[0] == 'D')
		{
			scanf("%d", &k);
			
			if (k == 0) delete_head();
			else delete_k(k - 1);
		}
		else 
		{
			scanf("%d %d", &k, &x);
			
			add_k(k - 1, x);
		}
	}
	
	for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
	
	return 0;
}
