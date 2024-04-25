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
int n,m;
vector<int> v;
bitset<13> used;

void dfs(){
	if(v.size() == n){
		for(auto i:v)cout<<i<<' ';
		cout<<'\n';
		return;
	}
	for(int i = (v.empty()?1:v.back());i<=m;i++){
		if(!used[i]){
			used[i] = true;
			v.push_back(i);
			dfs();
			v.pop_back();
			used[i] = false;
		}
	}
	return;
}
int main(){
	io
	cin>>n>>m;
	dfs();
}

