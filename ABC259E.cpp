#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mod = 1e9+7;
const ll mxn = 2e5+10;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
vector<ll> all;
map<ll,ll> cnt[mxn];
vector<pll> arr[mxn];
set<pll> st;
ll mad(ll a,ll b){
    a += b;
    a %= mod;
    return a;
}
ll mub(ll a,ll b){
    a = a+mod-b;
    a %= mod;
    return a;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int m;
        cin>>m;
        while(m--){
            int p,k;
            cin>>p>>k;
            arr[i].push_back({p,k});
            all.push_back(p);
        }
    }
    all.push_back(-1);
    all.push_back(0);
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto &i:arr){
        for(auto &j:i){
            j.fs = lower_bound(all.begin(),all.end(),j.fs)-all.begin();
            cnt[j.fs][j.sc]++;
            cnt[j.fs][0] = 1;
        }
    }
    ll total2 = 0;
    ll total = 0;
    for(int i = 2;i<all.size();i++){
        total = mad(total,pw(i,cnt[i].rbegin()->fs));
        total2 = mad(total2,pw(i,cnt[i].rbegin()->fs+1));
    }
    for(int i = 1;i<=n;i++){
        ll tmp = total;
        ll tmp2 = total2;
        for(auto &j:arr[i]){
            if(cnt[j.fs][j.sc] == 1&&cnt[j.fs].rbegin()->fs == j.sc){
                tmp = mub(tmp,pw(j.fs,cnt[j.fs].rbegin()->fs));
                tmp = mad(tmp,pw(j.fs,(++cnt[j.fs].rbegin())->fs));
                tmp2 = mub(tmp2,pw(j.fs,cnt[j.fs].rbegin()->fs+1));
                tmp2 = mad(tmp2,pw(j.fs,(++cnt[j.fs].rbegin())->fs+1));
            }
        }
        st.insert({tmp,tmp2});
    }
    cout<<st.size();
}