#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d %d",&a,&b);
        if((a+b)%2 !=0||b>a)printf("impossible\n");
        else printf("%d %d\n",(a+b)/2,(a-b)/2);
    }
}