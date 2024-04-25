#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	set<int> a,b;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		a.insert(k);
	}
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		b.insert(k);
	}
	for(auto &i:a){
		if(b.find(i)!=b.end()){
			cout<<"YES\n";
			cout<<"1 "<<i<<'\n';
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
