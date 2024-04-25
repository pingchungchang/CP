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
	auto vv = v;
	sort(v.begin(),v.end());
	int s = v[0];
	int G = 0;
	for(int i = 0;i<n;i++){
		if(v[i] != vv[i]){
			if(!G)G = v[i];
			else G = __gcd(G,v[i]);
		}
	}
	if(G%s == 0){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
