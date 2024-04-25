#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> pref;
int n,t;
bool f(int now){
	for(int i = now;i<=n;i++){
		if(pref[i]-pref[i-now]<=t)return true;
	}
	return false;
}
int main(){
	cin>>n>>t;
	ll l = 0,r = n;
	pref = vector<ll>(n+1,0LL);
	for(int i = 1;i<=n;i++){
		cin>>pref[i];
		pref[i] += pref[i-1];
	}
	while(l != r){
		ll mid = (l+r+1)/2;
		if(f(mid))l = mid;
		else r = mid-1;
	}
	cout<<l;
}

