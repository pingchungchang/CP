#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(vector<int>a,vector<int> b){
        return a[3]>b[3];
    }
};
int main(){
    int a,b,c;
    vector<int> start;
    vector<int> finish;
    while(cin>>a>>b>>c){
        if(a == 0&&b == 0&&c == 0) return 0;
        vector<vector<vector<char>>> m(a,vector<vector<char>>(b,vector<char>(c,'0')));
        for(int i = 0;i<m.size();i++){
            for(int j = 0;j<m[0].size();j++){
                for(int k = 0;k<m[0][0].size();k++){
                    char f;
                    cin>>f;
                    if(f == 'S') start = {i,j,k};
                    if(f == 'E') finish = {i,j,k};
                    m[i][j][k] = f;
                }
            }
        }
        vector<vector<vector<int>>> distance(a,vector<vector<int>>(b,vector<int>(c,INT_MAX)));
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        pq.push({start[0],start[1],start[2],0});
        //cout<<start[0]<<' '<<start[1]<<' '<<start[2]<<' ';
        while(!pq.empty()){
            vector<int> now = pq.top();
            pq.pop();
            if(now[0]>=a||now[0]<0||now[1]>=b||now[1]<0||now[2]>=c||now[2]<0){
                continue;
            }
            if(distance[finish[0]][finish[1]][finish[2]] != INT_MAX) break;
            if(m[now[0]][now[1]][now[2]] != '#'&&distance[now[0]][now[1]][now[2]] == INT_MAX){
                //printf("%d %d %d %d\n",now[0],now[1],now[2],now[3]);
                distance[now[0]][now[1]][now[2]] = now[3];
                pq.push({now[0]+1,now[1],now[2],now[3]+1});
                pq.push({now[0]-1,now[1],now[2],now[3]+1});
                pq.push({now[0],now[1]+1,now[2],now[3]+1});
                pq.push({now[0],now[1]-1,now[2],now[3]+1});
                pq.push({now[0],now[1],now[2]+1,now[3]+1});
                pq.push({now[0],now[1],now[2]-1,now[3]+1});
            }
        }
        if(distance[finish[0]][finish[1]][finish[2]] == INT_MAX) cout<<"Trapped!\n";
        else printf("Escaped in %d minute(s).\n",distance[finish[0]][finish[1]][finish[2]]);
    }
}
