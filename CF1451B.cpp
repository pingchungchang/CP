#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,q;
	string s;
	cin>>n>>q>>s;
	pii range[2];
	range[0] = range[1] = {n+1,0};
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		range[s[i]-'0'].fs = min(range[s[i]-'0'].fs,i);
		range[s[i]-'0'].sc = max(range[s[i]-'0'].sc,i);
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(range[s[l]-'0'].fs<l||range[s[r]-'0'].sc>r)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
