#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

ll n,q;
vector<ll> v;
void solve(){
	cin>>n>>q;
	v = vector<ll>(n);
	for(int i =  0;i<n;i++)cin>>v[i];
	string ans(n,'0');
	ll now = 0;
	for(ll i = n-1;i>=0;i--){
		if(v[i]>now&&now<q){
			now++;
			ans[i] = '1';
		}
		else if(now>=v[i]){
			ans[i] = '1';
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

