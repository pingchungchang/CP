#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int ans = 0;
    while(cin>>a>>b>>c){
        int sum = a+b+c;
        int biggest = max(a,b);
        biggest = max(biggest,c);
        if(sum-biggest>biggest) ans++;
    }
    printf("%d",ans);
}