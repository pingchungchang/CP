#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
    int dest;
    ll val;
    int id;
    edge(){}
    edge(int a,ll b,int c){
        dest = a;
        val = b;
        id = c;
    }
};

class Compare{
public:
    bool operator()(edge& a,edge& b){
        return a.val>b.val;
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<edge>> v(n);
    for(int i = 0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        v[a-1].push_back(edge(b-1,c,i+1));
        v[b-1].push_back(edge(a-1,c,i+1));
    }
    priority_queue<edge,vector<edge>,Compare> pq;
    pq.push(edge(0,0,-1));
    vector<int> ans;
    vector<ll> dist(n,LONG_LONG_MAX);
    dist[0] = 0;
    bitset<200010> goneto = {};
    while(!pq.empty()){
        edge now = pq.top();
        pq.pop();
        if(goneto[now.dest] == false){
            ans.push_back(now.id);
            goneto[now.dest] = true;
        }
        else continue;
        //else st.insert(now.dest);
        for(auto nxt:v[now.dest]){
            if(dist[nxt.dest]<=dist[now.dest]+nxt.val)continue;
            dist[nxt.dest] = dist[now.dest]+nxt.val;
            pq.push(edge(nxt.dest,dist[nxt.dest],nxt.id));
        }
    }
    for(auto i:ans)if(i != -1)cout<<i<<' ';
    return 0;
}
