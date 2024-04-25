#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	bool flag = false;
	ll n;
	cin>>n;
	ll arr[n*2];
	for(int i = 0;i<n*2;i++)cin>>arr[i];
	sort(arr,arr+n*2);
	for(int i = 0;i<n*2-1;i++){
		ll now = arr[n*2-1];
		multiset<ll> st;
		for(auto i:arr)st.insert(i);
		st.erase(st.find(arr[i]));
		st.erase(st.find(arr[n*2-1]));
		vector<pll> v = {make_pair(arr[n*2-1],arr[i])};
		while(!st.empty()){
			ll a = *st.rbegin();
			st.erase(st.find(a));
			if(st.find(now-a) == st.end())break;
			st.erase(st.find(now-a));
			v.push_back({a,now-a});
			now = a;
		}
		if(st.empty()){
			cout<<"YES\n";
			cout<<v[0].fs+v[0].sc<<'\n';
			for(auto i:v)cout<<i.fs<<' '<<i.sc<<'\n';
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

