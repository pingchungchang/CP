#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


vector<int> bit;
int n;

void modify(int p,int v){
	for(;p<=n;p += p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int returns = 0;
	for(;e>0;e -= e&-e)returns += bit[e];
	s--;
	for(;s>0;s -= s&-s)returns -= bit[s];
	return returns;
}
void solve(){
	cin>>n;
	bit = vector<int>(n+1,0);
	vector<int> v(n+1);
	for(int i = 1;i<=n;i++)cin>>v[i];
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans += getval(v[i],n);
		modify(v[i],1);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

