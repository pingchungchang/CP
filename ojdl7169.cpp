#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define fs first
#define sc second
#define ll long long

const int mxn = 3e3+10;
vector<pll> paths[mxn];
const ll inf = 1e9;
ll hen[mxn],oil[mxn];
bitset<mxn> vis[35];
ll vals[35][mxn];
//vals[35-1][mxn-1];
//vals[mxn-1][35-1];
struct node{
    ll pos,val,fuel,hen;
    node(){
        pos = val = fuel = hen = 0;
    }
    node(ll pp,ll vv,ll ff,ll hh){
        pos = pp,val = vv,fuel = ff,hen = hh;
    }
    bool operator<(node &b){
        return val<b.val;
    }
};

class Cmp{
public:
    bool operator()(node &a,node &b){
        return a.val>b.val;
    }
};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N,W,M,F;
    cin>>N>>M>>W>>F;
    for(int i = 1;i<=N;i++)cin>>hen[i];
    for(int i = 1;i<=N;i++)cin>>oil[i];
    for(int i= 0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        paths[a].push_back({b,c});
        paths[b].push_back({a,c});
    }
    ll S,E,B,G;
    cin>>S>>E>>B>>G;
    priority_queue<node,vector<node>,Cmp> pq;
    for(auto &i:vals)for(auto &j:i)j = inf;
    vals[B][S] = 0;
    ll ans = -inf;
    for(int w = 1;w<=W;w++){
//    	cout<<w<<":"<<ans<<endl;
        for(int i = 1;i<=N;i++)for(int j= 0;j<=F;j++){
            pq.push(node(i,vals[j][i],j,w-1));
            vis[j][i] = false;
        }
        while(!pq.empty()){
            auto now = pq.top();
            pq.pop();
            if(vis[now.fuel][now.pos])continue;
//            cout<<now.pos<<' '<<now.fuel<<' '<<now.val<<endl;
            vis[now.fuel][now.pos] = true;
            for(auto nxt:paths[now.pos]){
                for(int j = 0;j<=F-now.fuel;j++){
                    if(j+now.fuel<nxt.sc+now.hen)continue;
                    if(!vis[j+now.fuel-now.hen-nxt.sc][nxt.fs]&&vals[j+now.fuel-now.hen-nxt.sc][nxt.fs] > vals[now.fuel][now.pos]+oil[now.pos]*j){
                        vals[j+now.fuel-now.hen-nxt.sc][nxt.fs] = vals[now.fuel][now.pos]+oil[now.pos]*j;
                        pq.push(node(nxt.fs,vals[j+now.fuel-now.hen-nxt.sc][nxt.fs],j+now.fuel-now.hen-nxt.sc,now.hen));
                    }
                }
            }
        }
//        for(int i = 0;i<=F;i++)cout<<vals[i][E+1]<<' ';cout<<endl;
        for(int i = 0;i<=F;i++)ans = max(ans,G*(w-1)-vals[i][E]);
        for(int i = 1;i<=N;i++)for(int j= 0;j<=F;j++){
            vals[j][i] += hen[i];
        }
    }
    for(int i = 1;i<=N;i++)for(int j= 0;j<=F;j++){
        pq.push(node(i,vals[j][i],j,W));
        vis[j][i] = false;
    }
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if(vis[now.fuel][now.pos])continue;
        vis[now.fuel][now.pos] = true;
        for(auto nxt:paths[now.pos]){
            for(int j = 0;j<=F-now.fuel;j++){
                if(j+now.fuel<nxt.sc+now.hen)continue;
                if(!vis[j+now.fuel-now.hen-nxt.sc][nxt.fs]&&vals[j+now.fuel-now.hen-nxt.sc][nxt.fs] > vals[now.fuel][now.pos]+oil[now.pos]*j){
                    vals[j+now.fuel-now.hen-nxt.sc][nxt.fs] = vals[now.fuel][now.pos]+oil[now.pos]*j;
                    pq.push(node(nxt.fs,vals[j+now.fuel-now.hen-nxt.sc][nxt.fs],j+now.fuel-now.hen-nxt.sc,now.hen));
                }
            }
        }
    }
    for(int i = 0;i<=F;i++)ans = max(ans,G*W-vals[i][E]);
    cout<<ans;
    return 0;
}
