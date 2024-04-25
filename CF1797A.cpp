#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	int s1,e1,s2,e2;
	cin>>s1>>e1>>s2>>e2;
	int shift = 0;
	if(s1 == 1||s1 == n)shift++;
	if(e1 == 1||e1 == m)shift++;
	int ans = 4-shift;
	shift = 0;
	if(s2 == 1||s2 == n)shift++;
	if(e2 == 1||e2 == m)shift++;
	ans = min(ans,4-shift);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
