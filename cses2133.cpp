#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];
int cnt,n,m,k,q;
vector<pair<int,int>> segtree[mxn*4+4];
vector<pair<int,int>> st;
int ans[mxn];

int root(int k){
    return k == dsu[k]?k:root(dsu[k]);
}
void onion(int a,int b){
    int ra = root(a),rb = root(b);
    if(ra == rb){
        st.push_back({0,0});
        return;
    }
    cnt--;
    if(sz[rb]>sz[ra])swap(ra,rb);
    dsu[rb] = ra;
    sz[ra] += sz[rb];
    st.push_back({ra,rb});
    return;
}
void undo(){
    assert(!st.empty());
    auto now = st.back();
    st.pop_back();
    if(!now.fs)return;
    cnt++;
    dsu[now.sc] = now.sc;
    sz[now.fs]-= sz[now.sc];
    return;
}
void dfs(int now,int l,int r){
    for(auto &i:segtree[now])onion(i.fs,i.sc);
    if(l == r){
        ans[l] = cnt;
    }
    else{
        int mid = (l+r)>>1;
        dfs(now*2+1,l,mid);
        dfs(now*2+2,mid+1,r);
    }
    for(auto &i:segtree[now])undo();
    // cout<<now<<' '<<l<<' '<<r<<":";
    // for(auto &i:segtree[now])cout<<i.fs<<' '<<i.sc<<',';cout<<endl;
    return;
}
void modify(int now,int l,int r,int s,int e,pii v){
    if(s<=l&&e>=r){
        segtree[now].push_back(v);
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=s)modify(now*2+1,l,mid,s,e,v);
    if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
}

vector<pii> tmp;
vector<pii> all;
pii dur[mxn];
pair<int,pii> mv[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i = 1;i<=n;i++){
        dsu[i] = i;
        sz[i] = 1;
    }
    cnt = n;
    for(int i = 1;i<=m;i++){
        pii t;
        cin>>t.fs>>t.sc;
        tmp.push_back({min(t.fs,t.sc),max(t.fs,t.sc)});
        all.push_back(tmp.back());
    }
    for(int i = 1;i<=q;i++){
        cin>>mv[i].fs>>mv[i].sc.fs>>mv[i].sc.sc;
        all.push_back({min(mv[i].sc.fs,mv[i].sc.sc),max(mv[i].sc.fs,mv[i].sc.sc)});
        mv[i].sc = {min(mv[i].sc.fs,mv[i].sc.sc),max(mv[i].sc.fs,mv[i].sc.sc)};
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto &i:tmp){
        auto pos = lower_bound(all.begin(),all.end(),i)-all.begin();
        dur[pos].fs = 0;
        dur[pos].sc++;
    }
    tmp.clear();
    for(int i = 1;i<=q;i++){
        auto pos = lower_bound(all.begin(),all.end(),mv[i].sc)-all.begin();
        if(mv[i].fs == 1){
            if(dur[pos].sc == 0){
                dur[pos].fs = i;
            }
            dur[pos].sc++;
        }
        else{
            dur[pos].sc--;
            if(dur[pos].sc == 0){
                modify(0,0,q,dur[pos].fs,i-1,all[pos]);
                dur[pos].fs = 0;
            }
        }
    }
    for(int i = 0;i<all.size();i++){
        if(dur[i].sc != 0)modify(0,0,q,dur[i].fs,q,all[i]);
    }
//    return 0;
    dfs(0,0,q);
    for(int i = 0;i<=q;i++)cout<<ans[i]<<' ';
    return 0;
}
