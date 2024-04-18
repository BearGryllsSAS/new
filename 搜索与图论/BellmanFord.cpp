#include <cstring>
#include <iostream>
using namespace std;

const int N = 510, M = 10010;

struct Edge
{
	int a, b, w;
} edges[M];

int n, m, k, x, y, z;
int d[N], backup[N];

int bellmanFord()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	
	for (int i = 0; i < k; i++)
	{
		memcpy(backup, d, sizeof d);
		
		for (int j = 0; j < m; j++)
		{
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			
			d[b] = min(d[b], backup[a] + w);
		}
	}
	
	return d[n] > 0x3f3f3f3f / 2 ? -1 : d[n];
}

int main()
{
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		
		edges[i] = {x, y, z};
	}
	
	int res = bellmanFord();
	
	printf(res == -1 ? "impossible" : "%d\n", res);
	
	return 0;
}
