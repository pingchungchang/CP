#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<int> va,vb;
	if(a[0] != b[0]||a.back() != b.back()){
		cout<<-1<<'\n';
		return;
	}
	for(int i = 0;i<n;i++){
		if(va.empty()||a[va.back()] != a[i])va.push_back(i);
		if(vb.empty()||b[vb.back()] != b[i])vb.push_back(i);
	}
	if(va.size() != vb.size()){
		cout<<"-1\n";
		return;
	}
	ll ans = 0;
	for(int i = 0;i<va.size();i++){
		ans += abs(va[i]-vb[i]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
