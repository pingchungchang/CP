#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pll pair<ll,ll>
const int mxn = 2505;
const ll inf = 1e18;
vector<pll> paths[2505];
int pre[mxn];
ll dist[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
	}
	dist[1] = 0;
	for(int i = 0;i<n;i++){
		for(int j = 1;j<=n;j++){
			for(auto nxt:paths[j]){
				if(dist[nxt.fs]>dist[j]+nxt.sc)pre[nxt.fs] = j;
				dist[nxt.fs] = min(dist[nxt.fs],dist[j]+nxt.sc);
			}
		}
	}
	int change = 0;
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			if(dist[nxt.fs]>dist[i]+nxt.sc){
				pre[nxt.fs] = i;
				change = i;
				dist[nxt.fs] = min(dist[nxt.fs],dist[i]+nxt.sc);
			}
		}
	}
	if(!change){
		cout<<"NO\n";
		return 0;
	}
	vector<int> v;
	map<int,int> mp;
	while(mp.find(change) == mp.end()){
		mp[change] = v.size();
		v.push_back(change);
		change = pre[change];
	}
	cout<<"YES\n";
	cout<<change<<' ';
	for(int i = v.size()-1;i>=mp[change];i--)cout<<v[i]<<' ';
	return 0;
}