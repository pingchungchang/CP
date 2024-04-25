#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	string s;
	cin>>n>>s;
	int ans = 0;
	for(int i = 0;i<n;i++){
		ans += (s[i] == '@');
		if(i&&s[i] == s[i-1]&&s[i] == '*')break;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
