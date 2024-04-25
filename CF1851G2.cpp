#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn],arr[mxn];
int n,m,q;
vector<int> paths[mxn];

int root(int k){
	return dsu[k] == k?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

void solve(){
	cin>>n>>m;
	for(int i = 0;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
		paths[i].clear();
	}
	for(int i = 1;i<=n;i++)cin>>arr[i];
	vector<tuple<int,int,int,int>> op;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		op.push_back(make_tuple(max(arr[a],arr[b]),0,a,b));
	}
	cin>>q;
	int ans[q] = {};
	for(int i = 0;i<q;i++){
		int a,b,e;
		cin>>a>>b>>e;
		op.push_back({arr[a]+e,a,b,i});
	}
	sort(op.begin(),op.end());
	for(auto &i:op){
		if(!get<1>(i)){
			onion(get<2>(i),get<3>(i));
		}
		else{
			if(root(get<1>(i)) == root(get<2>(i)))ans[get<3>(i)] = true;
		}
	}
	for(auto &i:ans)if(i)cout<<"YES\n";else cout<<"NO\n";
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
