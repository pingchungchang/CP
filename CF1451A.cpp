#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    if(n<=3)cout<<n-1<<'\n';
    else{
        if(n%2 == 0)cout<<2<<'\n';
        else cout<<3<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
