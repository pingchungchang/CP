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
	int pl = 0,pr = n-1;
	while(pl<n&&s[pl] == '0')pl++;
	while(pr>=0&&s[pr] == '1')pr--;
	string ans;
	for(int i = 0;i<pl;i++)ans += s[i];
	if(pl<pr)ans += '0';
	for(int i = pr+1;i<n;i++)ans += s[i];
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
