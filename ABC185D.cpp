#include <bits/stdc++.h>
using namespace std;

map<string,vector<string>> mp;
map<string,int> deg;
set<string> vis;

int main(){
    int n;
    cin>>n;
    while(n--){
        string a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        deg[b]++;
    }
    queue<string> q;
    for(auto &i:mp){
        if(deg[i.first] == 0){
            q.push(i.first);
        }
    }
    while(!q.empty()){
        auto now = q.front();
        vis.insert(now);
        q.pop();
        for(auto &nxt:mp[now]){
            deg[nxt]--;
            if(!deg[nxt])q.push(nxt);
        }
    }
    for(auto &i:mp){
        if(vis.find(i.first) == vis.end()){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}