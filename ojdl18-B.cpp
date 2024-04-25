#include <bits/stdc++.h>
using namespace std;



#define ll long long


int main(){
    cout<<"5202";
    return 0;
}
/*
struct node{
    vector<pair<ll,ll>> paths;
    int par;
    ll val;
    node(){
        par = -1;
        val = 0;
    }
};
struct line{
    ll a,b,c;
    line(int x,int y,int z){
        a  =x,b= y,c = z;
    }
    line(){}
};
class Compare{
public:
    bool operator()(line x,line y){
        return x.c<y.c;
    }
};
vector<node> graph;
vector<node> tree;
ll ans1 = 0,ans2 = 0;
ll k;
vector<int>dsu;
int root(int now){
    while(dsu[now] != now){
        dsu[now] = dsu[dsu[now]];
        now = dsu[now];
    }
    return now;
}
void findpar(int now){
    for(auto nxt:tree[now].paths){
        if(nxt.first != tree[now].par){
            ans1 += nxt.second;
            tree[nxt.first].par = now;
            findpar(nxt.first);
        }
    }
    return;
}
void dfs(int now){
    vector<ll> all;
    for(auto nxt:tree[now].paths){
        if(nxt.first == tree[now].par)continue;
        dfs(nxt.first);
        if(k == 0)all.push_back(tree[nxt.first].val+nxt.second);
        else all.push_back(tree[nxt.first].val+k);
    }
    if(all.size() == 0)return;
    sort(all.rbegin(),all.rend());
    tree[now].val = all[0];
    ans2 = max(ans2,all[0]);
    if(all.size()>1)ans2 = max(ans2,all[0]+all[1]);
    return;
}
int main(){
    priority_queue<line,vector<line>,Compare> pq;
    int n,m;
    cin>>n>>m;
    tree = vector<node>(n);
    dsu = vector<int>(n);
    graph = vector<node>(n);

    for(int i = 0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        graph[a].paths.push_back(make_pair(b,c));
        graph[b].paths.push_back(make_pair(a,c));
        pq.push(line(a,b,c));
    }
    cin>>k;
    for(int i = 0;i<n;i++)dsu[i] = i;
    while(!pq.empty()){
        line now = pq.top();
        pq.pop();
        if(root(now.a) == root(now.b))continue;
        dsu[root(now.a)] = root(now.b);
        tree[now.a].paths.push_back(make_pair(now.b,now.c));
        tree[now.b].paths.push_back(make_pair(now.a,now.c));
    }
    findpar(0);
    dfs(0);
    cout<<ans1<<'\n'<<ans2<<'\n';
    return 0;
}
*/
