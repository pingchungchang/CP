#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second

struct node{
    ll l,r;
    mutable ll val;
    node(){l = r = val = 0;}
    node(ll s,ll e,ll vv){
        l = s,r = e,val = vv;
    }
    bool operator<(const node &b)const{
        return l<b.l;
    }
};

set<node> chtholly;

set<node>::iterator split(int p){
    auto it = chtholly.lower_bound(node(p,-1,-1));
    // cout<<p<<":"<<it->l<<' '<<it->r<<' '<<chtholly.size()<<endl;
    if(it != chtholly.end()&&it->l == p)return it;
    it--;
    auto tl = it->l,tr = it->r,tval = it->val;
    chtholly.erase(it);
    chtholly.insert(node(tl,p-1,tval));
    return chtholly.insert(node(p,tr,tval)).fs;
}

void _assign(int s,int e,ll val){
    auto rit = split(e+1);
    auto lit = split(s);
    chtholly.erase(lit,rit);
    chtholly.insert(node(s,e,val));
    return;
}

void add(int s,int e,ll val){
    auto rit = split(e+1);
    auto lit = split(s);
    for(auto it = lit;it != rit;it++)it->val += val;
    return;
}

ll getsum(int s,int e){
    auto rit = split(e+1);
    auto lit = split(s);
    ll re = 0;
    for(auto it = lit;it != rit;it++)re += it->val*(it->r-it->l+1);
    return re;
}

ll getbig(int s,int e){
    auto lit = split(s);
    auto rit = split(e+1);
    ll re = 0;
    for(auto it = lit;it != rit;it++)re = max(re,it->val);
    return re;
}

const int mxn = 5e5+10;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    auto s = clock();
    chtholly.insert(node(0,mxn,0));
    int n;
    cin>>n;
    int q;
    cin>>q;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        // for(auto &j:chtholly)cout<<j.l<<' '<<j.r<<' '<<j.val<<',';cout<<endl;
        _assign(i,i,k);
    }
    // cout<<"HI"<<endl;return 0;
    while(q--){
        if((double)(clock()-s)/CLOCKS_PER_SEC>=1)exit(0);
        int t;
        cin>>t;
        if(t == 2){
            int s,e,v;
            cin>>s>>e>>v;
            _assign(s,e,v);
        }
        else if(t == 1){
            int s,e,v;
            cin>>s>>e>>v;
            add(s,e,v);
        }
        else if(t == 3){
            int s,e;
            cin>>s>>e;
            cout<<getsum(s,e)<<'\n';
        }
        else{
            int s,e;
            cin>>s>>e;
            cout<<getbig(s,e)<<'\n';
        }
    }
    return 0;
}

