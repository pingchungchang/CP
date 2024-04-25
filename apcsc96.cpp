#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<int> dsu;
int root(int a){
	while(dsu[a] != a){
		dsu[a] = dsu[dsu[a]];
		a = dsu[a];
	}
	return a;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	dsu = vector<int> (n+1,0);
	vector<int> sz(n+1,1);
	for(int i = 1;i<=n;i++)dsu[i] = i;
	while(m--){
		int t;
		cin>>t;
		if(t == 1){
			int a,b;
			cin>>a>>b;
			int ra = root(a),rb = root(b);
			if(sz[ra]>sz[rb]){
				dsu[rb] = ra;
				if(ra != rb)sz[ra] += sz[rb];
			}
			else{
				dsu[ra] = rb;
				if(ra != rb)sz[rb] += sz[ra];
			}
		}
		else if(t == 2){
			int a,b;
			cin>>a>>b;
			if(root(a) == root(b))cout<<"Yes\n";
			else cout<<"No\n";
		}
		else{
			int x;
			cin>>x;
			cout<<sz[root(x)]<<'\n';
		}
	}
	return 0;
}

