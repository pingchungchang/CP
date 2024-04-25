#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	ll n,m;
	cin>>n>>m;
	vector<pll> dir;
	for(ll i = 0;i*i<=m;i++){
		ll j = sqrt(m-i*i);
		if(j*j + i*i == m){
			dir.push_back({i,j});
			dir.push_back({-i,j});
			dir.push_back({i,-j});
			dir.push_back({-i,-j});
		}
	}
//	for(auto &i:dir)cout<<i.fs<<' '<<i.sc<<endl;
	ll arr[n][n];
	memset(arr,INT_MAX,sizeof(arr));
	queue<pll> q;
	q.push({0,0});
	for(auto &i:arr)for(auto &j:i)j = INT_MAX;
	arr[0][0] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &i:dir){
			if(i.fs+now.fs>=0&&now.fs+i.fs<n&&i.sc+now.sc>=0&&now.sc+i.sc<n&&arr[now.fs+i.fs][now.sc+i.sc] == INT_MAX){
				arr[now.fs+i.fs][now.sc+i.sc] = arr[now.fs][now.sc]+1;
				q.push({now.fs+i.fs,now.sc+i.sc});
			}
		}
	}
	for(auto &i:arr){
		for(auto &j:i){
			if(j == INT_MAX)cout<<"-1 ";
			else cout<<j<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

