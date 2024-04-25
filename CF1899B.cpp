#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll inf = 4e18;

void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(n%i == 0){
			pll p = {inf,0ll};
			for(int ii = 0;ii<n;ii+=i){
				ll tsum = 0;
				for(int j = 0;j<i;j++){
					tsum += arr[ii+j];
				}
				p.fs = min(p.fs,tsum);
				p.sc = max(p.sc,tsum);
			}
			ans = max(ans,p.sc-p.fs);
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
