#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
string s;
int n;
int arr[mxn],deg[mxn],state[mxn];
queue<int> q;
bitset<mxn> vis;
vector<int> ansv;

void solve(){
	ansv.clear();
	for(int i = 1;i<=n;i++)vis[i] = false,deg[i] = 0,state[i] = 0,arr[i] = 0;
	cin>>n>>s;
	for(int i = 1;i<=n;i++)cin>>arr[i],deg[arr[i]]++;
	s = "#"+s;
	for(int i = 1;i<=n;i++)state[i] = s[i]-'0';
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	int ans = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(state[now]){
			state[now] = 0;
			state[arr[now]]^=1;
			ans++;
			ansv.push_back(now);
		}
		deg[arr[now]]--;
		if(!deg[arr[now]])q.push(arr[now]);
	}
	assert(ansv.size() == ans);
	for(int i = 1;i<=n;i++){
		if(vis[i]||!deg[i])continue;
		int now = i;
		vector<int> v;
		do{
			vis[now] = true;
			v.push_back(now);
			now = arr[now];
		}while(!vis[now]);
		int tag = 0;
		int cnt = 0,tans = 1e6;
		vector<int> v1,v2;
		for(int i = 1;i<v.size();i++){
			if(state[v[i]]^tag)cnt++,tag = 1,v1.push_back(v[i]);
			else tag = 0;
		}
		if(!(state[v[0]]^tag))tans = min(tans,cnt);
		tag = 1;
		cnt = 1;
		v2.push_back(v[0]);
		/*
		for(auto &j:v1)cout<<j<<',';cout<<endl;
		for(auto &j:v2)cout<<j<<',';cout<<endl;

	   */
		for(int i = 1;i<v.size();i++){
			if(state[v[i]]^tag)cnt++,tag = 1,v2.push_back(v[i]);
			else tag = 0;
		}
		if((state[v[0]]^tag))tans = min(tans,cnt);
		ans += tans;
		if(tans == v1.size())for(auto &j:v1)ansv.push_back(j);
		else for(auto &j:v2)ansv.push_back(j);
	}
	if(ans != ansv.size())cout<<-1<<'\n';
	else{
		assert(ans == ansv.size());
		cout<<ans<<'\n';
		for(auto &i:ansv)cout<<i<<' ';cout<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
