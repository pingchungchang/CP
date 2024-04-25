#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	bool flag = true;
	for(int i = 1;i<n;i++){
		if(v[i]<v[i-1])flag = false;
	}
	if(flag){
		cout<<"0\n";
		return;
	}
	int ans = 1e9;
	for(int i = 0;i<n;i++){
		auto tmp = v;
		auto tar = tmp;
		tar[i] = x;
		sort(tar.begin(),tar.end());
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		for(int j = 0;j<n;j++){
			if(tmp[j] != tar[j]){
				pq.push(make_pair(tmp[j],j));
			}
		}
		int tx = x;
		flag = true;
		int tans = 0;
		while(!pq.empty()){
			auto now = pq.top();
			pq.pop();
			if(now.fs<tx){
				flag = false;
				break;
			}
			tans++;
			swap(tx,tmp[now.sc]);
		}
		for(int i = 1;i<n;i++)if(tmp[i]<tmp[i-1])flag = false;
		if(!flag)continue;
		ans = min(ans,tans);
	}
	if(ans>n)cout<<"-1\n";
	else cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
