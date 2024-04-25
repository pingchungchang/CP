#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> pref(n+1,0);
	string s;
	cin>>s;
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1]+(pow(-1,i%2))*(s[i-1] == '+');
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		if((e-s+1)%2 != 0){
			cout<<1<<'\n';
		}
		else if(pref[e]-pref[s-1] == 0)cout<<0<<'\n';
		else cout<<2<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

