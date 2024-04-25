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


const int mxn = 2e5+10;
const int mxn2 = 5e5+10;
int dsu[mxn];
int sz[mxn];
bitset<mxn2> use;
bitset<mxn> light;
int root(int now){
	while(dsu[now] != now){
		dsu[now] = dsu[dsu[now]];
		now = dsu[now];
	}
	return now;
}
int main(){
	io
	int n,m,e;
	cin>>n>>m>>e;
	for(int i = 1;i<=n+m;i++){
		dsu[i] = i;
		sz[i] = 1;
		if(i>n)light[i] = true;
	}
	vector<pii> lines(e+1);
	for(int i = 1;i<=e;i++)use[i] = true;
	for(int i = 1;i<=e;i++)cin>>lines[i].fs>>lines[i].sc;
	int q;
	cin>>q;
	vector<int> broke(q);
	for(int i = 0;i<q;i++){
		int k;
		cin>>k;
		use[k] = false;
		broke[i] = k;
	}
	vector<int> ans(q);
	ans[0] = m;
	reverse(_all(broke));
	for(int i = 1;i<=e;i++){
		if(use[i]){
			int ra = root(lines[i].fs);
			int rb = root(lines[i].sc);
			if(ra == rb)continue;
			dsu[rb] = ra;
			ans[0] -= sz[ra]*light[ra]+sz[rb]*light[rb];
			if(light[ra]||light[rb]){
				light[ra] = true;
			}
			sz[ra] += sz[rb];
			ans[0] += sz[ra]*light[ra];
		}
	}
	int now = ans[0];
	for(int i= 0;i<broke.size()-1;i++){
		auto tmp = lines[broke[i]];
		int ra = root(tmp.fs);
		int rb = root(tmp.sc);
		if(ra != rb){
			now -= sz[ra]*light[ra]+sz[rb]*light[rb];
			if(light[ra]||light[rb]){
				light[ra] = true;
			}
			dsu[rb] = ra;
			sz[ra] += sz[rb];
			now += sz[ra]*light[ra];
		}
		ans[i+1] = now;
	}
	reverse(_all(ans));
	for(auto i:ans)cout<<i-m<<'\n';	
}

