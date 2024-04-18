#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m, l, r;
int arr[N], srr[N];

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	
	for (int i = 1; i <= n; i++) srr[i] = srr[i - 1] + arr[i];
	
	while (m--)
	{
		scanf("%d %d", &l, &r);
		
		printf("%d\n", srr[r] - srr[l - 1]);
	}
	
	return 0;
}
