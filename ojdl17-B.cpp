#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1e9+7;
vector<vector<ll>> mult(vector<vector<ll>> a,vector<vector<ll>> b){
	vector<vector<ll>> returns(2,vector<ll>(2,0));
	for(int i = 0;i<2;i++){
		for(int j = 0;j<2;j++){
			for(int k = 0;k<2;k++){
				returns[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	return returns;
}
int main(){
	int n;
	cin>>n;
	if((n&1)){
		cout<<0;
		return 0;
	}
	else n/=2;
	vector<vector<ll>> now = {{1,0},{0,1}};
	vector<vector<ll>> dp = {{3,2},{1,0}};
	while(n != 0){
		if((n&1))now = mult(now,dp);
		dp = mult(dp,dp);
		n>>=1;
	}
	cout<<now[1][0]+now[1][1];
	
}
