#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(m<=n/k){
        cout<<m<<'\n';
        return;
    }
    int d = m-n/k;
    // cout<<d<<":";
    cout<<n/k-(d+k-2)/(k-1)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}