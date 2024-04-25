#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	vector<int> ans(n,INT_MAX);
	ans[0] = 0;
	for(int i = 1;i<n;i++){
		if((v[i]&v[i-1]) == v[i-1])ans[i] = 0;
		else{
			ans[i] = (v[i]^(v[i]|v[i-1]));
			v[i]^=ans[i];
		}
	}
	for(auto i:ans)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

