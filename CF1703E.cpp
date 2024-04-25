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
	int v[n][n];
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++){
		char c;
		cin>>c;
		v[i][j] = c-'0';
	}
	int ans =0;
	bool cnt[n][n] = {};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int one = 0,zero = 0;
			one += v[i][j];zero += 1-v[i][j];
			one += v[n-1-j][i];zero += 1-v[n-1-j][i];
			one += v[n-1-i][n-1-j];zero += 1-v[n-1-i][n-1-j];
			one += v[j][n-1-i];zero += 1-v[j][n-1-i];
			ans += min(one,zero);
		}
	}
	cout<<ans/4<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

