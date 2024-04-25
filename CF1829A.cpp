#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


string tar = "codeforces";
void solve(){
	string s;
	cin>>s;
	int ans = 0;
	for(int i = 0;i<s.size();i++)if(s[i] != tar[i])ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
