#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int pos[n+1] = {};
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		pos[k] = i;
	}
	int ans = -1;
	for(int i = 1;i<=n;i++){
		if(pos[i] == i)continue;
		if(ans == -1)ans = abs(pos[i]-i);
		else ans = __gcd(ans,abs(pos[i]-i));
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
