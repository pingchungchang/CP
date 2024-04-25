#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 2e5+10;
ll bit[mxn+1];

void modify(int p,ll v){
	for(;p<=mxn;p+=p&-p)bit[p] += v;
	return;
}
ll getval(int s,int e){
	ll re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	int pos[n+1];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		pos[k] = i;
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans += getval(pos[i]+1,mxn);
		modify(pos[i],1);
		cout<<ans<<' ';
	}
	return 0;
}
