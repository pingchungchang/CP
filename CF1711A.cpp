#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll n;
	cin>>n;
	vector<ll> ans(n+1,0);
	for(int i = 1;i<=n;i++)ans[i] = i;
	for(int i = 1;i<=n-1;i+=2){
		swap(ans[i],ans[i+1]);
	}
	if(n&1){
		swap(ans[1],ans.back());
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

