#include <iostream>
#include <string>
using namespace std;

int a[5001];

int main()
{
    int n,i,j;

    while (scanf("%d",&n)!=EOF)
    {
        if (n<=0) break;
        for (i=0; i<n; i++) scanf("%d",&a[i]);

        for (i=0; i<n-1; i++)
			for (j=i+1; j<n; j++)
			if (a[i]>a[j])
			{
				printf("%d %d\n",a[i],a[j]);
				swap(a[i],a[j]);
			}

        printf("%d",a[0]); for (i=1; i<n; i++) printf(" %d",a[i]); printf("\n");
    }
    return 0;
}            
