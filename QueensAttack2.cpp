#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int r = n,c = n;
    unordered_map<pair<int,int>,int> obstacles;
    cin>>r>>c;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        obstacles[make_pair(a,b)] = 1;
    }
    int ans = -7;
    queue<vector<int>> q;
    q.push({r,c,1,0});
    q.push({r,c,1,1});
    q.push({r,c,1,-1});
    q.push({r,c,0,-1});
    q.push({r,c,0,1});
    q.push({r,c,-1,1});
    q.push({r,c,-1,-1});
    q.push({r,c,-1,0});
    while(!q.empty()){
        vector<int> now = q.front();
        if(obstacles.count(make_pair(now[0],now[1]))==0&&now[0]>0&&now[0]<=n&&now[1]>0&&now[1]<=n){
            ans++;
            q.push({now[0]+now[2],now[0]+now[3],now[2],now[3]});
        }
    }
    cout<<ans;
}
//cannot use unordered_map with pairs