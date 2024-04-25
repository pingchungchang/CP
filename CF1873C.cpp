#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


string s[11];

void solve(){
	for(int i = 0;i<10;i++)cin>>s[i];
	int ans = 0;
	for(int i = 0;i<10;i++){
		for(int j = 0;j<10;j++){
			if(s[i][j] == 'X')ans += min({i+1,j+1,10-i,10-j});
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
