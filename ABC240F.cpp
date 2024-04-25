#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	ll fst;
	ll dif;
	ll cnt;
	node(){
		fst =0;
		dif = 0;
		cnt = 0;
	}
};
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<node> v(n);
	ll now = 0;
	for(ll i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v[i].dif = a;
		v[i].fst = now+a;
		v[i].cnt = b;
		now += b*a;
	}
	now = 0;
	ll ans = v[0].fst;
	for(auto i:v){
		if(i.fst>0&&i.dif<0){
			ll lst = i.fst/abs(i.dif);
			lst = min(lst,i.cnt-1);
			ans = max(ans,now+(i.fst*2+lst*i.dif)*(lst+1)/2);
		}
		now += (i.fst*2+i.dif*(i.cnt-1))*i.cnt/2;
		ans = max(ans,now);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

