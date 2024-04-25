#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")
const int mxn = 5e5+10;
#define pii pair<int,int>
#define fs first
#define sc second
#define push_back emplace_back
vector<pair<int,int>> ps,ss;
vector<pii> segtree[mxn*4];
int dsu[mxn];
int sz[mxn];
int ans[mxn];
int cnt;
int n;
int root(int k){
    while(k != dsu[k])k = dsu[k];
    return k;
}
void onion(int a,int b){
	int ra = root(a),rb  = root(b);
    if(ra != rb){
        cnt--;
    }
    if(sz[ra]<sz[rb])swap(ra,rb);
    if(ra == rb){
        ps.push_back(-1,-1);
        ss.push_back(-1,-1);
    }
    else{
        ps.push_back(rb,rb);
        ss.push_back(ra,sz[ra]);
        sz[ra] += sz[rb];
        dsu[rb] = ra;
    }
//    cout<<"union:";for(int i = 0;i<=n;i++)cout<<dsu[i]<<' ';cout<<endl;
    return;
}
void undo(){
    if(ps.back().fs != -1){
    if(ps.back().first != dsu[ps.back().first])cnt++;
        dsu[ps.back().first] = ps.back().second;
        sz[ss.back().first] = ss.back().second;
    }
    ps.pop_back();
    ss.pop_back();
// 	cout<<"undo:";for(int i = 0;i<=n;i++)cout<<dsu[i]<<' ';
    return;
}
struct Q{
    int s,e;
    int a,b;
    int tp;
    Q(){}
};
Q req[mxn];
void modify(int now,int l,int r,int s,int e,pii v){
    if(s<=l&&e>=r){
        segtree[now].push_back(v.fs,v.sc);
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=s)modify(now*2+1,l,mid,s,e,v);
    if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
    return;
}
void dfs(int now,int l,int r){
//	cout<<l<<' '<<r<<':';for(auto &i:segtree[now])cout<<i.fs<<' '<<i.sc<<',';cout<<endl;
    for(auto &i:segtree[now])onion(i.fs,i.sc);
    int mid = (l+r)>>1;
    if(l == r){
        ans[l] = cnt;
    }
    else{
        dfs(now*2+1,l,mid);
        dfs(now*2+2,mid+1,r);
    }
    while(!segtree[now].empty()){
        undo();
        segtree[now].pop_back();
    }
    return;
}
void solve(){
    ps.clear();ss.clear();
    vector<pair<int,int>> all;
    int m,q;
    cin>>n>>m>>q;
    cnt = n;
    for(int i = 0;i<=n;i++)dsu[i] = i;
    for(int i = 0;i<=n;i++)sz[i] = 1;
    for(int i = 0;i<m;i++){
        cin>>req[i].a>>req[i].b;
        if(req[i].a>req[i].b)swap(req[i].a,req[i].b);
        all.push_back(req[i].a,req[i].b);
        req[i].s = i;
        req[i].e = m+q;
    }
    for(int i = 0;i<q;i++){
        char c;
        cin>>c;
        if(c == 'N')req[i+m].tp = 0;
        else req[i+m].tp = 1;
        cin>>req[i+m].a>>req[i+m].b;
        if(req[i+m].a>req[i+m].b)swap(req[i+m].a,req[i+m].b);
        all.push_back(req[i+m].a,req[i+m].b);
        req[i+m].s = i+m;
        req[i+m].e = m+q;
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    int arr[all.size()];
    fill(arr,arr+all.size(),-1);
    int cnt[all.size()] = {};
    for(int i = 0;i<m+q;i++){
        auto pos = lower_bound(all.begin(),all.end(),make_pair(req[i].a,req[i].b))-all.begin();
        if(req[i].tp){
            req[i].s = m+q;
            cnt[pos]--;
            if(cnt[pos] == 0){
                req[arr[pos]].e = i-1;
            }
        }
        else{
            cnt[pos]++;
            if(cnt[pos] != 1){
                req[i].s = req[i].e = m+q;
            }
            else{
                arr[pos] = i;
            }
        }
    }
    for(int i = 0;i<m+q;i++){
        if(req[i].s == m+q) continue;
        if(!req[i].tp)modify(0,m-1,m+q,req[i].s,req[i].e,{req[i].a,req[i].b});
    }
    dfs(0,m-1,m+q);
    for(int i = m;i<m+q;i++)cout<<ans[i]<<'\n';
//    cout<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
//    cout<<"done"<<endl;return 0;
}