#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
    int i=4;
    int term;
    if(n==1)return a;
    if(n==2)return b;
    if(n==3)return c;
    for(i=4;i<=n;i++){
        term=a+b+c;
        a=b;
        b=c;
        c=term;
    }
    return term;
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}
