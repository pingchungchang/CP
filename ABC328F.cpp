#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n,q;
vector<int> ans;
bitset<mxn> vis;
vector<int> v[mxn];
int dsu[mxn],sz[mxn];
ll arr[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

inline bool onion(int a,int b,ll dif){
	int ra = root(a),rb = root(b);
	if(ra == rb&&arr[a]-arr[b]!=dif){
		return false;
	}
	if(ra == rb)return true;
	dif = arr[a]-dif-arr[b];
	if(v[ra].size()<v[rb].size()){
		swap(ra,rb);
		swap(a,b);
		dif = -dif;
	}
	while(!v[rb].empty()){
		arr[v[rb].back()] += dif;
		v[ra].push_back(v[rb].back());
		v[rb].pop_back();
	}
	if(sz[ra]<sz[rb]){
		swap(ra,rb);
		swap(a,b);
	}
	dsu[rb] = ra;
	sz[ra] += sz[rb];
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1,v[i].push_back(i);
	for(int i = 1;i<=q;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(onion(a,b,c))ans.push_back(i);
	}
	for(auto &i:ans)cout<<i<<' ';
}
