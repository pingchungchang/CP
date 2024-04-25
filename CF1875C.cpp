#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,m;
	cin>>n>>m;
	n%=m;
	if(n == 0){
		cout<<"0\n";
		return;
	}
	ll G = __gcd(n,m);
	n /=G,m/=G;
	if(__builtin_popcountll(m) != 1){
		cout<<"-1\n";
		return;
	}
	n *= G,m *= G;
	ll cnt = n;
	ll ans = 0;
	while(cnt != 0){
		cnt *= 2;
		ans += cnt/2;
		if(cnt>=m){
			cnt -= m;
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
