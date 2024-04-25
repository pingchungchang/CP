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
const int mxn = 1e5+10;
int dsu[mxn];

int root(int now){
	while(dsu[now] != now){
		dsu[now] = dsu[dsu[now]];
		now = dsu[now];
	}
	return now;
}
void onion(int a,int b){
	int ra = root(a),rb = root(b);
	if(ra != rb)dsu[ra] = rb;
	return;
}
int main(){
	io
	ll n,m;
	cin>>n>>m;
	ll p[n+1];
	for(int i = 1;i<=n;i++)cin>>p[i];
	for(int i = 0;i<mxn;i++)dsu[i] = i;
	while(m--){
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(root(i) == root(p[i]))ans++;
	}
	cout<<ans;
}

