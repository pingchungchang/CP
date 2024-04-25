#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};
int main(){
    int n,m,y,o;
    scanf("%d %d %d %d\n",&n,&m,&y,&o);
    unordered_map<int,vector<pair<int,int>>> paths;
    vector<int> dist(n+1,INT_MAX);
    for(int i = 0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(i != m-1)scanf("\n");
        paths[a].push_back(make_pair(b,c));
        paths[b].push_back(make_pair(a,c));
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;
    pq.push(make_pair(y,0));
    while(!pq.empty()&&dist[o] == INT_MAX){
        pair<int,int> now = pq.top();
        // cout<<now.first;
        pq.pop();
        if(dist[now.first] == INT_MAX){
            dist[now.first] = now.second;
            for(int i = 0;i<paths[now.first].size();i++){
                pq.push(make_pair(paths[now.first][i].first,paths[now.first][i].second+dist[now.first]));
            }
        }
    }
    cout<<dist[o];
}