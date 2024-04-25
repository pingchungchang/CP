#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

const int mxn = 1e5+10;
int n,q;
vector<int> tree[mxn];
vector<int> dp[mxn];

void dfs(int now,int par){
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs(nxt,now);
        for(auto &i:dp[nxt])dp[now].push_back(i);
        sort(dp[now].rbegin(),dp[now].rend());
        while(dp[now].size()>20)dp[now].pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        dp[i].push_back(k);
    }
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,1);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<dp[a][b-1]<<'\n';
    }
    return 0;
}