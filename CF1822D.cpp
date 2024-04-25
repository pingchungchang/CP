#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	if(n == 1){
		cout<<"1\n";
		return;
	}
	if(n&1){
		cout<<"-1\n";
		return;
	}
	vector<int> ans;
	ans.push_back(n);
	for(int i = n-1;i>=0;i-= 2){
		ans.push_back(i);
		if(i>1)ans.push_back(n+1-i);
	}
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
