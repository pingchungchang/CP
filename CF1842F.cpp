#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 5050;
vector<int> v[mxn],tree[mxn];
queue<int> q;
int dep[mxn];
int n;
ll ans[mxn];
int tans = 0;

inline void getans(int rt){
	for(auto &i:v)i.clear();
	tans = 0;
	memset(dep,-1,sizeof(dep));
	dep[rt] = 0;
	q.push(rt);
	while(!q.empty()){
		auto now = q.front();
		v[dep[now]].push_back(now);
		q.pop();
		for(auto nxt:tree[now]){
			if(dep[nxt] == -1){
				dep[nxt] = dep[now]+1;
				q.push(nxt);
			}
		}
	}
	int r = 0,c = 0;
	for(int i = 1;i<=n;i++){
		if(c == v[r].size()){
			r++,c = 0;
		}
		tans = tans+(i-1)-r*2+i-1;
		//if(i == n&&ans[i] == 12)cout<<rt<<":"<<tans<<endl;
		ans[i] = max(ans[i],tans+1ll*(n-i)*i);
		c++;
	}
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		getans(i);
	}
	for(int i  = 0;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
