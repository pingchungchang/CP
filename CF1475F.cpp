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
	string arr[n],brr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	vector<vector<int>> v(n,vector<int>(n,0));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(arr[i][j] != brr[i][j])v[i][j] = 1;
		}
	}
	for(int i = 0;i<n;i++){
		int xsum[2] = {};
		for(int j = 0;j<n;j++){
			if((v[i][j]^v[0][j]) != (v[i][0]^v[0][0])){
				cout<<"NO\n";
				return;
			}
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
