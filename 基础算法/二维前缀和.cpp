#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q, x1, y1, x2, y2;
int arr[N][N], srr[N][N];

int main()
{
	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			srr[i][j] = srr[i][j - 1] + srr[i - 1][j] - srr[i - 1][j - 1] + arr[i][j];
			
	while (q--)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		printf("%d\n", srr[x2][y2] - srr[x2][y1 - 1] - srr[x1 - 1][y2] + srr[x1 - 1][y1 - 1]);
	}
	
	return 0;
}
