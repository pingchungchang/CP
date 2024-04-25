#include <bits/stdc++.h>
using namespace std;

const int mxn = 2020;
vector<int> paths[mxn];
int ans[mxn];
queue<int> q;
int dist[mxn];
void bfs(int now){
    fill(dist,dist+mxn,-1);
    dist[now] = 0;
    q.push(now);
    ans[0]++;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:paths[now]){
            if(dist[nxt] == -1){
                dist[nxt] = dist[now]+1;
                ans[dist[nxt]]++;
                q.push(nxt);
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i =2;i<=n;i++){
        paths[i].push_back(i-1);
        paths[i-1].push_back(i);
    }
    int a,b;
    cin>>a>>b;
    paths[a].push_back(b);
    paths[b].push_back(a);
    for(int i = 1;i<=n;i++)bfs(i);
    for(int i = 1;i<n;i++)cout<<ans[i]/2<<'\n';
}