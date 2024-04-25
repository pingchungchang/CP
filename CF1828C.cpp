#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;

void solve(){
	int n;
	cin>>n;
	int a[n],b[n];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	sort(a,a+n);
	sort(b,b+n);
	int p = 0;
	int pos[n] = {};
	for(int i = 0;i<n;i++){
		while(p<n&&a[p]<=b[i])p++;
		pos[i] = p;
	}
	/*
	for(auto &i:pos)cout<<i<<' ';cout<<endl;
	for(auto &i:a)cout<<i<<' ';cout<<endl;
	for(auto &i:b)cout<<i<<' ';cout<<endl;

   */
	ll ans = 1;
	for(int i = n-1;i>=0;i--){
		ll choice = (n-pos[i])-(n-i-1);
		//cout<<i<<":"<<pos[i]<<' '<<choice<<endl;
		ans = ans*max(0LL,choice)%mod;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
