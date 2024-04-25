#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int k;
	cin>>k;
	string arr[n];
	for(auto &i:arr)cin>>i;
	int ans =0;
	for(auto &i:arr)if(i == arr[0])ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
