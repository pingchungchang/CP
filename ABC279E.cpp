#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int arr[m];
    for(auto &i:arr)cin>>i;
    int now[n+1]= {},pos[n+1] = {};
    for(int i = 1;i<=n;i++)now[i] = i;
    for(int i = 1;i<=n;i++)pos[i] = i;
    int ans[n+1] = {};
    for(int i = 0;i<m-1;i++){
        swap(pos[now[arr[i]]],pos[now[arr[i]+1]]);
        swap(now[arr[i]],now[arr[i]+1]);
    }
    int inow[n+1] = {},ipos[n+1] = {};
    for(int i = 0;i<=n;i++){
        inow[i] = ipos[i] = i;
    }
    for(int i = m-1;i>=0;i--){
        ans[i] = ipos[inow[pos[1]]];
        swap(pos[now[arr[i]]],pos[now[arr[i]]+1]);
        swap(now[arr[i]],now[arr[i]+1]);
        swap()
    }
}
/*
dp[i] = for k = 1 to n-1 dp[i-k]*n*(n-1)
*/