#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,f,a,b;
	cin>>n>>f>>a>>b;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll now = 0;
	for(auto &i:arr){
		f -= min(b,a*(i-now));
		now = i;
		if(f<=0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
