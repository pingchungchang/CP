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
void solve(){
	int n,m;
	cin>>n>>m;
	ll total = 0;
	ll sm = INT_MAX;
	ll neg = 0;
	bool z = false;
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++){
		ll k;
		cin>>k;
		sm = min(sm,abs(k));
		if(k<0)neg++;
		if(k == 0)z = true;
		total += abs(k);
	}
	if(z||neg%2 == 0){
		cout<<total<<'\n';
		return;
	}
	cout<<total-sm*2<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;while(t--)solve();
}

