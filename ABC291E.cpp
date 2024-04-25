#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
vector<int> paths[mxn];
int deg[mxn];
int ans[mxn];
int cnt[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(deg[i] == 0){
            q.push(i);
            ans[i] = 1;
        }
    }
    if(q.size()>1){
        cout<<"No";
        return 0;
    }
    while(!q.empty()){
        if(q.size()>1){
            cout<<"No";
            return 0;
        }
        auto now= q.front();
        q.pop();
        for(auto nxt:paths[now]){
            deg[nxt]--;
            if(!deg[nxt]){
                q.push(nxt);
                ans[nxt] = ans[now]+1;
            }
        }
    }
    cout<<"Yes\n";
    for(int i = 1;i<=n;++i)cout<<ans[i]<<' ';cout<<'\n';
    return 0;
}