#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        if(a==b&&b==0)return 0;
        int x = sqrt(a);
        int y = sqrt(b);
        int ans = y-x+1;
        if(x*x<a)ans--;
        printf("%d\n",ans);
    }
}