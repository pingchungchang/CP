#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    if(n&1){
        int shift = (k-1)/(n/2);
        k += shift;
        k = (k-1)%n+1;
        cout<<k<<'\n';
    }
    else cout<<(k-1)%n+1<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}