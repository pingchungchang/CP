#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 1e14;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	ll arr[n],brr[m];
	ll sum = 0;
	vector<ll> all[m];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i,sum += i;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			int k;
			cin>>k;
			k--;
			all[i].push_back(k);
		}
	}

	auto g = mf_graph<ll>(600);
	for(int i = 0;i<n;i++){
		g.add_edge(0,i+1,inf);
		for(int j = 1;j<5;j++){
			g.add_edge(i+j*n+1,i+(j-1)*n+1,inf);
		}
	}
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			g.add_edge(i+400,j+1+all[i][j]*n,inf);
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 1;j<5;j++){
			g.add_edge(i+1+j*n,500,arr[i]);
		}
	}
	for(int i = 0;i<m;i++)g.add_edge(0,400+i,brr[i]);
	auto ans = g.flow(0,500);
	cout<<sum-ans;
}
