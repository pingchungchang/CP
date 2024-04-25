#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	string a,b;
	cin>>a>>b;
	ll n = a.size(),m = b.size();
	vector<vector<ll>> v(n,vector<ll>(m,LONG_LONG_MAX));
	if(a[0] == b[0])v[0][0]=0;
	else v[0][0] = 1;
	for(ll i =1;i<m;i++){
		if(a[0] == b[i]){
			v[0][i] = i;
		}
		else{
			v[0][i] = 1+v[0][i-1];
		}
	}
	for(ll i =1;i<n;i++){
		if(a[i] == b[0]){
			v[i][0] = i;
		}
		else{
			v[i][0] = v[i-1][0]+1;
		}
	}
	for(ll i =1;i<n;i++){
		for(ll j =1;j<m;j++){
			if(a[i] == b[j]){
				v[i][j] = v[i-1][j-1];
			}
			v[i][j] = min(v[i][j],1+v[i-1][j-1]);
			v[i][j] = min(v[i][j],min(1+v[i-1][j],1+v[i][j-1]));
		}
	}
//	for(ll i =0;i<n;i++){
//		for(ll j =0;j<m;j++)cout<<v[i][j]<<' ';
//		cout<<endl;
//	}
	cout<<v[n-1][m-1];
}
