#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

const int inf = 1e18;
struct Q{
    int l,r,id,val,tp;
    Q(){}
    Q(int lll,int rrr,int iii,int vv,int ttt){
        l = lll,r = rrr,id = iii,val = vv,tp = ttt;
    }
};
const int mxn = 3e5+10;
int bit[mxn];
vector<int> all;
int ans[mxn],arr[mxn];
void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] += v;
    return;
}
int getval(int s,int e){
    int re = 0;
    for(;e>0;e -= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s)re -= bit[s];
    return re;
}


void dc(int l,int r,vector<Q> &req){
    // cout<<l<<' '<<r<<":";for(auto &i:req)cout<<i.tp<<','<<i.l<<','<<i.r<<','<<i.id<<' ';cout<<endl;
    if(l == r||req.empty()){
        for(auto &i:req){
            if(i.tp)ans[i.id] = all[l];
        }
        return;
    }
    int mid = (l+r)>>1;
    vector<Q> ql,qr;
    for(auto &i:req){
        if(!i.tp){
            if(i.r<=mid){
                modify(i.l,i.val);
                ql.push_back(i);
            }
            else{
                qr.push_back(i);
            }
        }
        else{
            if(getval(i.l,i.r)>=i.val){
                ql.push_back(i);
            }
            else{
                qr.push_back(Q(i.l,i.r,i.id,i.val-getval(i.l,i.r),i.tp));
            }
        }
    }
    for(auto &i:ql){
        if(!i.tp){
            modify(i.l,-i.val);
        }
    }
    dc(l,mid,ql);
    dc(mid+1,r,qr);
    return;
}
void solve(){
    all.clear();
    int n,q;
    cin>>n>>q;
    fill(ans,ans+q,inf);
    vector<Q> req;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        arr[i] = k;
        req.push_back(Q(i,k,1,1,0));
        all.push_back(k);
    }
    for(int i = 0;i<q;i++){
        Q now;
        cin>>now.tp;
        if(now.tp == 1){
            now.id = i;
            cin>>now.l>>now.r>>now.val;
            req.push_back(now);
        }
        else if(now.tp == 2){
            now.tp = 0;
            cin>>now.l>>now.r;
            now.val = 1;
            all.push_back(now.r);
            Q pre = now;
            pre.r = arr[now.l];
            pre.val = -1;
            arr[now.l] = now.r;
            req.push_back(pre);
            req.push_back(now);
        }
        else{
            int a;
            cin>>a>>a;
            ans[i] = 7122;
        }
    }
    all.push_back(-inf);
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto &i:req){
        if(!i.tp)i.r = lower_bound(all.begin(),all.end(),i.r)-all.begin();
    }
    for(int i = req.size()-1;i>=0;i--){
        auto tmp = req[i];
        if(!tmp.tp){
            arr[tmp.l] = tmp.r;
        }
    }
    // for(auto &i:all)cout<<i<<' ';cout<<endl;
    dc(0,all.size()-1,req);
    for(int i = 0;i<q;i++){
        if(ans[i] != inf){
            cout<<ans[i]<<'\n';
        }
    }
    return;
}

main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}