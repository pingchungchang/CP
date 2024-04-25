#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int r = -1;
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == 'B'){
			if(r<i)r = i+k-1,ans++;
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
