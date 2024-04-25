#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mxn = 1e6+10;
vector<int> childs[mxn];
int sz[mxn];
int n;

void get_sz(int now,int par){
	sz[now] = 1;
	for(auto nxt:childs[now]){
		if(nxt == par)continue;
		get_sz(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}
int get_centroid(int now,int par,int tar){
	for(auto nxt:childs[now]){
		if(nxt == par)continue;
		if(sz[nxt]>tar)return get_centroid(nxt,now,tar);
	}
	return now;
}
int main(){
	cin>>n;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		childs[a].push_back(b);
		childs[b].push_back(a);
	}
	get_sz(0,0);
	int cen = get_centroid(0,0,(sz[0]+1)/2);
	get_sz(cen,cen);
	int small = 0;
	for(auto nxt:childs[cen]){
		small = max(small,sz[nxt]);
	}
	cout<<small;
	return 0;
}

