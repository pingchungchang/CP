#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mx = (ll)1e9*(ll)1e9;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<ll>> v(n,vector<ll>(n,mx));
	for(int i =0;i<n;i++)v[i][i] = 0;
	for(int i =0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		v[a][b] = min(c,v[a][b]);
		v[b][a] = v[a][b];
	}
//	cout<<v[3][6]<<v[6][9]<<v[9][5]<<endl;
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			for(int k = 0;k<n;k++){
				v[j][k] = min(v[j][k],v[j][i]+v[i][k]);
			}
		}
	}
	for(int i =0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		if(v[a][b] == mx){
			cout<<"-1\n";
		}
		else cout<<v[a][b]<<'\n';
	}
}
