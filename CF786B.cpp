#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct node{
    int idx;
    node(){}
};
const int mxn = 1e5+10;
vector<pll> paths[mxn*4];
int idx[mxn];
ll dist[mxn*4];
node seg1[mxn*4],seg2[mxn*4];
bitset<mxn*4> vis;
int idcnt = 1;

void build1(int now,int l,int r){
    seg1[now].idx = idcnt++;
//    cout<<now<<' '<<l<<' '<<r<<":"<<endl;
    if(l == r){
        idx[l] = seg1[now].idx;
        return;
    }
    int mid = (l+r)>>1;
    build1(now*2+1,l,mid);
    build1(now*2+2,mid+1,r);
    paths[seg1[now].idx].push_back({seg1[now*2+1].idx,0});
    paths[seg1[now].idx].push_back({seg1[now*2+2].idx,0});
    return;
}
void build2(int now,int l,int r){
    seg2[now].idx = idcnt++;
    if(l == r){
        seg2[now].idx = idx[l];
        return;
    }
    int mid = (l+r)>>1;
    build2(now*2+1,l,mid);
    build2(now*2+2,mid+1,r);
    paths[seg2[now*2+1].idx].push_back({seg2[now].idx,0});
    paths[seg2[now*2+2].idx].push_back({seg2[now].idx,0});
    return;
}
vector<int> buf;
void get1(int now,int l,int r,int s,int e){
    if(s<=l&&e>=r){
        buf.push_back(seg1[now].idx);
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=s)get1(now*2+1,l,mid,s,e);
    if(mid<e)get1(now*2+2,mid+1,r,s,e);
    return;
}
void get2(int now,int l,int r,int s,int e){
    if(s<=l&&e>=r){
        buf.push_back(seg2[now].idx);
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=s)get2(now*2+1,l,mid,s,e);
    if(mid<e)get2(now*2+2,mid+1,r,s,e);
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int s;
    cin>>s;
    build1(0,1,n);
    build2(0,1,n);
//    for(int i = 1;i<=n;i++)cout<<idx[i]<<' ';cout<<endl<<endl;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            ll u,v,w;
            cin>>u>>v>>w;
            paths[idx[u]].push_back({idx[v],w});
        }
        else if(t == 2){
            buf.clear();
            ll l,r,u,w;
            cin>>u>>l>>r>>w;
            get1(0,1,n,l,r);
            for(auto &i:buf)paths[idx[u]].push_back({i,w});
        }
        else{
            buf.clear();
            ll l,r,u,w;
            cin>>u>>l>>r>>w;
            get2(0,1,n,l,r);
            for(auto &i:buf)paths[i].push_back({idx[u],w});
        }
//        for(auto &i:buf)cout<<i<<',';cout<<endl;
    }
    const ll inf = 1e18;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,idx[s]});
    fill(dist,dist+mxn*4,inf);
    dist[idx[s]] = 0;
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if(vis[now.sc])continue;
        vis[now.sc] = true;
        for(auto nxt:paths[now.sc]){
            if(dist[nxt.fs]>dist[now.sc]+nxt.sc){
            	dist[nxt.fs] = dist[now.sc]+nxt.sc;
                pq.push({dist[now.sc]+nxt.sc,nxt.fs});
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(dist[idx[i]]>=inf)cout<<-1<<' ';
        else cout<<dist[idx[i]]<<' ';
    }
    return 0;
}
