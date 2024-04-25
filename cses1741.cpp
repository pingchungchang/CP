#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define _all(A) A.begin(),A.end()
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll inf = 1e6+10;
const ll mxn = 2e5+10;
vector<int> allx,ally;
#define pll pair<ll,ll>
struct node{
    int pl,pr;
    ll tag,sum;
    node(){}
};
node segtree[mxn*32];
int pp = 0;
int newnode(){
    pp++;
    int now = pp;
    segtree[now].pl = segtree[now].pr = segtree[now].tag = segtree[now].sum = 0;
    return pp;
}
void modify(int now,int l,int r,int s,int e,int v){
    // cout<<now<<' '<<l<<' '<<r<<' '<<s<<' '<<e<<' '<<v<<endl;
    if(l>=s&&e>=r){
        segtree[now].tag += v;
        return;
    }
    int mid = l+(r-l)/2;
    if(!segtree[now].pl){
        segtree[now].pl = newnode();
        segtree[now].pr = newnode();
    }
    if(mid>=s)modify(segtree[now].pl,l,mid,s,e,v);
    if(mid<e)modify(segtree[now].pr,mid+1,r,s,e,v);
    segtree[now].sum = 0;
    if(segtree[segtree[now].pl].tag)segtree[now].sum += mid-l+1;
    else segtree[now].sum += segtree[segtree[now].pl].sum;
    if(segtree[segtree[now].pr].tag)segtree[now].sum += r-mid;
    else segtree[now].sum += segtree[segtree[now].pr].sum;
    return;
}
pair<pll,pll> req[mxn];
vector<pair<ll,pll>> mv[mxn];
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>req[i].fs.fs>>req[i].sc.fs>>req[i].fs.sc>>req[i].sc.sc;
        req[i].sc.sc--;
        allx.push_back(req[i].fs.fs);allx.push_back(req[i].fs.sc);
        ally.push_back(req[i].sc.fs);ally.push_back(req[i].sc.sc);
    }
    allx.push_back(-inf);allx.push_back(inf);
    ally.push_back(-inf);ally.push_back(inf);
    sort(allx.begin(),allx.end());
    sort(ally.begin(),ally.end());
    allx.erase(unique(allx.begin(),allx.end()),allx.end());
    ally.erase(unique(ally.begin(),ally.end()),ally.end());
    for(int j = 1;j<=n;j++){
        auto i = req[j];
        auto x1 = lower_bound(allx.begin(),allx.end(),i.fs.fs)-allx.begin();
        auto x2 = lower_bound(_all(allx),i.fs.sc)-allx.begin();
        auto y1 = i.sc.fs;
        auto y2 = i.sc.sc;
        mv[x1].push_back(make_pair(1LL,make_pair(y1,y2)));
        mv[x2].push_back(make_pair(-1LL,make_pair(y1,y2)));
    }
    ll ans = 0;
    int root = newnode();
    for(int i = 0;i<allx.size();i++){
        if(i != 0)ans += (allx[i]-allx[i-1])*segtree[root].sum;
        for(auto &j:mv[i]){
            modify(root,-inf,inf,j.sc.fs,j.sc.sc,j.fs);
        }
    }
    cout<<ans;
}