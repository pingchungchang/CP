#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


struct node{
	ll l,r;
	node(){}
	node(ll a,ll b):l(a),r(b){}
	bool operator<(node b)const{
		if(r-l == b.r-b.l)return l>b.l;
		else return r-l<b.r-b.l;
	}
};

void solve(){
	ll n;
	cin>>n;
	priority_queue<node> pq;
	ll ans[n];
	pq.push(node(0,n-1));
	int c = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		ll mid = (now.l+now.r)/2;
		ans[mid] = ++c;
		if(mid != now.l)pq.push(node(now.l,mid-1));
		if(mid != now.r)pq.push(node(mid+1,now.r));
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
