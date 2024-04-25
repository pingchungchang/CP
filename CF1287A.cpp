#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	int p = n-1;
	int ans = 0;
	for(int i = n-1;i>=0;i--){
		if(s[i] == 'P')p = max(p,i);
		else{
			ans = max(ans,p-i);
			p = 0;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
