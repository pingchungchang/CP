#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 1e5+10;
pll arr[mxn];
ll n,p;
multiset<int> st;

void solve(){
	st.clear();
	cin>>n>>p;
	for(int i = 0;i<n;i++)cin>>arr[i].sc;
	for(int i = 0;i<n;i++)cin>>arr[i].fs;
	sort(arr,arr+n);
	for(int i = 0;i<n;i++)st.insert(p);
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ans += *st.begin();
		st.erase(st.find(*st.begin()));
		while(arr[i].sc--&&!st.empty()&&*st.rbegin()>arr[i].fs){
			st.insert(arr[i].fs);
			st.erase(st.find(*st.rbegin()));
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
