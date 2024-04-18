#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m, l, r, c;
int arr[N], srr[N];

void insert(int l, int r, int c)
{
	arr[l] += c, arr[r + 1] -= c;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &srr[i]);
		
		insert(i, i, srr[i]);
	}
	
	while (m--)
	{
		scanf("%d %d %d", &l, &r, &c);
		
		insert(l, r, c);
	}
	
	for (int i = 1; i <= n; i++)
	{
		// srr[i] = srr[i - 1] + arr[i];
		
		arr[i] += arr[i - 1];
		
		printf("%d ", arr[i]);
	}
	
	return 0;	
} 
