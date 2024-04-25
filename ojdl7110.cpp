#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>


const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];
vector<pii> ask[mxn];
int ans[mxn];
tiii edges[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

void onion(int a,int b,int w){
	 a= root(a),b = root(b);
	 if(a == b)return;
	 if(ask[b].size()>ask[a].size()){
		 swap(a,b);
	 }
	 while(!ask[b].empty()){
		 auto tmp = ask[b].back();
		 ask[b].pop_back();
		 if(root(tmp.fs) == a){
			 if(!ans[tmp.sc])ans[tmp.sc] = w;
		 }
		 else ask[a].push_back(tmp);
	 }

	 if(sz[a]<sz[b]){
		 ask[a].swap(ask[b]);
		 swap(a,b);
	 }
	 dsu[b] = a;
	 sz[a] += sz[b];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n-1;i++){
		cin>>get<1>(edges[i])>>get<2>(edges[i])>>get<0>(edges[i]);
	}
	sort(edges,edges+n-1);
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		ask[a].push_back({b,i});
		ask[b].push_back({a,i});
	}
	for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1;
	for(int i = 0;i<n-1;i++){
		onion(get<1>(edges[i]),get<2>(edges[i]),get<0>(edges[i]));
	}
	for(int i = 0;i<q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
