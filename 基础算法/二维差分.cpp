#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int x1, y1, x2, y2, c;
int arr[N][N], srr[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	arr[x1][y1] += c;
	arr[x2 + 1][y1] -= c;
	arr[x1][y2 + 1] -= c;
	arr[x2 + 1][y2 + 1] += c;
}

int main()
{
	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &srr[i][j]);
			
			insert(i, j, i, j, srr[i][j]);
		}
	}
	
	while (q--)
	{
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
		
		insert(x1, y1, x2, y2, c);
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			// srr[i][j] = srr[i][j - 1] + srr[i - 1][j] - srr[i - 1][j - 1] + arr[i][j];		// srr 根本没用
			
			arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1]; 
			
			printf("%d ", arr[i][j]);
		}
		puts("");
	}
	
	return 0;
}
