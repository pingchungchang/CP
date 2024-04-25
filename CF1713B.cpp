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
	ll n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++)cin>>arr[i];
	int pref[n] = {},suff[n] = {};
	for(int i = 1;i<n;i++){
		pref[i] = pref[i-1];
		suff[n-1-i] = suff[n-i];
		if(arr[i]>=arr[i-1])pref[i]++;
		if(arr[n-1-i]>=arr[n-i])suff[n-1-i]++;
	}
//	for(int i = 0;i<n;i++)cout<<pref[i]<<' ';cout<<'\n';for(int i = 0;i<n;i++)cout<<suff[i]<<" ";cout<<'\n';
	for(int i = 0;i<n;i++){
		if(pref[i]+suff[i] == n-1){
			cout<<"YES\n";
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

