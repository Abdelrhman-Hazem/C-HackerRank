#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void SwapTri(triangle * A, triangle * B){
    triangle temp;
    temp.a=A->a;    temp.b=A->b;    temp.c=A->c;
    A->a=B->a;      A->b=B->b;      A->c=B->c;
    B->a=temp.a;    B->b=temp.b;    B->c=temp.c;
}
void Swap(double * A,double * B){
    double temp;
    temp=*A;
    *A=*B;
    *B=temp;
}
void sort_by_area(triangle* tr, int n) {
	    /**
	* Sort an array a of the length n
	*/
    double * area;
    double a,b,c, p;
    
    area = malloc(n*sizeof(double));
    for(int i=0;i<n;i++){
        a=tr[i].a;  b=tr[i].b;  c=tr[i].c;
        p=(a+b+c)/2;
        area[i]=sqrt(p*(p-a)*(p-b)*(p-c));
    }
    
    int sorted=0;
    for(int i=1;i<n && !sorted;i++){
        sorted =1;
        for(int j=0;j<n-i;j++)
        if(area[j]>area[j+1]){
            SwapTri(&tr[j],&tr[j+1]);
            Swap(&area[j],&area[j+1]);
            sorted=0;
        }
    }
    
    //for(int i=0;i<n;i++)printf("%f   ",area[i]);
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
