#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		v[i]+=v[i];
	}
	int ans = 0;
	for(int i =0;i<n;++i){
		int tmp = 0;
		for(int j = 0;j<n;j++){
			tmp += v[j][i+j]-'0';
		}
		ans = max(ans,tmp);
	}
	int o = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			o += v[i][j]-'0';
		}
	}
	cout<<o-ans+n-ans<<'\n';
}

int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

