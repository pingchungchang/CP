#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    vector<pll> pos;
    for(int i = 0;i<m;i++){
        pll now = make_pair(v[i],-1);
        int p = upper_bound(pos.begin(),pos.end(),now)-pos.begin();
        if(p == pos.size()){
            pos.push_back(make_pair(v[i],i));
        }
        else{
            pos[p] = make_pair(v[i],i);
        }
    }
    vector<ll> big(pos.size());
    big[0] = pos[0].sc;
    for(int i = 1;i<pos.size();i++){
        big[i] = pos[i].sc;
        big[i] = max(big[i],big[i-1]);
    }
    ll ans = INT_MAX;
    for(int i =m;i<n;i++){
        int p = upper_bound(pos.begin(),pos.end(),make_pair(1LL*v[i],1LL*INT_MIN))-pos.begin();
        p--;
        if(p == -1)continue;
        ans = min(ans,i-big[p]);
    }
    if(ans == INT_MAX)cout<<-1;
    else cout<<ans;
}
