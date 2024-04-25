#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l = INT_MAX,u = INT_MAX;
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    for(int i = 0;i<n;i++)for(int j = 0;j<m;j++){
        if(v[i][j] == 'R'){
            u = min(u,i);
            l = min(l,j);
        }
    }
    if(u == INT_MAX)cout<<"NO\n";
    else if(v[u][l] == 'R')cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
