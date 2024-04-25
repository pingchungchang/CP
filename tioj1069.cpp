#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 1010;
struct node{
    int t,x,y;
    node(){}
}arr[mxn];
bool paths[mxn][mxn],visy[mxn];
int matchx[mxn],matchy[mxn];
int n;
bool dfs(int now){
    for(int i = 1;i<=n;i++){
        if(!paths[now][i]||visy[i])continue;
        visy[i] = true;
        if(!matchy[i]||dfs(matchy[i])){
            matchy[i] = now;
            matchx[now] = i;
            return true;
        }
    }
    return false;
}
void solve(){
    cin>>n;
    fill(matchx,matchx+n+1,0);
    fill(matchy,matchy+n+1,0);
    fill(visy,visy+n+1,0);
    for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++)paths[i][j] = 0;
    for(int i = 1;i<=n;i++)cin>>arr[i].t>>arr[i].x>>arr[i].y;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(j == i||arr[i].t>=arr[j].t)continue;
            if(abs(arr[i].x-arr[j].x)+abs(arr[i].y-arr[j].y)<=arr[j].t-arr[i].t)paths[i][j] = true;
        }
    }
    int ans= 0;
    for(int i = 1;i<=n;i++){
        fill(visy,visy+n+1,false);
        if(dfs(i))ans++;
    }
    cout<<n-ans<<'\n';
}
int main(){
    io
    int t;
    cin>>t;
    while(t--)solve();
}

