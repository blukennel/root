#include <stdio.h>

void foo(char* n1, char* n2)
{
    int k = 0;
    while(n2[k]!=0)
        k++;
    int start = k;
    k = 0;
    while(n1[k]!=0)
    {
        n2[start+k]=n1[k];
        k++;
    }
    n2[start+k]=0;
}

int main()
{
    char n1[] = " ma";
    char n2[50];
    n2[0]='A'; n2[1]='l'; n2[2]='a'; n2[3]= 0;

    printf("%s\n",n1);
    printf("%s\n",n2);
    foo(n1,n2);
    printf("%s\n",n1);
    printf("%s\n",n2);
    return 0;
}
