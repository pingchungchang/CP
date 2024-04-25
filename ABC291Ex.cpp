#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
int sz[mxn];
bitset<mxn> del;
vector<int> tree[mxn];
int centree[mxn];
void szdfs(int now,int par){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par||del[nxt])continue;
        szdfs(nxt,now);
        sz[now] += sz[nxt];
    }
    return;
}
int find_centroid(int now,int par,int tar){
    for(auto nxt:tree[now]){
        if(nxt == par||del[nxt])continue;
        if(sz[nxt]>=tar)return find_centroid(nxt,now,tar);
    }
    return now;
}

void cendfs(int now,int par){
    szdfs(now,now);
    int c = find_centroid(now,now,(sz[now]+1)/2);
    centree[c] = par;
    // cout<<now<<' '<<c<<' '<<sz[now]<<endl;
    del[c] = true;
    for(auto nxt:tree[c]){
        if(del[nxt])continue;
        cendfs(nxt,c);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cendfs(1,-1);
    for(int i = 1;i<=n;i++)cout<<centree[i]<<' ';
}