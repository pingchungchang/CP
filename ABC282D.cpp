#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 5e5+10;
vector<int> paths[mxn];
int col[mxn];
ll id = 0;
ll cnt[mxn];
bool dfs(int now,int c){
    col[now] = c;
    bool re = true;
    cnt[c]++;
    for(auto nxt:paths[now]){
        if(col[nxt] == -1)re = (re&&dfs(nxt,c^1));
        else if(col[nxt] != (c^1))return false;
    }
    return re;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(col,-1,sizeof(col));
    ll ans = 0;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        if(col[i] == -1){
            if(!dfs(i,id+=2)){
                cout<<"0\n";
                return 0;
            }
        }
    }
    ll total = 0;
    for(int i = 0;i<mxn;i+=2){
        ans += 1LL*cnt[i]*cnt[i^1];
        ans += total*(cnt[i]+cnt[i^1]);
        total += cnt[i]+cnt[i^1];
    }
    cout<<ans-m;
}