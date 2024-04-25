#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 101;
const int inf = 1e9+10;
struct node{
    int id,s,e;
    node(){}
    node(int ii,int ss,int ee){
        id = ii,s = ss,e = ee;
    }
};
vector<node> req[mxn];
int ans[mxn*mxn*mxn];
int paths[mxn][mxn];
int dist[mxn][mxn];
int n,m,q;

void dfs(int l,int r){
    // cout<<l<<' '<<r<<':'<<endl;
    // for(int i = 0;i<n;i++){
    //     for(int j= 0;j<n;j++)cout<<dist[i][j]<<' ';cout<<endl;
    // }
    if(l == r){
        for(auto &j:req[l]){
            ans[j.id] = dist[j.s][j.e];
        }
        return;
    }
    int mid = (l+r)>>1;
    int pre[mxn][mxn];
    for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)pre[i][j] = dist[i][j];
    for(int i = l;i<=mid;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    dfs(mid+1,r);
    for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)dist[i][j] = pre[i][j];
    for(int i = mid+1;i<=r;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    dfs(l,mid);
    for(int i =0;i<n;i++)for(int j = 0;j<n;j++)dist[i][j] = pre[i][j];
    return;
}

int main(){
    cin>>n>>m>>q;
    for(auto &i:dist)for(auto &j:i)j = inf;
    for(int i = 0;i<n;i++)dist[i][i] = 0;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b],c);
    }
    for(int i = 0;i<q;i++){
        int a,b,c;
        cin>>c>>a>>b;
        req[c].push_back(node(i,a,b));
    }
    dfs(0,n-1);
    for(int i = 0;i<q;i++)cout<<(ans[i]>=inf?-1:ans[i])<<'\n';
}