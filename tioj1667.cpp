#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;

vector<ll> all;
int n;
ll arr[mxn];
ll bit[mxn];

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
ll getval(int p){
	ll re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

void solve(){
	all = {INT_MIN};
	for(int i = 0;i<n;i++)cin>>arr[i],all.push_back(arr[i]);
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 0;i<n;i++)arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
	ll ans = 0;
	for(int i = n-1;i>=0;i--){
		ans += getval(arr[i]-1);
		modify(arr[i],1);
	}
	cout<<ans<<'\n';
	for(int i = 1;i<=all.size();i++)modify(i,-getval(i));
	for(int i = 0;i<=n;i++)arr[i] = 0;
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
