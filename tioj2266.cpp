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
int main(){
	io
	int n;
	cin>>n;
	set<ll> unused;
	multiset<pair<pll,ll>> st1,st2;
	pll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs;
		unused.insert(i);
	}
	for(int i = 0;i<n;i++)cin>>arr[i].sc;
	for(int i = 0;i<n;i++){
		st1.insert({arr[i],i});
		st2.insert({{arr[i].sc,arr[i].sc},i});
	}
	ll dp[n+1];
	memset(dp,0LL,sizeof(dp));
	dp[1] = st2.begin()->fs.fs;
	unused.erase(st2.begin()->sc);
	for(int i = 2;i<=n;i++){
		dp[i]+=dp[i-1];
		bool done = false;
		while(unused.find(st2.begin()->sc) == unused.end()){
			st2.erase(st2.find(*st2.begin()));
		}
		if(st2.begin()->fs.fs<=i){
			done = true;
			st2.erase(st2.find(*st2.begin()));
		}
		if(done)continue;
		while(unused.find(st1.begin()->sc) == unused.end()){
			st1.erase(st2.find(*st1.begin()));
		}
		dp[i]+=st1.begin()->fs.fs;
		cout<<i<<' '<<dp[i]<<endl;
		st1.erase(st1.find(*st1.begin()));
	}
	ll total = 0;
	for(int i= 0;i<n;i++)total += arr[i].fs;
	for(int i = 1;i<=n;i++){
		cout<<total-dp[i]<<' ';
	}
	return 0;
}

