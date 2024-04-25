#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(pair<char,int> p1,pair<char,int> p2){
        return p1.second>p2.second;
    }
};
int main(){
    int n;
    while(scanf("%d\n",&n) !=EOF){
        unordered_map<int,vector<pair<char,int>>> m;
        unordered_map<char,int> dist;
        for(int i = 0;i<n;i++){
            char a,b;
            int c;
            scanf("%c %c %d\n",&a,&b,&c);
            dist[a] = INT_MAX;
            dist[b] = INT_MAX;
            m[a].push_back(make_pair(b,c));
            m[b].push_back(make_pair(a,c));
        }
        char s,e;
        scanf("%c %c",&s,&e);
        priority_queue<pair<char,int>,vector<pair<char,int>>, Compare> pq;
        pq.push(make_pair(s,0));
        while(!pq.empty()){
            if(dist[e] != INT_MAX) break;
            pair<char,int> now = pq.top();
            pq.pop();
            if(dist[now.first] ==INT_MAX){
                dist[now.first] = now.second;
                for(int i = 0;i<m[now.first].size();i++){
                    pq.push(make_pair(m[now.first][i].first,m[now.first][i].second+now.second));
                }
            }
        }
        if(dist[e]== INT_MAX)printf("NoRoute\n");
        else printf("%d\n",dist[e]);
        scanf("\n");
    }
}