#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,s;
	cin>>n>>s;
	ll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	arr[0] = 0;
	ll p = 1;
	ll total = s;
	pll ans = {-1,-1};
	for(int i = 1;i<=n;i++)if(arr[i]+s>=0)ans = {i,i};
	for(int i = 1;i<=n;i++){
		if(p<=i){
			p = i;
			total = s;
		}
		while(p<=n&&total+arr[p]>=0){
			total += arr[p];
			p++;
		}
		//cout<<i<<":"<<p<<endl;
		if(p-i>ans.sc-ans.fs+1)ans = make_pair(i,p-1);
		total -= arr[i];
	}
	if(ans.fs == -1)cout<<ans.fs<<'\n';
	else cout<<ans.fs<<' '<<ans.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
