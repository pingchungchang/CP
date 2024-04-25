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

ll rev(ll k){
	ll re = 0;
	while(k != 0){
		re<<=1;
		if(k&1)re ^=1;
		k>>=1;
	}
	return re;
}
int main(){
	io
	ll x,y;
	cin>>x>>y;
	map<ll,ll> mp;
	queue<pll> q;
	q.push({x,0});
	mp[x] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
//		cout<<now.fs<<endl;
		ll a= rev(now.fs*2+1);
		ll b = rev(now.fs*2);
		if(a<=1e18&&!mp.count(a)){
			mp[a] = now.sc+1;
			q.push({a,now.sc+1});
		}
		if(b<=1e18&&!mp.count(b)){
			mp[b] = now.sc+1;
			q.push({b,now.sc+1});
		}
	}
	if(!mp.count(y))cout<<"NO";
	else cout<<"YES\n";
	return 0;
}

