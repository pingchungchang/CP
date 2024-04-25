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
	vector<vector<int>> v(n,vector<int>(n,0));
	for(int i = 0;i<n;i++){
		v[i][i] = 1;
		if(i>0)v[i-1][i] = 1;
	}
	v[n-1][0] = 1;
	for(auto &i:v){
		for(auto &j:i)cout<<j<<' ';
		cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
