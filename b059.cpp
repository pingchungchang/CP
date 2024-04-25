#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
        return p1.second<p2.second;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> distance(100,vector<int>(100,INT_MAX));
    unordered_map<pair,int> obstacles;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pair<int,int> p = make_pair(a,b);
        obstacles[p] = 9;
    }
    int x,y;
    cin>>x>>y;
    pair<int,int> start = make_pair(x,y);
    cin>>x>>y;
    pair<int,int> finish = make_pair(x,y);
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,Compare> pq;
    pq.push(make_pair(start,0));
    while(!pq.empty()&&distance[finish.first][finish.second] == INT_MAX){
        pair<pair<int,int>,int> now = pq.top();
        pq.pop();
        if(now.first.first<0||now.first.first>99||now.first.second <0||now.first.second>99){
            continue;
        }
        else if(distance[now.first.first][now.first.second] == INT_MAX){
            distance[now.first.first][now.first.second] = now.second;
            if(obstacles.count(make_pair(now.first.first+1,now.first.second)) == 0){
                pq.push(make_pair(make_pair(now.first.first+3,now.first.second+1),now.second+1));
                pq.push(make_pair(make_pair(now.first.first+3,now.first.second-1),now.second+1));
            }
            if(obstacles.count(make_pair(now.first.first-1,now.first.second)) == 0){
                pq.push(make_pair(make_pair(now.first.first-3,now.first.second-1),now.second+1));
                pq.push(make_pair(make_pair(now.first.first-3,now.first.second-1),now.second+1));
            }
            if(obstacles.count(make_pair(now.first.first,now.first.second+1)) == 0){
                pq.push(make_pair(make_pair(now.first.first+1,now.first.second+3),now.second+1));
                pq.push(make_pair(make_pair(now.first.first-1,now.first.second+3),now.second+1));
            }
            if(obstacles.count(make_pair(now.first.first,now.first.second-1)) == 0){
                pq.push(make_pair(make_pair(now.first.first+1,now.first.second-3),now.second+1));
                pq.push(make_pair(make_pair(now.first.first-1,now.first.second-3),now.second+1));
            }
        }
    }
    if(distance[finish.first][finish.second] == INT_MAX) cout<<"impossible";
    else cout<<distance[finish.first][finish.second];
}
//what is the problem with you??
