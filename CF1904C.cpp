#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	if(k>=3){
		cout<<"0\n";
		return;
	}
	ll ans = arr[0];
	if(k>=1){
		for(int i = 1;i<n;i++)ans = min(ans,arr[i]-arr[i-1]);
	}
	if(k>=2){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				ll tval = arr[j]-arr[i];
				auto it = upper_bound(arr,arr+n,tval)-arr;
				if(it<n)ans = min(ans,abs(tval-arr[it]));
				it--;
				if(it>=0)ans = min(ans,abs(tval-arr[it]));
			}
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
