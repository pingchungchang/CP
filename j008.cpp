#include <bits/stdc++.h>
using namespace std;

int n,m;
const int mxn = 505;
bool paths[mxn][mxn],visy[mxn];
int matchx[mxn],matchy[mxn];


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
int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a][b] = true;
    }
    int ans = 0;
    for(int i =1;i<=n;i++){
        fill(visy,visy+n+1,false);
        if(dfs(i))ans++;
    }
    cout<<n-ans;
}
