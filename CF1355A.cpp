#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

pii get(ll n){
	string s = to_string(n);
	return {*min_element(s.begin(),s.end())-'0',*max_element(s.begin(),s.end())-'0'};
}

void solve(){
	ll a,k;
	cin>>a>>k;
	k--;
	pii re;
	while(k>0&&(re = get(a)).fs != 0){
		a += re.fs*re.sc;
		k--;
	}
	re = get(a);
	cout<<a<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
