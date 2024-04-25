#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


vector<int> v[3][3];

int mex(int a,int b,int c){
	for(int i = 0;i<=4;i++){
		if(i != a&&i!=b&&i!=c)return i;
	}
	assert(false);
	return 0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	string s;
	for(auto &i:arr)cin>>i;
	cin>>s;
	for(int i = 0;i<n;i++){
		int p = 0;
		if(s[i] == 'M')p = 0;
		else if(s[i] == 'E')p = 1;
		else p = 2;
		v[p][arr[i]].push_back(i);
	}
	ll ans = 0;
	for(int i = 0;i<3;i++){
		for(auto &p:v[1][i]){
			for(int j = 0;j<3;j++){
				for(int k = 0;k<3;k++){
					auto lp = lower_bound(v[0][j].begin(),v[0][j].end(),p)-v[0][j].begin();
					auto rp = lower_bound(v[2][k].begin(),v[2][k].end(),p)-v[2][k].begin();
					ans += 1LL*mex(i,j,k)*lp*(v[2][k].size()-rp);
				}
			}
		}
	}
	cout<<ans;
}
