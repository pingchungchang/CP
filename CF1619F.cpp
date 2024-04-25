#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int n,m,k;
vector<pii> v;
priority_queue<pii,vector<pii>,greater<pii>> pq;
vector<vector<int>> ans;

void solve(){
	while(!pq.empty())pq.pop();
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)pq.push({0,i});
	int r1 = n%m,r2 = m-r1;;
	int s1 = (n+m-1)/m,s2 = n/m;
	while(k--){
		v.clear();
		ans.clear();
		for(int i = 0;i<r1;i++){
			ans.push_back({});
			while(ans.back().size()<s1){
				auto tmp = pq.top();
				pq.pop();
				ans.back().push_back(tmp.sc);
				tmp.fs++;
				v.push_back(tmp);
			}
		}
		for(int i = 0;i<r2;i++){
			ans.push_back({});
			while(ans.back().size()<s2){
				auto tmp = pq.top();
				pq.pop();
				ans.back().push_back(tmp.sc);
				v.push_back(tmp);
			}
		}
		assert(pq.empty());
		for(auto &i:v)pq.push(i);
		for(auto &i:ans){
			cout<<i.size()<<' ';for(auto &j:i)cout<<j<<' ';cout<<'\n';
		}
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
