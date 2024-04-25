#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll


string s;
int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b != 0){
		a%=b;
		swap(a,b);
	}
	return a;
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}

ll f(vector<ll> &v){
	int sz = v.size();
	ll ans= sz;
	int sq = sqrt(sz)+1;
	for(ll i = 1;i<=sq;i++){
		if(sz%i == 0){
			ll tmp = sz/i;
			bool flag = true;
			for(ll j = 0;j<i;j++){
				for(ll k = i+j;k<sz;k+=i){
					if(s[v[k]] != s[v[k-i]])flag = false;
				}
			}
			if(flag)ans = min(ans,i);
			flag = true;
			for(ll j = 0;j<tmp;j++){
				for(ll k = tmp+j;k<sz;k+=tmp){
					if(s[v[k]] != s[v[k-tmp]])flag = false;
				}
			}
			if(flag)ans = min(ans,tmp);
		}
	}
	return ans;
}
void solve(){
	int n;
	cin>>n;
	cin>>s;
	vector<int> p(n);
	for(int i = 0;i<n;i++){
		cin>>p[i];
		p[i]--;
	}
	vector<vector<int>> loops;
	vector<int> goneto(n,0);
	for(int i = 0;i<n;i++){
		if(goneto[i] == 0){
			loops.push_back({i});
			goneto[i] = 1;
			int now = p[i];
			while(goneto[now] != 1){
				goneto[now] = 1;
				loops.back().push_back(now);
				now = p[now];
			}
		}
	}
	ll ans = 1;
	for(auto i:loops){
//		for(auto j:i)cout<<j<<' ';cout<<',';cout<<f(i)<<';';cout<<'\n';
		ans = lcm(ans,f(i));
	}
	cout<<ans<<'\n';
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

