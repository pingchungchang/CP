#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int mxn = 5e5+10;
map<string,ll> mp;
vector<int> paths[mxn];
ll segtree[mxn*4+4],vals[mxn];
int dep[mxn],link_top[mxn],bs[mxn],par[mxn],sz[mxn],idx[mxn],skillcnt = 0,cnt = 1;

void changeval(int now,int l,int r,int p,int v){
   if(l == r){
    segtree[now] = v;
    return;
   } 
   int mid = (l+r)>>1;
   if(mid>=p)changeval(now*2+1,l,mid,p,v);
   else if(mid<p)changeval(now*2+2,mid+1,r,p,v);
   segtree[now] = segtree[now*2+1]|segtree[now*2+2];
   return;
}
ll getval(int now,int l,int r,int s,int e){
    if(l>=s&&e>=r)return segtree[now];
    int mid = (l+r)>>1;
    if(mid<s)return getval(now*2+2,mid+1,r,s,e);
    else if(mid>=e)return getval(now*2+1,l,mid,s,e);
    else return getval(now*2+1,l,mid,s,e)|getval(now*2+2,mid+1,r,s,e);
}
void dfs1(int now){
    sz[now] = 1;
    for(auto nxt:paths[now]){
        if(nxt == par[now])continue;
        par[nxt] = now;
        dep[nxt] = dep[now]+1;
        dfs1(nxt);
        sz[now] += sz[nxt];
        if(bs[now] == 0||sz[bs[now]]<sz[nxt])bs[now] = nxt;
    }
    return;
}
void dfs2(int now,int top){
    link_top[now] = top;
    idx[now] = cnt++;
    changeval(0,0,mxn,idx[now],vals[now]);
    if(bs[now])dfs2(bs[now],top);
    for(auto nxt:paths[now]){
        if(nxt == par[now]||nxt == bs[now])continue;
        dfs2(nxt,nxt);
    }
    return;
}
ll lca(int a,int b){
    int ta = link_top[a],tb = link_top[b];
    ll re = 0;
    while(ta != tb){
        if(dep[ta]<dep[tb]){
            swap(ta,tb);
            swap(a,b);
        }
        re |= getval(0,0,mxn,idx[ta],idx[a]);
        a = par[ta];ta = link_top[a]; 
    }
    if(dep[a]<dep[b])swap(a,b);
    return (re|getval(0,0,mxn,idx[b],idx[a]));
}
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        if(mp[s] == 0){
            mp[s] = 1LL<<skillcnt;
            skillcnt++;
        }
        vals[i] = mp[s];
    }
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dep[1] = 1;
    dfs1(1);
    dfs2(1,1);
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int s,e;
            cin>>s>>e>>k;
            ll re = 0;
            while(k--){
                string s;
                cin>>s;
                if(mp[s] == 0){
                    mp[s] = 1LL<<skillcnt;
                    skillcnt++;
                }
                re |= mp[s];
            }
            if((re&lca(s,e)) == re)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            int p;
            string s;
            cin>>p>>s;
            if(mp[s] == 0){
                mp[s] = 1LL<<skillcnt;
                skillcnt++;
            }
            changeval(0,0,mxn,idx[p],mp[s]);
        }
    }
    return 0;
}
