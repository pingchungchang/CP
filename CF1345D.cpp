#include <bits/stdc++.h>
using namespace std;

const int mxn = 1010;
int arr[mxn][mxn];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bitset<mxn> donex,doney;
bitset<mxn> mx,my;
void dfs(int r,int c){
    arr[r][c] = 0;
    donex[r] = doney[c] = true;
    for(int i = 0;i<4;i++){
        int nr = r+dx[i],nc= c+dy[i];
        if(arr[nr][nc])dfs(nr,nc);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            char c;
            cin>>c;
            if(c == '#')arr[i][j] = 1;
        }
    }
    bool flag = true;
    for(int i = 1;i<=n;i++){
        int cnt = 0;
        int s = m,e = 0;
        for(int j = 1;j<=m;j++){
            cnt += arr[i][j];
            if(arr[i][j]){
                s = min(j,s);
                e = max(j,e);
            }
        }
        if(e-s+1>cnt)flag = false;
    }
    for(int i = 1;i<=m;i++){
        int cnt = 0;
        int s = n,e = 0;
        for(int j= 1;j<=n;j++){
            cnt += arr[j][i];
            if(arr[j][i]){
                s = min(s,j);
                e = max(e,j);
            }
        }
        if(e-s+1>cnt)flag = false;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            if(arr[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    for(int i =1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            if(!donex[i]&&!doney[j])mx[i] = my[j] = true;
        }
    }   
    donex = donex|mx;
    doney = doney|my;
    // cout<<donex.count()<<' '<<doney.count();
    if(donex.count() != n||doney.count() != m)flag =false;
    if(!flag){
        cout<<-1;
        return 0;
    }
    cout<<ans;
}
