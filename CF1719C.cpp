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
void solve(){
	ll n,q;
	cin>>n>>q;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	queue<ll> qu;
	for(int i = 1;i<n;i++)qu.push(i);
	ll now = 0;
	vector<tuple<ll,ll,ll>> req(q);
	for(int i = 0;i<q;i++){
		ll l,k;
		cin>>l>>k;
		get<0>(req[i]) = k;
		get<1>(req[i]) = l-1;
		get<2>(req[i]) = i;
	}
	vector<ll> ans(q);
	sort(_all(req));
	vector<ll> wins(n,0LL);
	ll p =0;
	for(int i = 1;i<=n*2;i++){
		if(v[now]>v[qu.front()]){
			qu.push(qu.front());
			qu.pop();
			wins[now]++;
		}
		else{
			qu.push(now);
			now = qu.front();
			wins[now]++;
			qu.pop();
		}
		while(p != q&&get<0>(req[p]) == i){
			ans[get<2>(req[p])] = wins[get<1>(req[p])];
			p++;
		}
//		cout<<i<<' '<<p<<endl;
	}
	while(p < q){
		if(v[get<1>(req[p])] != n)ans[get<2>(req[p])] = wins[get<1>(req[p])];
		else{
			int more = get<0>(req[p])-n*2;
			ans[get<2>(req[p])] = wins[get<1>(req[p])]+more;
		}
		p++;
	}
	for(auto i:ans)cout<<i<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

