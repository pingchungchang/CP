#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mxn = 6e5+10;
pll arr[mxn];
ll pos[mxn],neg[mxn];

void solve(){
	vector<ll> all;
	ll n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 0;i<n;i++){
		all.push_back(arr[i].fs);
		all.push_back(arr[i].fs-arr[i].sc);
		all.push_back(arr[i].fs+arr[i].sc);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	fill(pos,pos+all.size(),0LL);
	for(int i =0;i<n;i++){
		auto l = lower_bound(all.begin(),all.end(),arr[i].fs-arr[i].sc)-all.begin();
		auto r = lower_bound(all.begin(),all.end(),arr[i].fs+arr[i].sc)-all.begin();
		arr[i].fs = lower_bound(all.begin(),all.end(),arr[i].fs);
		pos[l]++;
		pos[arr[i].fs+1]-=2;
		pos[r+1]++;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
