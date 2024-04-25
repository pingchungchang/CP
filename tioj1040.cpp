#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const ll inf = 1e18;

void solve(){
	pii p;
	cin>>p.fs>>p.sc;
	string ans;
	ans += to_string(p.fs)+"/"+to_string(p.sc)+" = ";
	int g = __gcd(p.fs,p.sc);
	p = {p.fs/g,p.sc/g};
	if(p.sc == 1){
		cout<<ans<<p.fs<<'\n';
		return;
	}
	ans += to_string(p.fs/p.sc);
	ans += "+1/{";
	p.fs %= p.sc;
	swap(p.fs,p.sc);
	p = {p.fs/__gcd(p.fs,p.sc),p.sc/__gcd(p.fs,p.sc)};
	int cnt = 0;
	while(p.sc != 1){
		cnt++;
		ans += to_string(p.fs/p.sc)+"+1/{";
		p.fs %= p.sc;
		swap(p.fs,p.sc);
		p = {p.fs/__gcd(p.fs,p.sc),p.sc/__gcd(p.fs,p.sc)};
	}
	ans.pop_back();
	ans += to_string(p.fs);
	for(int i = 0;i<cnt;i++)ans+="}";
	cout<<ans<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

