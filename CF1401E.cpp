#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e6+10;
ll bit[mxn+1];

void modify(int p,int v){
	for(;p<=mxn;p+=p&-p)bit[p] += v;
	return;
}
ll getval(int s,int e){
	ll re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

vector<pii> event[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	ll ans = 1;
	for(int i = 0;i<n;i++){
		int y,l,r;
		cin>>y>>l>>r;
		event[l].push_back({-1,y});
		event[r+1].push_back({-2,y});
		if(l == 0&&r == 1000000)ans++;
	}
	for(int i = 0;i<m;i++){
		int x,l,r;
		cin>>x>>l>>r;
		event[x].push_back({l,r});
		if(l == 0&&r == 1000000)ans++;
	}
	for(int i = 0;i<mxn;i++){
		sort(event[i].begin(),event[i].end());
		for(auto &j:event[i]){
			if(j.fs == -2)modify(j.sc,-1);
			else if(j.fs == -1)modify(j.sc,1);
			else ans += getval(j.fs,j.sc);
		}
	}
	cout<<ans;
}
