#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void Swap(char  *A, char *B){
    char* temp;
    int n = 1 + strlen(A)>strlen(B)?strlen(A):strlen(B);
    //A=realloc(A, n* sizeof(char));
    //B=realloc(B, n* sizeof(char));
    temp=A;
    A=B;
    B=temp;
    
    //strcpy(temp,A);
    //strcpy(A,B);
    //strcpy(B,temp);
    
}
*/
int lexicographic_sort(const char* a, const char* b) {
    if (strcmp(a,b)>0) return 1;
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a,b)<0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    //return strcmp(a,b)>0;
    
    int alen=strlen(a), blen=strlen(b);
    int * aChar = calloc(alen, sizeof(int));
    int * bChar = calloc(blen, sizeof(int));
    for(int i=0;i<strlen(a);i++){
        for(int j=0;j<strlen(a);j++) 
            if(i!=j && aChar[i]==0 &&a[i]==a[j]){
                aChar[j]=1;
                alen--;
            }
    }
    for(int i=0;i<strlen(b);i++){
        for(int j=0;j<strlen(b);j++) 
            if(i!=j && bChar[i]==0 && b[i]==b[j]){
                bChar[j]=1;
                blen--;
            }
    }
    free(aChar);
    free(bChar);
    if(alen==blen) return lexicographic_sort(a,b);
    return alen>blen;
    
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a)==strlen(b))return lexicographic_sort(a,b);
    return strlen(a)>strlen(b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
    //printf("\n\nEND\n\n");
    int sorted=0;
    for(int i=1;i<len && !sorted;i++){
        sorted =1;
        for(int j=0;j<len-i;j++)
        if((*cmp_func)(arr[j],arr[j+1])>0){
            //printf("%d    %d\n",arr[j],arr[j+1]);
            char *temp;
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1]=temp;
            //Swap(arr[j],arr[j+1]);
            //printf("%d    %d\n",arr[j],arr[j+1]);
            
            sorted=0;
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
