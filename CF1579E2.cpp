#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> bit;
ll n;
void modify(ll p,ll val){
	for(;p<=n;p += p&-p)bit[p]+= val;
	return;
}

ll getval(ll p){
	ll re = 0;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
void solve(){
	cin>>n;
	vector<ll> v(n);
	vector<ll> all;
	for(int i = 0;i<n;i++){
		cin>>v[i];
		all.push_back(v[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(auto &i:v){
		i = lower_bound(all.begin(),all.end(),i)-all.begin()+1;
	}
	bit = vector<ll>(n+1,0LL);
	ll ans = 0;
	for(auto &i:v){
		ans += min(getval(i-1),getval(n)-getval(i));
		modify(i,1);
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

