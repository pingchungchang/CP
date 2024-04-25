#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

const int mxn = 2e5+10;
vector<int> tree[mxn];
bool flag;
map<vector<int>,int> mp;
int dp[mxn];
int idx;
void check(int now,int par){
    map<int,int> cnt;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        cnt[dp[nxt]]++;
    }
    vector<int> odd;
    for(auto &i:cnt){
        if(i.second&1)odd.push_back(i.first);
    }
    if(odd.size()>1){
        flag = false;
        return;
    }
    if(odd.size() == 0)return;
    for(auto nxt:tree[now]){
        if(dp[nxt] == odd[0]){
            check(nxt,now);
            return;
        }
    }
}
void dfs(int now,int par){
    map<int,int> cnt;
    vector<int> v;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs(nxt,now);
        v.push_back(dp[nxt]);
        cnt[dp[nxt]]++;
    }
    sort(v.begin(),v.end());
    if(mp[v] == 0)mp[v] = ++idx;
    dp[now] = mp[v];
    if(now == par){
        vector<int> odd;
        for(auto &i:cnt){
            if(i.second&1)odd.push_back(i.first);
        }
        if(odd.size()>1)flag = false;
        if(odd.size() == 0)return;
        for(auto &nxt:tree[now]){
            if(dp[nxt] == odd[0]){
                check(nxt,now);
                return;
            }
        }
    }
    // cout<<now<<":"<<dp[now]<<endl;
    return;
}
void solve(){
    int n;
    flag = true;
    idx = 0;
    cin>>n;
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,1);
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
    for(int i = 0;i<=n;i++)tree[i].clear();
    mp.clear();
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}