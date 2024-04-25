#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long

const ll mxn = 2e5+10;
ll arr[mxn];
vector<ll> high[33];
vector<ll> pref[33];

void f(ll i){
    for(int j = i-1;j>=0;j--){
        high[j].clear();
        pref[j] = {0};
    }
    for(auto &j:high[i]){
        j^=(1LL<<i);
        int tmp = 32;
        for(int kk = 0;kk<32;kk++){
            if((1LL<<kk)&j)tmp = kk;
        }
        high[tmp].push_back(j);
    }
    for(int j = i-1;j>=0;j--){
        pref[j] = {0};
        sort(high[j].rbegin(),high[j].rend());
        for(auto &kk:high[j])pref[j].push_back(pref[j].back()+kk);
    }
    high[i].clear();

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i = 0;i<n;i++)cin>>arr[i];
    for(int i = 0;i<n;i++){
        int tmp = 32;
        for(int j = 31;j>=0;j--){
            if((1LL<<j)&arr[i]){
                tmp = j;
                break;
            }
        }
        high[tmp].push_back(arr[i]);
    }
    for(auto &i:high)sort(i.rbegin(),i.rend());
    for(int i = 0;i<33;i++){
        pref[i].push_back(0);
        for(auto &j:high[i]){
            pref[i].push_back(pref[i].back()+j);
        }
    }
    ll ans = 0;
    for(int i = 31;i>=0;i--){
        if(high[i].size()>=k){
            if(i == 0){
                ans |=1;
                break;
            }
            ans |= (1LL<<i);
            f(i);
            continue;
        }
        ll cnt = k-high[i].size(),total = 0;
        for(int j = i-1;j>=0;j--){
            ll c = min(cnt,(ll)high[j].size());
            total += c*(1LL<<i)-pref[j][c];
            cnt -= c;
        }
        if(cnt != 0)total += (1LL<<i)*cnt;
        if(total>m){
            for(auto &j:high[i]){
                j^=(1LL<<i);
                int tmp = 32;
                for(int kk = 0;kk<32;kk++){
                    if((1LL<<kk)&j)tmp = kk;
                }
                high[tmp].push_back(j);
            }
            for(int j = i-1;j>=0;j--){
                pref[j] = {0};
                sort(high[j].rbegin(),high[j].rend());
                for(auto &kk:high[j])pref[j].push_back(pref[j].back()+kk);
            }
        }
        else{
            ans |= (1LL<<i);
            m -= total;
            f(i);
        }
    }
    cout<<ans;
}