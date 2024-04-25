#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<ll>> v(n,vector<ll>(m,0));
	priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>v[i][j];
			pq.push(make_tuple(v[i][j],i,j));
		}
	}
	vector<vector<int>> paths(m,vector<int>(n,-1));
	for(int i = 0;i<m;i++){
		auto now = pq.top();
		pq.pop();
		paths[i][get<1>(now)] = get<0>(now);
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		for(auto &i:paths){
			if(i[get<1>(now)] == -1){
				i[get<1>(now)] = get<0>(now);
				break;
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++)cout<<paths[j][i]<<' ';
		cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

