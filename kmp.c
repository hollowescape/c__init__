#include<stdio.h>
#include<string.h>
#define MAX 100

int failure[MAX];

int fail(char *pat){
    int n = strlen(pat);
    failure[0]=-1;
    int j, i;
    for(j=1; j<n; j++){
        i = failure[j-1];
        while((pat[j]!=pat[i+1] && (i>=0)))
            i = failure[i];
        if(pat[j] == pat[i+1])
            failure[j] = i+1;
        else failure[j] = -1;
    }
    return n;
}

int pos(char str[], char pat[]){

       int l1, l2, i=0, j=0;
       l1 = strlen(str);
       l2 = strlen(pat);
       while(i<l1 && j<l2){
                if(str[i]==pat[j])
                    i++, j++;
                else if(j==0) i++;
                else j = failure[j-1]+1;
        }
       if(j==l2)
            return i-l2;
        else 
            return -1;

}


void main(){
    char n[MAX],str[MAX*2];
    printf("enter the substringand string");
    gets(str);
    gets(n);
    fail(n);
    int posi = pos(str,n);
    printf("pos is %d",posi);
   
    
}
