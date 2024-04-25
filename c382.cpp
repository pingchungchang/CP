#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    char c;
    while(scanf("%d %c %d",&a,&c,&b) != EOF){
        if(c == '+'){
            printf("%d",a+b);
        }
        else if(c == '-'){
            printf("%d",a-b);
        }
        else if(c == '*'){
            printf("%d",a*b);
        }
        else{
            printf("%d",a/b);
        }
        printf("\n");
    }
}