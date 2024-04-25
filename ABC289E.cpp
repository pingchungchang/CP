#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2020;
int vis[mxn][mxn];
int col[mxn];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> paths[n+1];
    for(int i = 1;i<=n;i++)cin>>col[i];
    for(int i = 1;i<=n;i++)for(int j = 0;j<=n;j++)vis[i][j] = 0;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{1,n}});
    vis[1][n] = 1;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int a = now.sc.fs,b = now.sc.sc;
        for(auto &i:paths[a]){
            for(auto &j:paths[b]){
                if(col[i]!=col[j]&&!vis[i][j]){
                    q.push({now.fs+1,{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        if(a == n&&b == 1){
            cout<<now.fs<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}