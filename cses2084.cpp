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

struct line{
	ll m,b;
	ll s,e;
	line(){
		m = b = 0;
		s = 0,e = INT_MAX;
	}
	line(ll mm,ll bb){
		m = mm,b = bb;
		s = 0,e = INT_MAX;
	}
	ll operator()(ll k){
		return m*k+b;
	}
};
ll inter(line &a,line &b){
	if(a.m == b.m)return 0;
	return (a.b-b.b)/(b.m-a.m);
}
int main(){
	io
	ll n,x;
	cin>>n>>x;
	deque<line> dq;
	dq.push_back(line(x,0));
	ll ans = 0;
	pll req[n];
	for(auto&i:req)cin>>i.fs;
	for(auto &i:req)cin>>i.sc;
	for(int i = 0;i<n;i++){
		ll s,f;
		s = req[i].fs,f = req[i].sc;
		while(dq.size()>1&&dq[0](s)>=dq[1](s))dq.pop_front();
		ans = dq.front()(s);
		line now(f,ans);
		if(dq.back().m == now.m){
			if(dq.back().b>now.b)swap(dq.back(),now); 
			continue;
		} 
		while(dq.size()>1&&inter(dq[dq.size()-2],now)<inter(dq.back(),dq[dq.size()-2]))dq.pop_back();
		dq.push_back(line(f,ans));
	}
	cout<<ans;
}


/*
L,L-2
L-1,L-2

L,L-1
L-1,L-2
*/