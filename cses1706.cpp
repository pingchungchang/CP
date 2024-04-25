#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
const int mxn = 1e5+10;
int dsu[mxn];
int sz[mxn];
bitset<mxn> dp;
int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
    a = root(a),b = root(b);
    if(a == b)return;
    if(sz[a]<sz[b])swap(a,b);
    sz[b] += sz[a];
    dsu[a] = b;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1;
    while(m--){
        int a,b;
        cin>>a>>b;
        onion(a,b);
    }
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        if(dsu[i] == i){
            dp = dp|(dp<<sz[i]);
        }
    }
    for(int i = 1;i<=n;i++)cout<<dp[i];
}