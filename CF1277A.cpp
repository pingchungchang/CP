#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	int ans = 0;
	for(char c = '1';c<='9';c++){
		string s(1,c);
		while(stoll(s)<=n){
			ans++;
			s += c;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
