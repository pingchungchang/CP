#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
int n,k,d;
vector<pair<int,int>>v;
bool f(int now){
    int s = 0;
    map<int,int> cnt;
    int tmp = 0;
    int ans = 0;
    for(int e = 0;e<n;e++){
        int tp = v[e].first;
        tmp += v[e].second;
        cnt[tp]++;
        while(cnt.size()>now){
            tmp -= v[s].second;
            cnt[v[s].first]--;
            if(cnt[v[s].first] == 0){
                cnt.erase(v[s].first);
            }
            s++;
        }
        ans = max(ans,tmp);
    }
    if(ans>=d)return true;
    return false;
}
void solve(){
    cin>>n>>k>>d;
    v = vector<pair<int,int>>(0);
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        if(v.empty()||v.back().first != x){
            v.push_back(make_pair(x,1));
        }
        else v.back().second++;
    }
    n = v.size();
    int l = 1,r = n;
    while(l != r){
        int mid = (l+r)/2;
        //cout<<l<<' '<<r<<' '<<f(mid)<<'\n';
        if(f(mid))r = mid;
        else l = mid+1;
    }
    cout<<l<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
