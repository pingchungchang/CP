#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 1010;
int shif = mxn>>1;
int paths[mxn][mxn];
bool vis[mxn];
int deg[mxn];
int odds;
int total;
void dfs(int now){
    vis[now] = true;
    if(deg[now]&1)odds++;
    total += deg[now];
    for(int i = 1;i<=mxn;i++){
        if(paths[now][i]&&!vis[i]){
            dfs(i);
        }
    }
    return;
}
int main(){
    ll a,b,s,m,k;
    cin>>a>>b>>s>>m>>k;
    for(int i = 0;i<k;i++){
        int x,y,z;
        cin>>x>>y>>z;
        paths[x][a+y] = paths[a+y][x] = 1;
        deg[x]++;
        deg[y+a]++;
    }
    //for(int i = 1;i<=a+b;i++)cout<<deg[i]<<' ';return 0;
    int ans = 0;
    for(int i = 1;i<=a;i++){
        if(!vis[i]){
            total = odds = 0;
            dfs(i);
            if(total != 0)ans += max(odds/2,1);
        }
    }
    cout<<ans;

}
