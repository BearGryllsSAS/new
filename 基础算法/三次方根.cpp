#include <iomanip>
#include <iostream>
using namespace std;

double n;
double l, r, mid;

int main()
{
	cin >> n;

	l = 0, r = n;
	
	for (int i = 0; i < 100; i++)
	{
		mid = (l + r) / 2;
		
		if (mid * mid * mid > n) r = mid;
		else l = mid;
	}
	
	cout << fixed << setprecision(10) << l << endl;
	
	return 0;	
}
