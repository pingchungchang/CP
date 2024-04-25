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

bool cmp(pll a,pll b){
	return a.fs*b.sc>b.fs*a.sc;
}
int main(){
	io
	int n;
	cin>>n;
	ll ans = 0;
	vector<pll> v(n);
	for(auto &i:v)cin>>i.fs;
	for(auto &i:v)cin>>i.sc;
	sort(_all(v),cmp);
	ll total = 0;
	for(auto &i:v){
		ans += i.fs*total;
		total += i.sc;
	}
	cout<<ans;
}

