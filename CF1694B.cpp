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
	string s;
	cin>>s;
	ll ans = 0;
	for(int i = n-1;i>=0;i--){
		if(i == 0){
			ans++;
			break;
		}
		else{
			if(s[i] != s[i-1])ans += i+1;
			else ans ++;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

