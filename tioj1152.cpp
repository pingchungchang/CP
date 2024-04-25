#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e4+10;
int dist[mxn];
vector<int> paths[mxn];

void dfs(int now,int par){
    for(auto nxt:paths[now]){
        if(nxt == par)continue;
        dist[nxt] = dist[now]+1;
        dfs(nxt,now);
    }
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int k;
        while(cin>>k&&k != -1){
            paths[i].push_back(k);
            paths[k].push_back(i);
        }
    }
    dfs(0,0);
    pair<int,int> big = {0,0};
    for(int i = 0;i<n;i++){
        big = max(big,make_pair(dist[i],i));
    }
    dist[big.second] = 0;
    dfs(big.second,-1);
    int ans = 0;
    for(int i = 0;i<n;i++)ans = max(ans,dist[i]);
    cout<<ans;
}