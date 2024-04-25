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
	ll ans = 0;
	ll cnt = 0;
	for(int i = 0;i<32;i++){
		if(cnt+(n+1)/2>=k){
			cout<<(((k-cnt)*2-1)<<i)<<'\n';
			return;
		}
		cnt += (n+1)/2;
		n>>=1;
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
