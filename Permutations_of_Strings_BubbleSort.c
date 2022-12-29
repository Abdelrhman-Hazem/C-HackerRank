#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char  *A, char *B){
    char temp[11];
    strcpy(temp,A);
    strcpy(A,B);
    strcpy(B,temp);

}
void BubbleSort(char  ** data, int size,int start){
    int sorted=0;
    for(int i=start+1;i<size && !sorted;i++){
        sorted =1;
        for(int j=start;j<size-i+start;j++)
        if(strcmp(data[j],data[j+1])>0){
            Swap(data[j],data[j+1]);
            sorted=0;
        }
    }
}
int next_permutation(int n, char **s)
{
    /**
    * Complete this method
    * Return 0 when there is no next permutation and 1 otherwise
    * Modify array s to its next permutation
    */
    //i==n ||
    for(int i=n-1;i>0;i--){
        //for(int k=0;k<n;k++)strcpy(str[i], s[i]);
        if (strcmp(s[i], s[i-1])>0){
            int ind=n;
            while (ind>=i){
                if(strcmp(s[i-1],s[ind-1])>0){
                    char temp[11];
                    strcpy(temp,s[i]);
                    int key=i;
                    for(int k=i;k<ind;k++){
                        if(strcmp(temp,s[k])>0 && strcmp(s[i-1],s[k])<0) {
                            strcpy(temp,s[k]);
                            key=k;
                        }
                    }
                    Swap(s[key], s[i-1]);
                    BubbleSort(s, n, i);
                    ind=i-1;
                }else if (strcmp(s[i-1],s[ind-1])<0){
                    char temp[11];
                    strcpy(temp,s[ind-1]);
                    for (int j=ind-2;j>=i-1;j--)strcpy(s[j+1],s[j]);
                    strcpy(s[i-1],temp);
                    BubbleSort(s, n, i);
                    ind=i-1;

                }else {ind--;}
            }
            //printf("1 2 3sdfsdfsadf\n");
            return 1;
        }
    }
    return 0;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
