#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> v;
	int arr[n+1] = {};
	v.push_back(0);
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] ^= arr[i-1];
		v.push_back(arr[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int ans = 0;
	for(int i = 0;i<v.size();i++){
		for(int j = i+1;j<v.size();j++){
			ans = max(ans,v[i]^v[j]);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
