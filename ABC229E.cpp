#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
vector<int> paths[mxn];
int dsu[mxn],sz[mxn],cnt,ans[mxn];

int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
    a = root(a),b = root(b);
    if(a == b)return;
    if(sz[b]>sz[a])swap(a,b);
    dsu[a] = b;
    sz[b] += sz[a];
    cnt--;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        dsu[i] = i;
        sz[i] = 1;
    }
    cnt = n;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        paths[a].push_back(b);
    }
    for(int i = n;i>=1;i--){
        ans[i] = cnt-i;
        for(auto nxt:paths[i]){
            onion(i,nxt);
        }
    }
    for(int i = 1;i<=n;i++)cout<<ans[i]<<'\n';
}