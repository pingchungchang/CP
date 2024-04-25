#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<ll> v;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	ll ta = 0,tb = 0;
	bool flag = false;
	while(!v.empty()){
		auto now = v.back();v.pop_back();
		if(flag&&(now&1))tb+=now;
		if(!flag&&!(now&1))ta += now;
		flag ^= 1;
	}
	if(ta==tb)cout<<"Tie\n";
	else if(ta>tb)cout<<"Alice\n";
	else cout<<"Bob\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
