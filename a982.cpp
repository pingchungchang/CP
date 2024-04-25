#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(vector<int> a,vector<int> b){
        return a[2]>b[2];
    }
};
int main(){
    int n;
    cin>>n;
    vector<string> m(n);
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        m[i] = s;
    }
    vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
    if(m[n-2][n-2]  == '#'){
        printf("No solution!");
        return 0;
    }
    vector<int> s = {1,1,0};
    priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
    pq.push(s);
    while(!pq.empty()){
        vector<int> now = pq.top();
        // printf("%d %d\n",now[0],now[1]);
        pq.pop();
        if(distance[n-2][n-2] != INT_MAX) break;
        if(now[0]<m.size()&&now[1]<m.size()&&now[1]>=0&&now[0]>=0&&distance[now[0]][now[1]] == INT_MAX&&m[now[0]][now[1]] != '#'){
            distance[now[0]][now[1]] = now[2];
            pq.push({now[0]+1,now[1],now[2]+1});
            pq.push({now[0]-1,now[1],now[2]+1});
            pq.push({now[0],now[1]-1,now[2]+1});
            pq.push({now[0],now[1]+1,now[2]+1});
        }
    }
    if(distance[n-2][n-2] == INT_MAX){
        printf("No solution!");
        return 0;
    }
    else printf("%d",distance[n-2][n-2]+1);
}