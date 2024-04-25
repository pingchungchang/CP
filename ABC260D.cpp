#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<ll> cover(n+1,0);
	vector<ll> ans(n+1,-1);
	vector<ll> cnt(n+1,0);
	set<pll> st;
	for(int i = 0;i<n;i++){
		auto it = st.upper_bound(make_pair(v[i],0));
		if(it == st.end()){
			it = st.insert(make_pair(v[i],v[i])).fs;
			cnt[v[i]] = 1;
		}
		else{
			auto tt = *it;
			st.erase(it);
			cover[tt.fs] = v[i];
			cnt[tt.sc]++;
			tt.fs = v[i];
			it = st.insert(tt).fs;
		}
		if(cnt[it->sc] == k){
			ll now = it->sc;
			while(now != 0){
				ans[now] = i+1;
				now = cover[now];
			}
			st.erase(it);
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<'\n';
}

