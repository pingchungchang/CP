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
	int od = 0,ev = 0;
	for(auto &i:arr){
		cin>>i;
		if(i&1)od++;
		else ev++;
	}
	sort(arr,arr+n);
	if(od&1){
		for(int i = 1;i<n;i++){
			if(arr[i]-arr[i-1] == 1){
				cout<<"YES\n";
				return;
			}
		}
		cout<<"NO\n";
		return;
	}
	else cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
