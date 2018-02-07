#include <stdio.h>
#include <stdlib.h>
#include "math.h"
typedef struct point {
	double x;
	double y;
}point;
point array[30001];

int comp1(void const *a,void const *b);

int comp2(void const *a,void const *b);
double distance(point a,point b);
int main(int argc, char *argv[]) 
{

	int n,i,j,count;
	double maxdis,temp;
	while(scanf("%d",&n)!= EOF){
	
	for(i = 0;i<n;i++){
		scanf("%lf %lf",&array[i].x,&array[i].y);
	}
	for(i = 0;i<n;i++){
		//printf("%d %d\n",array[i].x,array[i].y);
		//printf("dis:%.2f\n",distance(array[0],array[i]));

	}
	maxdis = 0.0;

	qsort(array,n,sizeof(point),comp1);

	for(i = 0;i<n && i<=300;i++){
		for(j = n-1;j>=0 && j>=n-301;j--){
			if(distance((array[i]),(array[j])) > maxdis ){
				maxdis =distance((array[i]),(array[j]));
			}
		}
	}
	qsort(array,n,sizeof(point),comp2);
	for(i = 0;i<n && i<=300;i++){
		for(j = n-1;j>=0 && j>=n-301;j--){
			if(distance((array[i]),(array[j])) > maxdis ){
				maxdis =distance((array[i]),(array[j]));
			}
		}
	}
	printf("%.2lf\n",maxdis);
	}
	system("pause");
	return 0;
}

//¼ÆËãx yÖ®¼ä¾àÀë
double distance(point a,point b){
    return sqrt(    (a.x - b.x)*(a.x - b.x)  +   (a.y -b.y)*(a.y -b.y)  );
}

int comp1(void const *a,void const *b){
	if(((point *)a)->x > ((point *)b)->x){
		return 1;
	}
	if(((point *)a)->x == ((point *)b)->x){
		return 0;
	}
	else{
		return -1;
	}
}

int comp2(void const *a,void const *b){
	if(((point *)a)->y > ((point *)b)->y){
		return 1;
	}
	if(((point *)a)->y == ((point *)b)->y){
		return 0;
	}
	else{
		return -1;
	}
}
