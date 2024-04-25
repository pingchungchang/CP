#include <bits/stdc++.h>
using namespace std;


struct node{
    int c,r,b;
    int s,e;
    node(){
        c = 0;
        r = 0;
        b = 0;
    }
};
int n,d;

void solve(){
    cin>>n;
    vector<node> req(n);
    vector<int> all;
    for(int i = 0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        req[i].s = x*24+y;
        req[i].e = req[i].s+z;
        all.push_back(req[i].s);
        all.push_back(req[i].e);
        cin>>req[i].c>>req[i].r>>req[i].b;
        req.push_back(req[i]);
        req.rbegin()->s += 24*d;
        req.rbegin()->e += 24*d;
        all.push_back(req.rbegin()->s);
        all.push_back(req.rbegin()->e);
    }
    int zero;
    cin>>zero;
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto &i:req){
        i.s = lower_bound(all.begin(),all.end(),i.s)-all.begin();
        i.e = lower_bound(all.begin(),all.end(),i.e)-all.begin();
    }
    vector<node> v(all.size(),node());
    for(auto i:req){
        int f = i.s;
        int ls = i.e;
        v[f].c += i.c;
        v[f].r += i.r;
        v[f].b += i.b;
        v[ls].c -= i.c;
        v[ls].r -= i.r;
        v[ls].b -= i.b;
    }
    int mc = 0,mr = 0,mb = 0;
    int nc = 0,nr = 0,nb = 0;
    //for(auto i:all)cout<<i<<' ';cout<<endl;
    for(auto i:v){
        nc += i.c;
        nr += i.r;
        nb += i.b;
        mc = max(nc,mc);
        mr = max(nr,mr);
        mb = max(mb,nb);
    }
    cout<<mc<<' '<<mr<<' '<<mb<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t>>d;
    for(int i = 0;i<t;i++)solve();
}
