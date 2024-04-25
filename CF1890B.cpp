#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	bool flag = true;
	bool use = true;
	for(int i = 0;i+1<m;i++){
		if(t[i] == t[i+1])use = false;
	}
	for(int i = 0;i+1<n;i++){
		if(s[i] != s[i+1])continue;
		if(!use||s[i] == t[0]||s[i+1] == t.back())flag = false;
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
