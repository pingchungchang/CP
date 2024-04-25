#include <bits/stdc++.h>
using namespace std;

const int mxn = 11;
int arr[mxn][mxn];
set<int> st;
int ans = 0;
int n,m;
void dfs(int r,int c){
    if(st.find(arr[r][c]) != st.end())return;
    if(r == n-1&&c == m-1){
        ans++;
        return;
    }
    st.insert(arr[r][c]);
    if(r != n-1)dfs(r+1,c);
    if(c != m-1)dfs(r,c+1);
    st.erase(arr[r][c]);
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)cin>>arr[i][j];
    dfs(0,0);
    cout<<ans;
}