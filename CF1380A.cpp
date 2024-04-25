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
	int arr[n];
	for(auto &i:arr)cin>>i;
	int pref[n],suf[n];
	pref[0] = 0,suf[n-1] = n-1;
	for(int i = 1;i<n;i++){
		pref[i] = pref[i-1];
		if(arr[i]<arr[pref[i]])pref[i] = i;
	}
	for(int i = n-2;i>=0;i--){
		suf[i] = suf[i+1];
		if(arr[i]<arr[suf[i]])suf[i] = i;
	}
	for(int i = 1;i<n-1;i++){
		if(pref[i] != i&&suf[i] != i){
			cout<<"YES\n";
			cout<<pref[i]+1<<' '<<i+1<<' '<<suf[i]+1<<'\n';
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
