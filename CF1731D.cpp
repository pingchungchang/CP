#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int n,m;
bool f(int k){
    vector<vector<int>> tmp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            tmp[i][j] = tmp[i-1][j]+tmp[i][j-1]-tmp[i-1][j-1];
            if(arr[i][j]>=k)tmp[i][j]++;
        }
    }
    for(int i = k;i<=n;i++){
        for(int j= k;j<=m;j++){
            if(tmp[i][j]-tmp[i-k][j]-tmp[i][j-k]+tmp[i-k][j-k] == k*k)return true;
        }
    }
    return false;
}
void solve(){
    cin>>n>>m;
    arr = vector<vector<int>>(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++)cin>>arr[i][j];
    }
    int l = 1,r = min(n,m);
    while(l != r){
        int mid = (l+r+1)>>1;
        if(f(mid))l = mid;
        else r = mid-1;
    }
    cout<<l<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}