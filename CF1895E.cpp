#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e6+10;
int state[mxn];
pii arr[mxn],brr[mxn];
vector<pii> va,vb;
bitset<mxn> vis;
int n,m;
vector<int> paths[mxn];
int deg[mxn];

void solve(){
	va.clear(),vb.clear();
	for(int i = 0;i<=n+m+n+m;i++)vis[i] = 0,state[i] = 0,deg[i] = 0,paths[i].clear();
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i].fs;
	for(int i = 0;i<n;i++)cin>>arr[i].sc;
	cin>>m;
	for(int i = 0;i<m;i++)cin>>brr[i].fs;
	for(int i = 0;i<m;i++)cin>>brr[i].sc;
	sort(arr,arr+n);
	sort(brr,brr+m);
	for(int i = 0;i<n;i++){
		while(!va.empty()&&arr[va.back().sc].sc<=arr[i].sc)va.pop_back();
		va.push_back(make_pair(arr[i].fs,i));
	}
	for(int i = 0;i<m;i++){
		while(!vb.empty()&&brr[vb.back().sc].sc<= brr[i].sc)vb.pop_back();
		vb.push_back(make_pair(brr[i].fs,i));
	}

	for(int i = 0;i<n;i++){
		auto it = lower_bound(vb.begin(),vb.end(),make_pair(arr[i].sc+1,-1ll));
		if(it==vb.end())continue;
		deg[i]++;
		paths[it->sc+n].push_back(i);
	}
	for(int i = 0;i<m;i++){
		auto it = lower_bound(va.begin(),va.end(),make_pair(brr[i].sc+1,-1ll));
		if(it == va.end())continue;
		deg[i+n]++;
		paths[it->sc].push_back(i+n);
	}
	/*
	cout<<endl;
	for(auto &i:va)cout<<i.fs<<' '<<arr[i.sc].sc<<',';cout<<endl;
	for(auto &i:vb)cout<<i.fs<<' '<<brr[i.sc].sc<<',';cout<<endl;
	cout<<endl;
	for(int i = 0;i<n+m;i++){
		cout<<i<<":";for(auto &j:paths[i])cout<<j<<',';cout<<endl;
	}
   */

	queue<int> q;
	for(int i = 0;i<n+m;i++){
		state[i] = (i<n?1:2);
		if(!deg[i]){
			q.push(i);
		}
	}
	//for(int i = 0;i<n+m;i++)cout<<state[i]<<' ';cout<<endl;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			state[nxt] = state[now];
			if(!deg[nxt]){
				q.push(nxt);
			}
		}
	}

	int ans[3] = {};
	for(int i = 0;i<n;i++){
		assert(deg[i]>=0);
		if(deg[i])ans[1]++;
		else if(state[i] == 1)ans[0]++;
		else ans[2]++;
	}
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
