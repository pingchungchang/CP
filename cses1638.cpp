#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
int main(){
	ll n;
	cin>>n;
	vector<vector<ll>> v(n,vector<ll>(n,0));
	for(ll i =0;i<n;i++){
		for(ll j =0;j<n;j++){
			char c;
			cin>>c;
			if(c == '*')v[i][j] = -1;
		}
	}
	if(v[0][0]!= -1)v[0][0] = 1;
	else v[0][0] = 0;
	for(ll i =1;i<n;i++){
		if(v[i][0] == -1)v[i][0] =0;
		else v[i][0] = v[i-1][0];
	}
	for(ll i =1;i<n;i++){
		if(v[0][i] == -1)v[0][i] =0;
		else v[0][i] = v[0][i-1];
	}
	for(ll i =1;i<n;i++){
		for(ll j =1;j<n;j++){
			if(v[i][j] == -1){
				v[i][j] = 0;
				continue;
			}
			else{
				v[i][j] = v[i-1][j]+v[i][j-1];
				v[i][j]%=mod;
			}
		}
	}
//	for(ll i =0;i<n;i++){
//		for(ll j=0;j<n;j++){
//			cout<<v[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<v[n-1][n-1];
}
