#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void H()
{
	int n;
	int a[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long result = 0;
	int left = 0, right = n - 1;
	while (left < right)
	{
		while (left + 1 < n && a[left] < a[left + 1])
			left++;
		while (right - 1 > 0 && a[right] < a[right - 1])
			right--;
		if (left < right)
		{
			if (a[left] <= a[right])
			{
				int inc = a[left] + 1 - a[left + 1];
				a[left + 1] += inc;
				result += inc;
				left++;
			}
			else
			{
				int inc = a[right] + 1 - a[right - 1];
				a[right - 1] += inc;
				result += inc;
				left++;
			}
		}
	}
	cout << result << endl;
}

int main()
{
	H();
	return 0;
}
