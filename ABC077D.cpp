#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dist[n] = {},pre[n];
    bool vis[n] = {};
    for(int i = 0;i<n;i++){
        dist[i] = pre[i] = -1;
    }
    deque<int> dq;
    dist[1] = 1;
    dq.push_back(1);
    while(!dq.empty()){
        auto now = dq.front();
        dq.pop_front();
        if(vis[now])continue;
        vis[now] = true;
        // cout<<now<<' '<<dist[now]<<endl;
        int nxt = now*10%n;
        if(dist[nxt] == -1||dist[nxt]>dist[now]){
            if(vis[nxt])continue;
            dist[nxt] = dist[now];
            pre[nxt] = now;
            dq.push_front(nxt);
        }
        nxt = (now+1)%n;
        if(dist[nxt] == -1){
            if(vis[nxt])continue;
            dist[nxt] = dist[now]+1;
            pre[nxt] = now;
            dq.push_back(nxt);
        }
    }
    cout<<dist[0];
}