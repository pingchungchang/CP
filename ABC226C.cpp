#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 2e5+10;
ll val[mxn];
int deg[mxn];
ll t[mxn];
vector<int> paths[mxn];
bitset<mxn> used;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>t[i];
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            paths[i].push_back(x);
        }
    }
    queue<int> q;
    used[n] = true;
    q.push(n);
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:paths[now]){
            if(used[nxt])continue;
            q.push(nxt);
            used[nxt] = true;
        }
    }
    ll total = 0;
    for(int i = 1;i<=n;i++){
        if(used[i])total += t[i];
    }
    cout<<total;
}