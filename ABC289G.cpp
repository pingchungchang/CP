#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;
ll b[mxn];
pll c[mxn];
ll ans[mxn];
vector<pll> v;

void dc(int l,int r,int ql,int qr){
    // cout<<l<<' '<<r<<' '<<ql<<' '<<qr<<endl;
    int qmid = (ql+qr)>>1;
    pll p = {0,-1};
    for(int i = l;i<=r;i++){
        p = max(p,make_pair(v[i].sc*(c[qmid].fs+v[i].fs),1LL*i));
    }
    // cout<<qmid<<' '<<p.fs<<endl;
    ans[c[qmid].sc] = p.fs;
    if(ql == qr)return;
    if(ql != qmid)dc(l,p.sc,ql,qmid-1);
    dc(p.sc,r,qmid+1,qr);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>b[i];
    for(int i = 1;i<=m;i++){
        c[i].sc = i;
        cin>>c[i].fs;
    }
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1);
    for(int i = 1;i<=n;i++){
        if(v.empty()||v.back().fs != b[i]){
            v.push_back({b[i],1});
        }
        else v.back().sc++;
    }
    for(int i = 1;i<v.size();i++)v[i].sc += v[i-1].sc;
    ll p = 0;
    ll cnt = v[0].sc;
    sort(c+1,c+m+1);
    dc(0,v.size()-1,1,m);
    for(int i = 1;i<=m;i++)cout<<ans[i]<<' ';
}