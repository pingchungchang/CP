#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

//ans = 2^(m-n+cc)

const int mxn = 2e5+10;
const int mod = 1e9+7;

inline int pw(int a,int b){
	int re = 1;
	while(b){
		if(b&1)re = 1ll*re*a%mod;
		b>>=1;
		a = 1ll*a*a%mod;
	}
	return re;
}

int dsu[mxn],sz[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b){
		return;
	}
	if(sz[a]<sz[b])swap(a,b);
	sz[a] += sz[b];
	dsu[b] = a;
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)dsu[i] =i,sz[i] = 1;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	int C = m-n;
	for(int i = 1;i<=n;i++){
		if(dsu[i] == i)C++;
	}
	cout<<pw(2,C);
}
