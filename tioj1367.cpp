#include <bits/stdc++.h>
using namespace std;

#define ll long long

int m;

void solve(){
    vector<ll>v1(m),v2(m);
    for(int i = 0;i<m;i++)cin>>v1[i];
    for(int i = 0;i<m;i++)cin>>v2[i];
    sort(v1.begin(),v1.end());
    sort(v2.rbegin(),v2.rend());
    ll ans = 0;
    for(int i = 0;i<m;i++)ans += v1[i]*v2[i];
    cout<<ans<<'\n';
}

int main(){
	while(cin>>m)solve();
}
