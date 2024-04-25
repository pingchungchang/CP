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
	return a.fs*b.sc<b.fs*a.sc;
}
int main(){
	ll n;
	cin>>n;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	ll total = 0;
	ll ans = 0;
	sort(arr,arr+n,cmp);
	for(auto &i:arr){
		total += i.fs;
		ans += total*i.sc;
	}
	cout<<ans;
}

