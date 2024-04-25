#include <bits/stdc++.h>
using namespace std;

const int mxn = 110;
bitset<mxn> vals[mxn];
void solve(){
    int n;
    cin>>n;
    string arr[n];
    vector<int> paths[n];
    int deg[n] = {};
    for(int i = 0;i<n;i++)vals[i].reset();
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n;i++)vals[i][i] = true;
    for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++)if(arr[i][j] == '1'){
            paths[i].push_back(j);
            deg[j]++;
        }
    }
    queue<int> q;
    for(int i = 0;i<n;i++)if(!deg[i])q.push(i);
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:paths[now]){
            vals[nxt]|=vals[now];
            deg[nxt]--;
            if(!deg[nxt])q.push(nxt);
        }
    }
    for(int i = 0;i<n;i++){
    cout<<vals[i].count()<<' ';
        for(int j = 0;j<n;j++)if(vals[i][j])cout<<j+1<<' ';cout<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}