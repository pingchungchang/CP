#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	k %= n+1;
	vector<int> v;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		v.push_back(tmp);
		sum += tmp;
	}
	v.push_back(n*(n+1)/2-sum);
	for(int i = 0;i<n+1;i++)v.push_back(v[i]);
	int start = n+1-k;
	for(int i = 0;i<n;i++)cout<<v[start+i]<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
