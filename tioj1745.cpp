#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	ll x,y;
	ll l,r;
	node(ll lll,ll rrr,ll pl,ll pr){
		x = lll;
		y = rrr;
		l = pl;
		r = pr;
	}
};
ll interx(node a,node b){
	if(a.x == b.x)return 0LL;
	return (b.y-a.y+a.x-b.x-1)/(a.x-b.x);
}
int main(){
	ll n;
	cin>>n;
	ll a,b,c;
	cin>>a>>b>>c;
	vector<ll> dp(n+1,0LL);
	deque<node> dq;
	vector<ll> p(n+1,0LL);
	vector<ll> v(n+1,0);
	for(ll i = 1;i<=n;i++){
		cin>>v[i];
		p[i] = p[i-1]+v[i];
	}
	dq.push_back(node(0,0,0,LONG_LONG_MAX));
	
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&dq.front().r<=p[i])dq.pop_front();
		dp[i] = a*p[i]*p[i]+b*p[i]+c+dq.front().x*p[i]+dq.front().y;
		node tmp(-2LL*p[i]*a,-b*p[i]+dp[i]+a*p[i]*p[i],0,LONG_LONG_MAX);
		while(!dq.empty()&&interx(tmp,dq.back())<=dq.back().l)dq.pop_back();
		if(dq.empty())dq.push_back(tmp);
		else{
			dq.back().r = interx(dq.back(),tmp);
			tmp.l = interx(dq.back(),tmp);
			dq.push_back(tmp);
		}
//		for(auto i:dq)cout<<i.x<<' '<<i.y<<' '<<i.l<<' '<<i.r<<',';cout<<endl;
	}
	cout<<dp[n];
//	for(int i = 1;i<=n;i++)cout<<dp[i]<<" ";
}

