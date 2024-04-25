#include <bits/stdc++.h>
using namespace std;

#define ll __int128_t
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
const ll mxn = 2e5+10;
const ll inf = 1e9+10;
const ll inf2 = 1e27;
ll dp[mxn];
ll N,C,D;
struct node{
    ll d,p,g,r;
    node(){}
    bool operator<(node &b){
        return d<b.d;
    }
};
struct SEG{
    int pl,pr;
    pll line;
    ll operator()(ll k){
        return line.fs*k+line.sc;
    }
    SEG(){}
};
int pt = 0;
int root;
SEG segtree[mxn];
int newnode(){
    pt++;
    assert(pt<mxn);
    segtree[pt].pl = segtree[pt].pr = 0;
    segtree[pt].line = {0,-inf2};
    return pt;
}
ll f(pll val,ll k){
    return val.fs*k+val.sc;
}
void addline(int now,int l,int r,pll val){
    if(l == r){
        if(segtree[now](l)<f(val,r))segtree[now].line = val;
        return;
    }
    if(val.fs == segtree[now].line.fs&&val.sc == segtree[now].line.sc)return;
    int mid = (l+r)>>1;
    if(f(val,mid)>segtree[now](mid))swap(segtree[now].line,val);
    if(val.fs>segtree[now].line.fs){
        if(!segtree[now].pr)segtree[now].pr = newnode();
        addline(segtree[now].pr,mid+1,r,val);
    }
    else{
        if(!segtree[now].pl)segtree[now].pl = newnode();
        addline(segtree[now].pl,l,mid,val);
    }
    return;
}
ll getval(int now,int l,int r,int p){
    if(l == r)return segtree[now](p);
    if(!now)return -inf2;
    int mid = (l+r)>>1;
    if(mid>=p)return max(getval(segtree[now].pl,l,mid,p),segtree[now](p));
    else return max(getval(segtree[now].pr,mid+1,r,p),segtree[now](p));
}
node arr[mxn];
void pv(ll ans){
    string s;
    if(ans == 0){
        cout<<0;
    }
    while(ans){
        s += '0'+ans%10;
        ans /=10;
    }
    reverse(s.begin(),s.end());
    cout<<s;

}
string tos(ll ans){
    string s;
    if(ans == 0)return "0";
    while(ans){
        s += '0'+ans%10;
        ans/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tmp;
    cin>>tmp;N = tmp;
    cin>>tmp;C = tmp;
    cin>>tmp;D = tmp;
    ll n = N;
    for(int i = 1;i<=n;i++){
        int ta,tb,tc,td;
        cin>>ta>>tb>>tc>>td;
        arr[i].d = ta,arr[i].p = tb,arr[i].r = tc,arr[i].g = td;
    }
    dp[0] = C;
    root = newnode();
    sort(arr+1,arr+n+1);
    int p = 0;
    for(int i = 1;i<=n;i++){
        while(arr[p].d != arr[i].d){
            if(dp[p]>=0)addline(root,0,inf,make_pair(arr[p].g,dp[p]+arr[p].r-arr[p].g*(arr[p].d+1)));
            p++;
        }
        ll tmp = getval(root,0,inf,arr[i].d);
        dp[i] = tmp-arr[i].p;
    }
    ll ans = C;
    for(int i = 1;i<=n;i++){
        if(dp[i]<0)continue;
        ans = max(ans,dp[i]+arr[i].g*(D-arr[i].d)+arr[i].r);
    }
    pv(ans);
}