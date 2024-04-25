#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5e5+10;
int n,m;
vector<int> paths[mxn];

void solve(){
	cin>>n>>m;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	int arr[n+1] = {};
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++)cin>>arr[i],pq.push({arr[i],i});
	int pri[n+1] = {};
	vector<int> ans;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		ans.push_back(now.sc);
		vector<int> v;
		for(auto &i:paths[now.sc]){
			if(pri[i])v.push_back(pri[i]);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		int mex = v.size()+1;
		for(int i = 0;i<v.size();i++){
			if(v[i] != i+1){
				mex = i+1;
				break;
			}
		}
		if(mex != now.fs){
			cout<<-1;
			return;
		}
		pri[now.sc] = mex;
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	assert(ans.size() == n);
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
