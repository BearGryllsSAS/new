#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, q, k;
int l, r, mid;
int arr[N];

int main()
{
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	while (q--)
	{
		scanf("%d", &k);
		
		// 起始位置
		l = 0, r = n - 1, mid = -1;
		
		while (l < r)
		{
			mid = l + r >> 1;
			
			if (arr[mid] >= k) r = mid;
			else l = mid + 1;
		}
		
		if (arr[l] != k) 
		{
			printf("-1 -1\n");
			continue;
		}
		
		printf("%d ", l);
		
		
		// 终止位置	
		l = 0, r = n - 1, mid = -1;
		
		while (l < r)
		{
			mid = l + r + 1 >> 1;
			
			if (arr[mid] <= k) l = mid;
			else r = mid - 1;
		}
		
		printf("%d\n", r);
	}
	
	return 0;
} 
