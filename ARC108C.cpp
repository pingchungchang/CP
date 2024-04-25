#include <bits/stdc++.h>
using namespace std;


struct node{
    pair<int,int> par;
    vector<pair<int,int>> childs;
    int val;
    node(){
        val = -1;
        par = make_pair(-1,-1);
    }
};

vector<node> v;
int n,m;
vector<vector<pair<int,int>>> graph;
const int mxn = 1e5*2+10;
bool goneto[mxn] = {};

void dfs(int now){
    goneto[now] = true;
    for(auto nxt:graph[now]){
        if(goneto[nxt.first] == false){
            v[nxt.first].par = make_pair(now,nxt.second);
            v[now].childs.push_back(make_pair(nxt.first,nxt.second));
            dfs(nxt.first);
        }
    }
}

void dfs2(int now){
    pair<int,int>p = v[now].par;
    if(v[p.first].val != p.second){
        v[now].val = p.second;
    }
    for(auto nxt:v[now].childs){
        if(v[now].val == -1&&nxt.second != p.second){
            v[now].val = nxt.second;
        }
        dfs2(nxt.first);
    }
    return;
}


int main(){
    cin>>n>>m;
    graph = vector<vector<pair<int,int>>>(n+1);
    v = vector<node>(n+1,node());
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    goneto[1] = true;
    dfs(1);
    dfs2(1);
    bool ln[mxn] = {};
    for(int i = 1;i<=n;i++){
        for(auto nxt:v[i].childs){
            ln[nxt.second] = true;
        }
    }
    int small = -1;
    for(int i = 1;i<=n;i++){
        if(ln[i] == false){
            small = i;
            break;
        }
    }
    for(int i = 1;i<=n;i++){
        if(v[i].val == -1){
            v[i].val = small;
        }
        cout<<v[i].val<<'\n';
    }
    return 0;
}
