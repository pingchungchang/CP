#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ld long double
#define ll long long
#define fs first
#define sc second
const ll mxn = 1e5+10;
const ll inf = 5e18;
struct line{
    ll m,b;
    line(){
        m = 0;
        b = -inf;
    }
    line(ll mm,ll bb){
        m = mm,b = bb;
    }
    ll operator()(ll k){
        return m*k+b;
    }
};
ll n,k,R,C;
ll arr[mxn],pref1[mxn],pref2[mxn];
ll dp[mxn];

bool check(pair<line,ll> a,pair<line,ll> b,pair<line,ll> c,ll d){
    return (a.sc+d>=n||b.fs(pref2[a.sc+d+1])<=c.fs(pref2[a.sc+d+1]))&&(__int128_t)(b.fs.m-a.fs.m)*(a.fs.b-c.fs.b)<=(__int128_t)(a.fs.b-b.fs.b)*(c.fs.m-a.fs.m);
}
ll f(ll d){
    if(k*d<n)return -inf;
    fill(dp,dp+mxn,-inf);
    dp[0] = 0;
    deque<pair<line,int>> dq;
    for(int i = 0;i<k;i++){
        dq.clear();
        dq.push_back({line(i,dp[i]+pref1[i]-pref2[i]*(i)),i});
        for(ll j = i+1;j<=min(n,d*(i+1));j++){
            while(dq.front().sc<j-d)dq.pop_front();
            while(dq.size()>=2&&dq[0].fs(pref2[j])<=dq[1].fs(pref2[j]))dq.pop_front();
            ll tt = dq[0].fs(pref2[j])-pref1[j];
            line tmp;
            tmp.m = j;
            tmp.b = dp[j]+pref1[j]-pref2[j]*(j);
            while(dq.size()>=2&&check(dq[dq.size()-2],dq.back(),{tmp,j},d))dq.pop_back();
            dq.push_back({tmp,j});
            dp[j] = tt;
            // cout<<i<<' '<<j<<' '<<dq[0].fs.m<<' '<<dq[0].fs.b<<',';
        }
        // cout<<i<<' '<<d<<":";
        // for(int j = 1;j<=n;j++)cout<<dp[j]+C*pref2[j]<<' ';cout<<endl;
    }
    return dp[n]+C*pref2[n];
}
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(pref1,pref1+mxn,0LL);
    fill(pref2,pref2+mxn,0LL);
    cin>>n>>k>>R>>C;
    for(int i = 1;i<=n;i++){
        cin>>pref2[i];
        pref1[i] = pref2[i]*i;
        pref2[i] += pref2[i-1];
        pref1[i] += pref1[i-1];
    }
    assert(k<n);
    ll l = (n+k-1)/k,r = n-k+1;
    if(f(r)<R){
        cout<<"-1";
        return 0;
    }
    while(l != r){
        ll mid = (l+r)>>1;
        if(f(mid)>=R)r = mid;
        else l = mid+1;
    }
    if(f(l)>=R)cout<<l;
    else cout<<-1;
    // cout<<endl;
    // cout<<f(l);
    // cout<<endl;
    // cout<<f(6);
}