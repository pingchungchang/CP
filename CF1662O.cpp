#include <bits/stdc++.h>
using namespace std;

int vis[44][361];
void dfs(int r,int t){
    vis[r][t] = 1;
    if(r>0&&!vis[r-1][t])dfs(r-1,t);
    if(!vis[r][(t+1)%360])dfs(r,(t+1)%360);
    if(!vis[r][(t+359)%360])dfs(r,(t+359)%360);
    if(r<=42&&!vis[r+1][t])dfs(r+1,t);
    return;
}
void solve(){
    for(auto &i:vis)for(auto &j:i)j = 0;
    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        if(c == 'C'){
            int r,ta,tb;
            cin>>r>>ta>>tb;
            r = r*2-1;
            for(int i = ta;i!= tb;i = (i+1)%360)vis[r][i] = -1;
            // vis[r][tb] = -1;
        }
        else{
            int ra,rb,t;
            cin>>ra>>rb>>t;
            t %= 360;
            for(int i = ra*2-1;i <= rb*2-1;i++)vis[i][t] = -1;
        }
    }
    dfs(0,0);
    bool flag = false;
    for(int i = 0;i<360;i++){
        if(vis[42][i])flag = true;
    }
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}