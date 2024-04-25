#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(vector<int>a,vector<int>b){
        return a[4]>b[4];
    }
};
int main(){
    int r,c;
    vector<pair<int,int>> directions;
    directions.push_back(make_pair(0,1));
    directions.push_back(make_pair(0,-1));
    directions.push_back(make_pair(-1,0));
    directions.push_back(make_pair(1,0));
    while(cin>>r){
        if(r == 0)return 0;
        cin>>c;
        vector<vector<int>> m(r,vector<int>(c,INT_MAX));
        int k;
        int st,en;
        cin>>st>>en;
        pair<int ,int> s = make_pair(0,st);
        pair<int,int> e = make_pair(r-1,en);
        cin>>k;
        for(int i = 0;i<k;i++){
            int a,b;
            cin>>a>>b;
            m[a][b] =1;
        } 
        priority_queue<vector<int>,vector<vector<int>>,Compare>q;
        q.push({s.first,s.second,-1,0,0});
        while(!q.empty()){
            vector<int> now = q.top();
            q.pop();
            if(now[0]>=0&&now[0]<r&&now[1]>=0&&now[1]<c&&m[now[0]][now[1]] != -1&&m[now[0]][now[1]] >now[4]){
                m[now[0]][now[1]]= now[4];
                for(int i = 0;i<4;i++){
                    if(directions[i].first == now[2]&&directions[i].second == now[3]){
                        q.push({now[0]+directions[i].first,now[1]+directions[i].second,directions[i].first,directions[i].second,now[4]});
                    }
                    else q.push({now[0]+directions[i].first,now[1]+directions[i].second,directions[i].first,directions[i].second,now[4]+1});
                    // cout<<now[0]<<now[1]<<now[2]<<now[3]<<now[4]<<endl;
                }
            }
        }
        if(m[e.first][e.second] == INT_MAX) printf("fail\n");
        else printf("%d\n",m[e.first][e.second]);
    }
}
//fail