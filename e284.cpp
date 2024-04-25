#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n == 0)printf("No\n");
        else{
            if((n&(n-1)) ==0)printf("Yes\n");
            else printf("No\n");
        }
        scanf("\n");
    }
}