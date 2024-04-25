#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn = 2e5+10;
bitset<mxn> goneto = {};
vector<vector<int>> v;
vector<pair<int,int>> a1,a2;

void dfs(int now){
    goneto[now] = true;
    for(auto nxt:v[now]){
        if(goneto[nxt])continue;
        a1.push_back(make_pair(now,nxt));
        dfs(nxt);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    v = vector<vector<int>>(n+1);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    queue<int> q;
    q.push(1);
    goneto.reset();
    goneto[1] = true;
    while(!q.empty()){
        int now = q.front();q.pop();
        for(auto nxt:v[now]){
            if(goneto[nxt])continue;
            goneto[nxt] = true;
            a2.push_back(make_pair(now,nxt));
            q.push(nxt);
        }
    }
    for(auto i:a1)cout<<i.first<<' '<<i.second<<'\n';
    for(auto i:a2)cout<<i.first<<' '<<i.second<<'\n';
    return 0;
}
