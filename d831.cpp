#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,m;
vector<int> v;
int findroot(int a){
	while(a != v[a]){
		v[a] = v[v[a]];
		a = v[a];
	}
	return a;
}
void solve(){
	v = vector<int>(n+1);
	for(int i = 1;i<=n;i++)v[i] = i;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[findroot(a)] = findroot(b);
	}
	vector<int> sz(n+1);
	for(int i = 0;i<=n;i++){
		sz[findroot(i)]++;
	}
	int ans = 0;
	for(auto i:sz)ans = max(ans,i);
	cout<<ans<<'\n';
}
int main(){
	io
	while(cin>>n>>m){
		if(n == -1)return 0;
		solve();
	}
}

