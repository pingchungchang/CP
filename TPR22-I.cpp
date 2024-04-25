#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#pragma GCC optimize("O3")

const int mxn = 2e6+10;

vector<ll> bit;
int n,q;
ll lpf[mxn];
ll f(ll now){
	ll ans = 0;
	while(now != 1){
		ans += lpf[now];
		now /= lpf[now];
	}
	return ans;
}
void addval(int pos,ll val){
	for(;pos<=n;pos += pos&-pos){
		bit[pos] += val;
	}
	return;
}
ll getval(int pos){
	ll ans= 0;
	for(;pos>0;pos -= (pos&-pos)){
		ans += bit[pos];
	}
	return ans;
}
int main(){
	io
	memset(lpf,0LL,sizeof(lpf));
	for(ll i = 2;i<mxn;i++){
		if(lpf[i] != 0)continue;
		for(ll j = i;j<mxn;j+=i)lpf[j] = i;
	}
	cin>>n>>q;
	bit = vector<ll>(n+1,0);
	vector<ll> v(n+1);
	for(int i = 1;i<=n;i++){
		cin>>v[i];
	}
	for(ll i = 1;i<=n;i++){
		addval(i,f(v[i]));
//		cout<<tmp<<' ';
	}
//	cout<<endl<<endl;
	for(int i = 0;i<q;i++){
		int s,e;
		cin>>s>>e;
		cout<<getval(e)-getval(s-1)<<'\n';
	}
	return 0;
}

