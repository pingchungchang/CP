#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
int ans = 0;
int cc = 0;

struct DSU{
	int dsu[mxn],sz[mxn];
	DSU(){
	}
	void init(int n){
		for(int i = 0;i<=n;i++){
			dsu[i] = i,sz[i] = 1;
		}
		return;
	}
	int root(int k){
		return k == dsu[k]?k:dsu[k] = root(dsu[k]);
	}
	void onion(int a,int b){
		a = root(a),b = root(b);
		if(a == b)return;
		cc--;
		if(sz[a]<sz[b])swap(a,b);
		dsu[b] = a;
		sz[a] += sz[b];
		ans = max(ans,sz[a]);
	}
};

DSU dsu;
int N,M;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	ans = 1;
	cc = N;
	dsu.init(N);
	while(M--){
		int a,b;
		cin>>a>>b;
		dsu.onion(a,b);
		cout<<cc<<' '<<ans<<'\n';
	}
	return 0;
}
