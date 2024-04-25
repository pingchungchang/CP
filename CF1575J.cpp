#include <bits/stdc++.h>
using namespace std;

int v[1002][1002] = {};
int n,m,k;
pair<int,int> dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
int ones[1002];
void solve(){
	pair<int,int> now = make_pair(0,0);
	cin>>now.second;
	now.second--;
	while(now.first != n){
		int k = v[now.first][now.second];
		if(k != 1)ones[now.second]++;
		v[now.first][now.second] = 1;
		now.first += dir[k].first;
		now.second+= dir[k].second;
		if(ones[now.second] == n)now.first = n;
	}
	cout<<now.second+1<<' ';	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>v[i][j];
			v[i][j]--;
			if(v[i][j] == 1)ones[j]++;
		}
	}
	for(int i = 0;i<k;i++){
		solve();
	}
	
}
