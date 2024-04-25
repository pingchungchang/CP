#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
const int mxn = 2e5+10;

set<int> st;
int n;
int arr[mxn],rp[mxn];
map<int,int> mp;

void solve(){
	st.clear();
	mp.clear();
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = n;i>=1;i--){
		rp[i] = -1;
		if(mp.find(arr[i]) != mp.end())st.erase(mp[arr[i]]);
		if(!st.empty())rp[i] = *st.begin();
		st.insert(mp[arr[i]] = i);
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		if(rp[l] != -1&&rp[l]<=r)cout<<l<<' '<<rp[l]<<'\n';
		else cout<<"-1 -1\n";
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
