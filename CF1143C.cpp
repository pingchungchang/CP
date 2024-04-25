#include <bits/stdc++.h>
using namespace std;

struct node{
    int par;
    vector<int> childs;
    int val;
    int sum;
    node(){}
};
vector<node> tree;
priority_queue<int,vector<int>,greater<int>> pq;
void dfs(int now){
    for(auto nxt:tree[now].childs){
        dfs(nxt);
        tree[now].sum += tree[nxt].val;
    }
    if(tree[now].sum == 0&&tree[now].val == 0)pq.push(now);
}
int main(){
    int n;
    cin>>n;
    tree = vector<node>(n+1,node());
    int r;
    for(int i = 1;i<=n;i++){
        int p,c;
        cin>>p>>c;
        if(p != -1)tree[p].childs.push_back(i);
        else r = i;
        tree[i].par = p;
        tree[i].val = 1-c;
        tree[i].sum = 0;
    }
    dfs(r);
    if(pq.empty())cout<<-1;
    else{
        while(!pq.empty()){
            cout<<pq.top()<<' ';
            pq.pop();
        }
    }
}
