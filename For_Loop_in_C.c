#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char words[9][20] = { {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"},{"seven"}, {"eight"} , {"nine"}};
    for(int i=a ; i<=b;i++){
        if (i>9 && i%2==0) printf("even\n");
        else if (i>9 && i%2==1) printf("odd\n");
        else printf("%s\n", words[i-1]);
    }
    return 0;
}

