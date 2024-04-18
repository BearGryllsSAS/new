#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int arr[N];

void quickSort(int l, int r)
{
	if (l >= r) return;
	
	int x = arr[l], i = l - 1, j = r + 1;
	
	while (i < j)
	{
		do i++; while (arr[i] < x);
		do j--; while (arr[j] > x);
		
		if (i < j) swap(arr[i], arr[j]);
	}
	
	quickSort(l, j), quickSort(j + 1, r);
}

int main()
{
	cin >> n;
	
	for  (int i= 0; i < n; i++) scanf("%d", &arr[i]);
	
	quickSort(0, n - 1);
	
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	
	return 0;
}
