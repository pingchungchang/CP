#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

int n,q;
struct Q{
    int tp,id,p,val,k;
    int l,r;
    Q(){}
    Q(int tt,int ii,int pp,int vv,int kk,int lll = 0,int rrr = 0){
        tp = tt,id = ii,p = pp,val = vv,k = kk;
        l = lll,r = rrr;
    }
    bool operator<(Q &b)const{
        return val<b.val;
    }
};
const int mxn = 2e5+10;
int bit[mxn*4];
pii idx[mxn];
int vals[mxn];
vector<int> st;
vector<int> tree[mxn];
void dfs(int now,int par){
    st.push_back(now);
    idx[now].fs = st.size();
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs(nxt,now);
    }
    st.push_back(now);
    idx[now].sc = st.size();
}
void modify(int p,int v){
    for(;p<mxn*4;p += p&-p)bit[p] += v;
    return;
}
int getval(int s,int e){
    int re = 0;
    for(;e>0;e -= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s)re -= bit[s];
    return re;
}

int ans[mxn];
vector<Q> req;
void f(Q &now){
    if(!now.tp){
        ans[now.id] += getval(now.l,now.r)*now.k;
    }
    else{
        modify(now.p,now.k);
    }
    return;
}
vector<Q> comb;
vector<Q> ql,qr;
void init(int p){
    modify(p,-getval(p,p));
}
void dc(int l,int r){
    if(l == r)return;
    // cout<<l<<' '<<r<<endl;
    int mid = (l+r)>>1;
    dc(l,mid);
    dc(mid+1,r);
   	comb.clear();
    ql.clear();qr.clear();
    for(int i = mid;i>=l;i--)ql.push_back(req[i]);
    for(int i = r;i>mid;i--)qr.push_back(req[i]);
    // cout<<l<<' '<<r<<":"<<ql.size()<<' '<<qr.size()<<endl;
    while(!ql.empty()&&!qr.empty()){
        // cout<<ql.size()<<' '<<qr.size()<<":";
        if(ql.back().val<=qr.back().val){
            if(ql.back().tp)f(ql.back());
            comb.push_back(ql.back());
            ql.pop_back();
        }
        else{
            if(!qr.back().tp)f(qr.back());
            comb.push_back(qr.back());
            qr.pop_back();
        }
    }
    // cout<<l<<' '<<r<<' '<<":";for(int i = 0;i<comb.size();i++)cout<<comb[i].tp<<','<<(comb[i].tp?comb[i].p:comb[i].l)<<','<<(comb[i].tp?comb[i].val:comb[i].r)<<','<<comb[i].val<<' ';cout<<endl;
    while(!ql.empty()){
        comb.push_back(ql.back());
        ql.pop_back();
    }
    while(!qr.empty()){
        if(!qr.back().tp)f(qr.back());
        comb.push_back(qr.back());
        qr.pop_back();
    }
    for(int i = 0;i<comb.size();i++){
        req[i+l] = comb[i];
        if(comb[i].tp)init(comb[i].p);
    }
    // cout<<l<<' '<<r<<' '<<":";for(int i = l;i<=r;i++)cout<<req[i].tp<<','<<(req[i].tp?req[i].p:req[i].l)<<','<<(req[i].tp?req[i].val:req[i].r)<<','<<req[i].k<<','<<req[i].val<<' ';cout<<endl;
    // for(int i = 0;i<q;i++)cout<<ans[i]<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    vector<int> all = {-1};
    for(int i =1;i<=n;i++){
        cin>>vals[i];
        all.push_back(vals[i]);
    }
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,1);
    for(int i = 1;i<=n;i++){
        req.push_back(Q(1,0,idx[i].fs,vals[i],1));
    }
    for(int i = 0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1){
            ans[i] = -1;
            int pos,val;
            cin>>pos>>val;
            req.push_back(Q(1,-1,idx[pos].fs,vals[pos],-1));
            req.push_back(Q(1,-1,idx[pos].fs,val,1));
            vals[pos] = val;
            all.push_back(val);
        }
        else{
            int pos;
            int l,r;
            cin>>pos>>l>>r;
            int pl = idx[pos].fs;
            int pr = idx[pos].sc;
            req.push_back(Q(0,i,-1,l-1,-1,pl,pr));
            req.push_back(Q(0,i,-1,r,1,pl,pr));
            all.push_back(l-1);
            all.push_back(r);
        }
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    // for(auto &i:all)cout<<i<<' ';cout<<endl;
    for(auto &i:req){
        i.val = lower_bound(all.begin(),all.end(),i.val)-all.begin();
    }
    //for(int i = 0;i<req.size();i++)cout<<req[i].tp<<','<<(req[i].tp?req[i].p:req[i].l)<<','<<(req[i].tp?req[i].val:req[i].r)<<','<<req[i].val<<' ';cout<<endl;
    dc(0,req.size()-1);
    for(int i = 0;i<q;i++){
        if(ans[i]!= -1)cout<<ans[i]<<'\n';
    }
    return 0;
}
/*
5 11
10 6 3 0 7
5 4
2 1
2 3
3 4
2 3 2 4
1 5 0
1 1 6
1 1 6
2 4 0 5
2 5 2 6
2 2 8 10
1 1 10
1 5 5
1 1 9
1 5 6


1
2
0
0
*/