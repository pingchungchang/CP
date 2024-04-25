#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> v[n];
	for(auto &i:v){
		i = vector<int>(m);
		for(auto &j:i)cin>>j;
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m-3;j++)ans = max(ans,v[i][j]*v[i][j+1]*v[i][j+2]*v[i][j+3]);
	}
	for(int i = 0;i<m;i++){
		for(int j= 0;j<n-3;j++)ans = max(ans,v[j][i]*v[j+1][i]*v[j+2][i]*v[j+3][i]);
	}
	for(int i = 0;i<n-3;i++)for(int j = 0;j<m-3;j++)ans = max({ans,v[i][j]*v[i+1][j+1]*v[i+2][j+2]*v[i+3][j+3],v[i+3][j]*v[i+2][j+1]*v[i+1][j+2]*v[i][j+3]});
	cout<<ans;
}
