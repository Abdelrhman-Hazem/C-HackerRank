#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char* str;
    str=malloc(sizeof(char)*100);
    scanf("%s",str);
    int arr[10]={0};
    for (int i=0;i<strlen(str);i++){
        if(str[i]>=48 && str[i]<=57)arr[str[i]-48]++;
    } 
    
    for(int i=0;i<10;i++)printf("%d ",arr[i]);
    
    return 0;
}
