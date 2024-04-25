#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	ll len;
	ll mn;
	node(){
		mn = 0;
		len = 0;
	}
};
bool cmp(node a,node b){
	return a.mn<b.mn;
}
void solve(){
	ll n;
	cin>>n;
	vector<node> v(n,node());
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		v[i].len = k;
		for(ll j= 0;j<k;j++){
			ll tmp;
			cin>>tmp;
			v[i].mn = max(v[i].mn,tmp-j+1);
		}
	}
	sort(v.begin(),v.end(),cmp);
	ll ans = 0;
	ll sum = 0;
	for(auto i:v){
		ans = max(ans,i.mn-sum);
		sum += i.len;
	}
	cout<<ans<<'\n';
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
