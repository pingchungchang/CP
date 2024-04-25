#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


map<vector<int>,int> mp;
queue<vector<int>> q;
map<vector<int>,pii> pre;

void calc(int N){
	vector<int> v;
	for(int i = 1;i<=N;i++)v.push_back(i);
	q.push(v);
	mp[v] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int s = 0;s<N;s++){
			for(int e = s+1;e<N;e++){
				auto tmp = now;
				swap(tmp[s],tmp[e]);
				swap(tmp[N-1-s],tmp[N-1-e]);
				if(mp.find(tmp) != mp.end())continue;
				pre[tmp] = {s,e};
				mp[tmp] = mp[now]+1;
				q.push(tmp);
			}
		}
	}
	return;
}

void prec(){
	mp[vector<int>(1,1)] = 0;
	for(int i = 2;i<=12;i+=2){
		calc(i);
		cerr<<i<<":"<<mp.size()<<endl;
	}
	int mx = 0;
	for(auto &i:mp){
		mx = max(mx,i.sc);
		if(i.fs.size()==6){
			for(auto &j:i.fs)cerr<<j<<',';cerr<<endl;
		}
	}
	cerr<<"MX:"<<mx<<endl;
}
void solve(){
	int N;
	cin>>N;
	vector<int> v;
	for(int i = 1;i<=N;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	if(mp.find(v) == mp.end()){
		cout<<"-1\n";
		return;
	}
	cout<<mp[v]<<' '<<mp[v]<<'\n';
	vector<pii> ans;
	while(mp[v] != 0){
		auto [a,b] = pre[v];
		swap(v[a],v[b]);
		swap(v[N-1-a],v[N-1-b]);
		ans.push_back({a+1,b+1});
	}
	reverse(ans.begin(),ans.end());
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	prec();
	int t;cin>>t;
	while(t--)solve();
}
