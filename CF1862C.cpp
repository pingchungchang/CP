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
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	vector<int> vv;
	for(int i = 1;i<=n;i++){
		auto pos = lower_bound(v.rbegin(),v.rend(),i)-v.rbegin();
		vv.push_back(v.size()-pos);
	}
	for(int i = 0;i<n;i++){
		if(v[i] != vv[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
