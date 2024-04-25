#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct node{
    vector<int> childs;
    int s = -1;
    int ans=-1;
    int parent;
} node;
void findsize(int root,vector<node> &tree){
    if(tree[root].childs.size()==0){
        tree[root].s = 1;
        return;
    }
    else{
        tree[root].s = 1;
        for(int i =0;i<tree[root].childs.size();i++){
            int child = tree[root].childs[i];
            findsize(child,tree);
            tree[root].s+= tree[child].s;
        }
        return;
    }
}
ll findans(int root,vector<node> &tree,int depth){
    if(tree[root].childs.size()==0)return depth;
    ll k = depth;
    for(int i =0;i<tree[root].childs.size();i++){
        k += findans(tree[root].childs[i],tree,depth+1);
    }
    return k;
}

int main(){
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    long long sum = (long long) n*(long long)(n+1)/2;
    vector<node> tree(n+1);
    for(int i =0;i<m;i++){
        int a,b;
        cin>>a>>b;
        sum -= b;
        tree[a].childs.push_back(b);
        tree[b].parent = a;
    }
    int root =(int) sum;
    findsize(root,tree);
    tree[root].ans = findans(root,tree,0);
    queue<int> q;
    for(int i =0;i<tree[root].childs.size();i++){
        q.push(tree[root].childs[i]);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int p = tree[now].parent;
        tree[now].ans = tree[p].ans+n-2*tree[now].s;
        for(int i =0;i<tree[now].childs.size();i++){
            q.push(tree[now].childs[i]);
        }
    }
    for(int i =1;i<=n;i++)cout<<tree[i].ans<<'\n';
}
