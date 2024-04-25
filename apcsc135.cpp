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
const int mxn = 1e3+10;

int n;
pll v[mxn];
bool f(ll x){
	bool goneto[n] = {};
	queue<pll> q;
	goneto[0] = true;
	q.push(v[0]);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int i = 0;i<n;i++){
			if(goneto[i]||x*x*4LL<(v[i].fs-now.fs)*(v[i].fs-now.fs)+(v[i].sc-now.sc)*(v[i].sc-now.sc))continue;
			q.push(v[i]);
			goneto[i] = true;
		}
	}
	for(int i = 0;i<n;i++)if(!goneto[i])return false;
	return true;
}
void solve(){
	cin>>n;
	for(int i = 0;i<n;i++)cin>>v[i].fs>>v[i].sc;
	sort(v,v+n);
	ll l = 0,r = 2e9;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

