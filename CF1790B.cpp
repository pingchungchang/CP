#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,r,s;
    cin>>n>>s>>r;
    int ans[n-1];
    int total = 0;
    for(auto &i:ans)i = 1;
    total = n-1;
    int p = 0;
    for(int p = 0;total != r;p= (p+1)%(n-1)){
        ans[p]++;
        total++;
    }
    cout<<s-r<<' ';
    for(auto &i:ans)cout<<i<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}