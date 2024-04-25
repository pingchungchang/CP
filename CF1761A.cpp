#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(n == 1&&a == 1&&b == 1){
        cout<<"Yes\n";
        return;
    }
    else if(n == 1){
        cout<<"No\n";
        return;
    }
    if(a == b&&a == n){
        cout<<"Yes\n";
        return;
    }
    if(a+b>=n-1)cout<<"No\n";
    else cout<<"Yes\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}