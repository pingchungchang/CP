#include <bits/stdc++.h>
using namespace std;


void solve(){
    int k;
    cin>>k;
    if(k<3)cout<<4-k<<'\n';
    else cout<<k%2<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
