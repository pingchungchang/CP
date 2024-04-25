#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 998244353;
int n;
string s;
ll ans;
ll pw(ll a,ll b){
	ll returns = 1;
	while(b != 0){
		if((b&1))returns *= a;
		a *= a;
		a%= mod;
		returns %= mod;
		b>>=1;	
	}
	return returns;
}
void init(){
	s = "";
	ans = 0;
	n = 0;
}
ll rec(int now){
	if(now == n)return 0;
	ll def = pw(1LL*26,n-now-1);
	def = (def*(s[now]-'A'))%mod;
	return (def+rec(now+1))%mod;
}
void solve(){
	init();
	cin>>n>>s;
	s = s.substr(0,(n+1)/2);
	n = (n+1)/2;
	cout<<rec(0)+1<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

