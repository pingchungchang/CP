#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


ll calc(string a,string lim){
	while(a.size() != lim.size())a = "0"+a;
	auto r = a;
	for(int i = r.size()-1;i>=0;i--){
		if(r[i] != '1')r[i] = '9';
		else break;
	}
	if(lim>=r)return stoll(r)-stoll(a)+1;
	else if(lim<a)return 0LL;
	else return stoll(lim)-stoll(a)+1;
}

void solve(){
	ll n;
	cin>>n;
	string s = to_string(n);
	ll p = 1;
	while(p<=n)p *= 10;
	p/=10;
	ll ans = 0;
	ll pref = 0;
	for(int i = 0;i<s.size();i++){
		string tmp(i+1,'1');
		do{
			ans += calc(tmp,s);
			tmp += '0';
		}while(tmp.size()<=s.size());
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
