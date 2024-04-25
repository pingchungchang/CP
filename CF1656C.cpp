#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void solve(){
	int n;
	cin>>n;
	bool one = false;
	bool cons = false;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	if(mp[0] != 0&&mp[1] != 0){
		cout<<"NO\n";
		return;
	}
	int pre = -2;
	for(auto it:mp){
		if(it.sc == 0)continue;
		if(it.fs-pre== 1)cons = true;
		if(it.fs == 1)one = true;
		pre = it.fs;
	}
	if(one&&cons)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

/*
10
13 20 13 5 1 15 8 2 17 15
*/
