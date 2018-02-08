#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t, _case = 1;
	scanf("%d", &t);
	while (t--)
	{
		int n, dp = 0, maxSubSequence = (1<<31), begin = 1, end = 1, temp = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			int num;
			scanf("%d", &num);
			dp += num;
			if (dp > maxSubSequence) { maxSubSequence = dp; begin = temp; end = i; }
			if (dp < 0) { dp = 0; temp = i + 1; }
		}
		printf("Case %d:\n%d %d %d\n", _case++, maxSubSequence, begin, end);
		if (t) printf("\n");
	}
	return 0;
}
