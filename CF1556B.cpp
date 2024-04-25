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
void modify(ll p,ll v){
	for(;p<=n;p += p&-p)bit[p] += v;
	return;
}
ll getval(ll p){
	ll returns = 0;
	for(;p>0;p -= p&-p)returns += bit[p];
	return returns;
}
void solve(){
	cin>>n;
	bit = vector<ll>(n+2,0LL);
	queue<ll> ev,od,e,o;
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		if(k%2)o.push(i);
		else e.push(i);
	}
	ll ans = INT_MAX;
	ev = e;
	od = o;
	ll tmp = 0;
	for(ll i = 1;i<=n;i++){
		if(i%2 == 1&&ev.empty()){
			tmp = INT_MAX;
			break;
		}
		if(i%2 == 0&&od.empty()){
			tmp = INT_MAX;
			break;
		}
		if(i%2 == 1){
			tmp += ev.front()+getval(ev.front())-i;
			modify(1,1);
			modify(ev.front()+1,-1);
			ev.pop();
		}
		else{
			tmp += od.front()+getval(od.front())-i;
			modify(1,1);
			modify(od.front()+1,-1);
			od.pop();
		}
	}
	ans = min(ans,tmp);
	bit = vector<ll>(n+2,0LL);
	ev = e;
	od = o;
	tmp = 0;
	for(ll i = 1;i<=n;i++){
		if(i%2 == 1&&od.empty()){
			tmp = INT_MAX;
			break;
		}
		if(i%2 == 0&&ev.empty()){
			tmp = INT_MAX;
			break;
		}
		if(i%2 == 1){
			tmp += od.front()+getval(od.front())-i;
			modify(1,1);
			modify(od.front()+1,-1);
			od.pop();
		}
		else{
			tmp += ev.front()+getval(ev.front())-i;
			modify(1,1);
			modify(ev.front()+1,-1);
			ev.pop();
		}
	}
	ans = min(ans,tmp);
	if(ans == INT_MAX){
		cout<<"-1\n";
	}
	else cout<<ans<<'\n';
	return;
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

