#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

vector<ll> all;
vector<pll> v[2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll L,n1,n2;
    cin>>L>>n1>>n2;
    ll pre = 1;
    all.push_back(1);
    all.push_back(0);
    for(int i = 0;i<n1;i++){
        ll c,l;
        cin>>c>>l;
        v[0].push_back({l,c});
        all.push_back(pre+l);
        pre += l;
    }
    pre = 1;
    for(int i = 0;i<n2;i++){
        ll c,l;
        cin>>c>>l;
        v[1].push_back({l,-c});
        all.push_back(pre+l);
        pre += l;
    }
    // cout<<"HIO"<<endl;
    all.push_back(L+1);
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()));
    ll sweep[all.size()];
    memset(sweep,0LL,sizeof(sweep));
    ll ans = 0;
    pre = 1;
    for(auto &i:v[0]){
        sweep[lower_bound(all.begin(),all.end(),pre)-all.begin()] += i.sc;
        pre += i.fs;
        sweep[lower_bound(all.begin(),all.end(),pre)-all.begin()] -= i.sc;
    }
    pre = 1;
    for(auto &i:v[1]){
        sweep[lower_bound(all.begin(),all.end(),pre)-all.begin()] += i.sc;
        pre += i.fs;
        sweep[lower_bound(all.begin(),all.end(),pre)-all.begin()] -= i.sc;
    }
    // for(auto &i:all)cout<<i<<' ';cout<<endl;
    // for(auto &i:sweep)cout<<i<<' ';cout<<endl;
    pre = 0;
    for(int i = 1;i<all.size();i++){
        if(!pre)ans += all[i]-all[i-1];
        pre += sweep[i];
    }
    cout<<ans-1;
}