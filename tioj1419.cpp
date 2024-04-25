#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    vector<pair<ll,ll>> v(T);
    for(int i =0;i<T;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v[i] = make_pair(a*a+b*b,c);
    }
    sort(v.begin(),v.end());
    ll ans =0;
    ll nowbig=0;
    ll nowsmall = 100000;
    for(int i =0;i<T;i++){
        nowsmall = min(nowsmall,v[i].second);
        if(v[i].second>nowbig){
            ans = max(ans,nowbig-nowsmall);
            nowbig = v[i].second;
            nowsmall = v[i].second;
        }
    }
    ans = max(ans,nowbig-nowsmall);
    cout<<ans;
}
