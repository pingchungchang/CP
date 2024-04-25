#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

ll A,B;
ll calc(ll L){
	//cout<<L<<":"<<((B+L-1)/L+1)*L<<'\n';
	return L*((B+L-1)/L)+L-A-B;
}

void solve(){
	cin>>A>>B;
	if(A>=B){
		cout<<A-B<<'\n';
		return;
	}
	ll ans = 4e18;
	ll L = 2;
	ll pre = 1;
	for(;L<=B;pre = L,L = B/(B/L)+1){
		for(int i = -20;i<=20;i++){
			ans = min(ans,calc(max(L+i,A)));
			ans = min(ans,calc(max(pre+i,A)));
		}
	}
	ans = min(ans,calc(B));
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
