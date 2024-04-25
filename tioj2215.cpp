#include <bits/stdc++.h>
using namespace std;

/*
a,b,c
len = dep[a]+dep[c]-2*dep[b](b = min dep between a,c)
*/

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 1e5+10;
pii dp1[mxn],dp2[mxn];
int centree[mxn];
int dep[mxn],sz[mxn],dp[mxn];
int link_top[mxn],par[mxn],bs[mxn];
bool del[mxn];
vector<int> tree[mxn];
int ans = 0;
void find_sz(int now){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par[now])continue;
        if(del[nxt])continue;
        par[nxt] = now;
        find_sz(nxt);
        sz[now] += sz[nxt];
    }
    return;
}
int find_centroid(int now,int tar){
    for(auto nxt:tree[now]){
        if(nxt == par[now])continue;
        if(del[nxt])continue;
        if(sz[nxt]>=tar)return find_centroid(nxt,tar);
    }
    return now;
}
void cd(int now,int fa){
    par[now] = now;
    find_sz(now);
    int cen = find_centroid(now,(sz[now]+1)/2);
    centree[cen] = fa;
    del[cen] = true;
    for(auto nxt:tree[cen]){
        if(del[nxt])continue;
        cd(nxt,cen);
    }
    return;
}
void dfs1(int now){
    sz[now] = 1;
    for(auto nxt:tree[now]){
        if(nxt == par[now])continue;
        par[nxt] = now;
        dep[nxt] = dep[now]+1;
        dfs1(nxt);
        sz[now] += sz[nxt];
        if(!bs[now]||sz[bs[now]]<sz[nxt])bs[now] = nxt;
    }
    return;
}
void dfs2(int now,int top){
    link_top[now] = top;
    if(bs[now])dfs2(bs[now],top);
    for(auto nxt:tree[now]){
        if(nxt == par[now]||nxt == bs[now])continue;
        dfs2(nxt,nxt);
    }
    return;
}
int lca(int a,int b){
    int ta = link_top[a],tb = link_top[b];
    while(ta != tb){
        if(dep[ta]<dep[tb]){
            swap(ta,tb);
            swap(a,b);
        }
        a = par[ta];
        ta = link_top[a];
    }
    if(dep[a]>dep[b])return b;
    else return a;
}
int dist(int a,int b){
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
void modify(int p){
    int pre = p;
    int now = p;
    while(now){
        // cout<<p<<":"<<now<<' '<<pre<<' '<<dp1[now].fs<<' '<<dp1[now].sc<<' '<<dp2[now].fs<<' '<<dp2[now].sc<<":"<<ans<<endl;
        if(dp1[now].sc != pre){
            if(p>=now)ans = max(ans,dist(p,now)+dp1[now].fs);
        }
        else{
            if(p>=now)ans = max(ans,dist(p,now)+dp2[now].fs);
        }
        if(dp1[now].fs<=dist(p,now)){
            if(dp1[now].sc == pre)dp1[now].fs = dist(p,now);
            else{
                swap(dp1[now],dp2[now]);
                dp1[now].fs = dist(p,now);
                dp1[now].sc = pre;
            }
        }
        else if(dp1[now].sc != pre&&dp2[now].fs<=dist(p,now)){
            dp2[now].fs = dist(p,now);
            dp2[now].sc = pre;
        }
        pre = now;
        now =  centree[now];
    }
    return;
}
/*
19
1 1 3 2 4 4 6 3 8 7 9 10 10 2 5 10 17 3 
*/
// #define cin fin
int main(){
    // ifstream fin("input.txt");
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 2;i<=n;i++){
        int p;
        cin>>p;
        // cout<<p<<' '<<i<<'\n';
        tree[p].push_back(i);
        tree[i].push_back(p);
    }
    par[1] = 1;
    cd(1,0);
    par[1] = 1;
    dep[1] = 1;
    dfs1(1);
    dfs2(1,1);
    modify(1);
    assert(ans == 0);
    for(int i = 2;i<=n;i++){
        modify(i);
        // cout<<ans<<' ';
        cout<<ans<<'\n';
    }
    return 0;
}
