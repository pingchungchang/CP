#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> v[2];
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v[k&1].push_back(k);
	}
	for(auto &i:v){
		for(auto &j:i)cout<<j<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
