#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n,k;
	cin>>n>>k;
	int cnt = 1;
	int arr[n];
	vector<int> all;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(auto &i:arr){
		i = lower_bound(all.begin(),all.end(),i)-all.begin();
	}
	for(int i = 1;i<n;i++){
		if(arr[i]-arr[i-1]!=1&&arr[i]!=arr[i-1])cnt++;
	}
	if(cnt<=k)cout<<"YES\n";
	else cout<<"NO\n";
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

